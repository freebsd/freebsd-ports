PORTNAME=	frobby
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.7
CATEGORIES=	math

MAINTAINER=	jishanalam9128@gmail.com
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
DOCS_USES=		tex
DOCS_USE=		TEX=dvipsk:build,latex:build
LIBDOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
LIBDOCS_USES=		tex
LIBDOCS_USE=		TEX=base:build,dvipsk:build,latex:build
TEST_BUILD_DEPENDS=	bash:shells/bash

# The following variables should be defined to the same values
# that can be found in ${WRKSRC}/Makefile
FROBBY_SOVERSION=	1
FROBBY_AGE=		0
FROBBY_REVISION=	2
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
	${INSTALL_LIB} ${WRKSRC}/bin/libfrobby.so.${FROBBY_VERSION} ${STAGEDIR}${PREFIX}/lib
	${RLN} ${STAGEDIR}${PREFIX}/lib/libfrobby.so.${FROBBY_VERSION} \
		${STAGEDIR}${PREFIX}/lib/libfrobby.so
	${RLN} ${STAGEDIR}${PREFIX}/lib/libfrobby.so.${FROBBY_VERSION} \
		${STAGEDIR}${PREFIX}/lib/libfrobby.so.${FROBBY_SOVERSION}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/bin/manual.ps \
		${WRKSRC}/bin/manual.pdf ${STAGEDIR}${DOCSDIR}

do-install-LIBDOCS-on:
	(cd ${WRKSRC}/bin/develDoc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/bin/develDoc/develDoc.ps \
		${WRKSRC}/bin/develDoc/develDoc.pdf ${STAGEDIR}${DOCSDIR}

do-install-STATIC-on:
	${INSTALL_DATA} ${WRKSRC}/bin/libfrobby.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
