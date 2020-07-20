# $FreeBSD$

PORTNAME=	cocoalib
DISTVERSION=	0.99710
CATEGORIES=	math
MASTER_SITES=	http://cocoa.dima.unige.it/cocoalib/tgz/
DISTNAME=	CoCoALib-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for doing Computations in Commutative Algebra

LICENSE=			GPLv3+ GFDL PD
LICENSE_COMB=			multi
LICENSE_FILE_GPLv3+ =		${WRKSRC}/COPYING-GPLv3
LICENSE_FILE_GFDL=		${WRKSRC}/doc/COPYING

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libgmp.so:math/gmp

USES=		compiler:c++11-lang shebangfix tar:tgz

SHEBANG_GLOB=	*.sh

CXXFLAGS+=	-I${WRKSRC}/include \
		-I${WRKSRC}/src/AlgebraicCore/TmpFactorDir \
		-I${WRKSRC}/src/AlgebraicCore/TmpFactorDir/multivariate \
		-I${WRKSRC}/src/AlgebraicCore/TmpFactorDir/linalg \
		-I${LOCALBASE}/include \
		-DCoCoA_ULONG2LONG=1
LDFLAGS+=	-L${LOCALBASE}/lib -L${BUILD_WRKSRC} -lcocoa -lgmp

BUILD_WRKSRC=	${WRKSRC}/src/AlgebraicCore

TEST_TARGET=	all
TEST_WRKSRC=	${WRKSRC}/src/tests

PREPROCESSOR_DEFNS=	${WRKSRC}/include/CoCoA/PREPROCESSOR_DEFNS.H

OPTIONS_DEFINE=		BOOST DOCS EXAMPLES FROBBY GFAN \
			GSL NORMALIZ SMALLDEG TEST

FROBBY_DESC=		Link with libfrobby.a
GFAN_DESC=		Link with libgfan.a
GSL_DESC=		Link with libgsl.a
NORMALIZ_DESC=		Link with libnormaliz.a (might cause circular dependency)
SMALLDEG_DESC=		Optimization for small degree polynomials

BOOST_BUILD_DEPENDS=	${LOCALBASE}/include/boost/thread.hpp:devel/boost-libs
BOOST_CXXFLAGS=		-pthread
FROBBY_BUILD_DEPENDS=	${LOCALBASE}/lib/libfrobby.a:math/frobby
GFAN_BUILD_DEPENDS=	${LOCALBASE}/lib/libgfan.a:math/gfanlib
GSL_BUILD_DEPENDS=	${LOCALBASE}/lib/libgsl.a:math/gsl
NORMALIZ_BUILD_DEPENDS=	${LOCALBASE}/lib/libnormaliz.a:math/libnormaliz
SMALLDEG_EXTRA_PATCHES=	${FILESDIR}/extra-patch-include-CoCoA_config.H

post-patch:
	${REINPLACE_CMD} "s,%%DISTVERSION%%,${DISTVERSION},g" ${BUILD_WRKSRC}/Makefile

do-configure-BOOST-on:
	${ECHO_CMD} "#define COCOA_WITH_BOOST" >> ${PREPROCESSOR_DEFNS}

do-configure-BOOST-off:
	${ECHO_CMD} "#undef COCOA_WITH_BOOST" >> ${PREPROCESSOR_DEFNS}

do-configure-FROBBY-on:
	${ECHO_CMD} "#define COCOA_WITH_FROBBY" >> ${PREPROCESSOR_DEFNS}

do-configure-FROBBY-off:
	${ECHO_CMD} "#undef COCOA_WITH_FROBBY" >> ${PREPROCESSOR_DEFNS}

do-configure-GFAN-on:
	${ECHO_CMD} "#define COCOA_WITH_GFAN" >> ${PREPROCESSOR_DEFNS}

do-configure-GFAN-off:
	${ECHO_CMD} "#undef COCOA_WITH_GFAN" >> ${PREPROCESSOR_DEFNS}

do-configure-GSL-on:
	${ECHO_CMD} "#define COCOA_WITH_GSL" >> ${PREPROCESSOR_DEFNS}

do-configure-GSL-off:
	${ECHO_CMD} "#undef COCOA_WITH_GSL" >> ${PREPROCESSOR_DEFNS}

do-configure-NORMALIZ-on:
	${ECHO_CMD} "#define COCOA_WITH_NORMALIZ" >> ${PREPROCESSOR_DEFNS}

do-configure-NORMALIZ-off:
	${ECHO_CMD} "#undef COCOA_WITH_NORMALIZ" >> ${PREPROCESSOR_DEFNS}

pre-build:
	cd ${WRKSRC}/include/CoCoA && ./MakeUnifiedHeader.sh --check

post-build-TEST-on: do-test

do-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/libcocoa.a ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${PREFIX}/include/CoCoA
	cd ${WRKSRC}/include/CoCoA && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/CoCoA '-name *\.H -a ! -name \._*'

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_MAN} ${WRKSRC}/doc/CoCoALib.pdf ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/html '! -name \._*'

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/index.html ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} '-name ex-*\.C'

.include <bsd.port.mk>
