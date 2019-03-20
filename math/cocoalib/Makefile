# $FreeBSD$

PORTNAME=	cocoalib
DISTVERSION=	0.99600
CATEGORIES=	math
MASTER_SITES=	http://cocoa.dima.unige.it/cocoalib/tgz/
DISTNAME=	CoCoALib-0.99600

MAINTAINER=	phascolarctos@protonmail.ch
COMMENT=	C++ library for doing Computations in Commutative Algebra

LICENSE=			GPLv3+ GFDL PD
LICENSE_COMB=			multi
LICENSE_FILE_GPL3+ =		${WRKSRC}/COPYING-GPLv3
LICENSE_FILE_GFDL=		${WRKSRC}/doc/COPYING

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libgmp.so:math/gmp

USES=		shebangfix tar:tgz

SHEBANG_GLOB=	*.sh

CXXFLAGS+=	-I${WRKSRC}/include \
		-I${WRKSRC}/src/AlgebraicCore/TmpFactorDir \
		-I${WRKSRC}/src/AlgebraicCore/TmpFactorDir/multivariate \
		-I${WRKSRC}/src/AlgebraicCore/TmpFactorDir/linalg \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${BUILD_WRKSRC} -lcocoa -lgmp

BUILD_WRKSRC=	${WRKSRC}/src/AlgebraicCore

TEST_TARGET=	all
TEST_WRKSRC=	${WRKSRC}/src/tests

OPTIONS_DEFINE=		DOCS EXAMPLES FROBBY GFAN \
			GSL NORMALIZ SMALLDEG TEST
FROBBY_DESC=		Link with libfrobby.a
GFAN_DESC=		Link with libgfan.a
GSL_DESC=		Link with libgsl.a
NORMALIZ_DESC=		Link with libnormaliz.a (might cause circular dependency)
SMALLDEG_DESC=		Optimization for small degree polynomials
BOOST_BUILD_DEPENDS=	${LOCALBASE}/include/boost/thread.hpp:devel/boost-libs
FROBBY_BUILD_DEPENDS=	${LOCALBASE}/lib/libfrobby.a:math/frobby
FROBBY_CXXFLAGS=	-DCoCoA_WITH_FROBBY
FROBBY_LDFLAGS=		-lfrobby
GFAN_BUILD_DEPENDS=	${LOCALBASE}/lib/libgfan.a:math/gfanlib
GFAN_CXXFLAGS=		-DCoCoA_WITH_GFAN
GFAN_LDFLAGS=		-lgfan
GSL_BUILD_DEPENDS=	${LOCALBASE}/lib/libgsl.a:math/gsl
GSL_CXXFLAGS=		-DCoCoA_WITH_GSL
GSL_LDFLAGS=		-lgsl -lgslcblas
NORMALIZ_BUILD_DEPENDS=	${LOCALBASE}/lib/libnormaliz.a:math/libnormaliz
NORMALIZ_CXXFLAGS=	-DCoCoA_WITH_NORMALIZ
NORMALIZ_LDFLAGS=	-lnormaliz

post-patch:
	${CP} ${FILESDIR}/Makefile.AlgebraicCore ${BUILD_WRKSRC}/Makefile

post-patch-SMALLDEG-on:
	${REINPLACE_CMD} 's,int SmallExponent_t,short SmallExponent_t,' ${WRKSRC}/include/CoCoA/config.H

post-patch-TEST-on:
	${CP} ${FILESDIR}/Makefile.tests ${TEST_WRKSRC}/Makefile

pre-build:
	cd ${WRKSRC}/include/CoCoA && ./MakeUnifiedHeader.sh --check

post-build-TEST-on: do-test

do-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/libcocoa.a ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${PREFIX}/include/CoCoA
	cd ${WRKSRC}/include/CoCoA && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/CoCoA '-name *\.H'

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_MAN} ${WRKSRC}/doc/CoCoALib.pdf ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/html

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/index.html ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} '-name ex-*\.C'

.include <bsd.port.mk>
