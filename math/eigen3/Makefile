# $FreeBSD$

PORTNAME=	eigen
PORTVERSION=	3.3.9
CATEGORIES=	math
MASTER_SITES=	https://gitlab.com/libeigen/eigen/-/archive/${PORTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Lightweight library for vector and matrix math

LICENSE=	LGPL21 MPL20
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LGPL
LICENSE_FILE_MPL20=	${WRKSRC}/COPYING.MPL2

CMAKE_ARGS=	-DPKGCONFIG_INSTALL_DIR:PATH="libdata/pkgconfig"
USES=		cmake tar:bzip2
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	FULL
OPTIONS_DEFAULT=FULL

FULL_DESC=	Add the support for math dependencies
FULL_CMAKE_ON=	-DBLAS_DIR:PATH="${LOCALBASE}"
FULL_USES=	blaslapack:openblas pkgconfig
FULL_LIB_DEPENDS=	libcholmod.so:math/suitesparse	\
			libsuperlu.so:math/superlu	\
			libadolc.so:math/adol-c		\
			libfftw3.so:math/fftw3		\
			libmpfr.so:math/mpfr		\
			libgmp.so:math/gmp		\
			libboost_thread.so:devel/boost-libs

.include <bsd.port.mk>
