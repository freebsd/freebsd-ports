PORTNAME=	frobby
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.5
PORTREVISION=	3
CATEGORIES=	math

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	5b9e4ac4057f5693f53c321eeb5bfb387f6b69fb.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Software system and project for computations with monomial ideals
WWW=		https://github.com/Macaulay2/frobby

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		gmake localbase:ldflags shebangfix
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	Macaulay2

USE_LDCONFIG=	yes

SHEBANG_FILES=	test/latticeFormats/runtest* test/runSplitTests test/runTests \
		test/testScripts/*

MAKE_ENV=	RANLIB=${RANLIB}

ALL_TARGET=	# Empty

OPTIONS_DEFINE=		DOCS LIBDOCS STATIC TEST
OPTIONS_DEFAULT=	STATIC
OPTIONS_SUB=		yes
LIBDOCS_DESC=		Build and install documentation for frobby library
DOCS_BUILD_DEPENDS=	dvips:print/tex-dvipsk \
			latex:print/tex-formats
LIBDOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dvips:print/tex-dvipsk \
			epstopdf:print/texlive-base \
			latex:print/tex-formats
TEST_BUILD_DEPENDS=	bash:shells/bash

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTATIC}
PLIST_SUB+=	LIBRARY="" \
		NO_LIBRARY="@comment "
.else
PLIST_SUB+=	LIBRARY="@comment " \
		NO_LIBRARY=""
.endif

# The following variables should be defined to the same values
# that can be found in ${WRKSRC}/Makefile
FROBBY_SOVERSION=	1
FROBBY_AGE=		0
FROBBY_REVISION=	0
FROBBY_VERSION=		${FROBBY_SOVERSION}.${FROBBY_AGE}.${FROBBY_REVISION}

do-build-DOCS-on:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} doc

do-build-LIBDOCS-on:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} develDoc

do-build-STATIC-on:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} library

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} MODE=shared library

post-build-TEST-on:
	cd ${WRKSRC} && test/runTests _full
	cd ${WRKSRC} && test/runSplitTests _full

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/release/frobby ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/frobby.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/bin/libfrobby.so.${FROBBY_VERSION} ${STAGEDIR}${PREFIX}/lib/libfrobby.so.${FROBBY_VERSION}
	cd ${STAGEDIR}${PREFIX}/lib && \
		${RLN} libfrobby.so.${FROBBY_VERSION} ${STAGEDIR}${PREFIX}/lib/libfrobby.so && \
		${RLN} libfrobby.so.${FROBBY_VERSION} ${STAGEDIR}${PREFIX}/lib/libfrobby.so.${FROBBY_SOVERSION}

do-install-STATIC-on:
	${INSTALL_DATA} ${WRKSRC}/src/frobby.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/bin/libfrobby.a ${STAGEDIR}${PREFIX}/lib

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/bin/manual.ps ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/bin/manual.pdf ${STAGEDIR}${DOCSDIR}

do-install-LIBDOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/bin/develDoc/develDoc.ps ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/bin/develDoc/develDoc.pdf ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/bin/develDoc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
