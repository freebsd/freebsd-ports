# $FreeBSD$

PORTNAME=		frobby
DISTVERSIONPREFIX=	v
DISTVERSION=		0.9.0
CATEGORIES=		math
MASTER_SITES=		http://www.broune.com/frobby/
DISTNAME=		${PORTNAME}_${DISTVERSIONPREFIX}${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Software system and project for computations with monomial ideals

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		gmake shebangfix

BINARY_ALIAS=	make=gmake
USE_LDCONFIG=	yes

SHEBANG_FILES=	test/testScripts/* \
		test/latticeFormats/runtest*

OPTIONS_DEFINE=		EXEDOCS LIBDOCS TEST
OPTIONS_DEFAULT=	STATIC SHARED
OPTIONS_MULTI=		INSTALL
OPTIONS_MULTI_INSTALL=	EXECUTABLE \
			SHARED \
			STATIC
EXEDOCS_DESC=		Build and install documentation for frobby executable
LIBDOCS_DESC=		Build and install documentation for frobby library
EXECUTABLE_DESC=	Build and install frobby executable
SHARED_DESC=		Build and install libfrobby.so
STATIC_DESC=		Build and install libfrobby.a
EXEDOCS_BUILD_DEPENDS=	latex:print/tex-formats \
			dvips:print/tex-dvipsk
LIBDOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			epstopdf:print/texlive-base
TEST_BUILD_DEPENDS=	bash:shells/bash
OPTIONS_SUB=		yes

MAKE_ARGS+=	GMP_INC_DIR=${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSHARED} || ${PORT_OPTIONS:MSTATIC}
PLIST_SUB+=	LIBRARY="" NO_LIBRARY="@comment "
.else
PLIST_SUB+=	LIBRARY="@comment " NO_LIBRARY=""
.endif

do-build:

do-build-EXEDOCS-on:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} doc

do-build-EXECUTABLE-on:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS}

do-build-LIBDOCS-on:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} develDoc

do-build-STATIC-on:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} library

post-build-SHARED-on:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} MODE=shared library

post-build-TEST-on: do-build-EXECUTABLE-on
	cd ${WRKSRC} && test/runTests _full
	cd ${WRKSRC} && test/runSplitTests _full

do-install:

do-install-EXECUTABLE-on:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/release/frobby ${STAGEDIR}${PREFIX}/bin

do-install-SHARED-on:
	${INSTALL_DATA} ${WRKSRC}/src/frobby.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/bin/libfrobby.so ${STAGEDIR}${PREFIX}/lib

do-install-STATIC-on:
	${INSTALL_DATA} ${WRKSRC}/src/frobby.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/bin/libfrobby.a ${STAGEDIR}${PREFIX}/lib

do-install-EXEDOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/bin/manual.ps ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/bin/manual.pdf ${STAGEDIR}${DOCSDIR}

do-install-LIBDOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/bin/develDoc/develDoc.ps ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/bin/develDoc/develDoc.pdf ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/bin/develDoc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
