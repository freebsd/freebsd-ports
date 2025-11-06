PORTNAME=	helfem
DISTVERSION=	g20251026
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Finite element methods for electronic structure calculations
WWW=		https://github.com/susilehtola/HelFEM

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libarmadillo.so:math/armadillo \
		libgsl.so:math/gsl \
		libhdf5_cpp.so:science/hdf5 \
		libsz.so:science/libaec \
		libxc.so:science/libxc

USES=		cmake fortran
USE_CXXSTD=	c++14

USE_GITHUB=	yes
GH_ACCOUNT=	susilehtola
GH_PROJECT=	HelFEM
GH_TAGNAME=	ca3fa54

CMAKE_ON=	HELFEM_FIND_DEPS BUILD_SHARED_LIBS

.include <bsd.port.mk>
