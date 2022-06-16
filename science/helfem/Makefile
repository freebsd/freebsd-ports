PORTNAME=	helfem
DISTVERSION=	g20210912
PORTREVISION=	3
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Finite element methods for electronic structure calculations

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libarmadillo.so:math/armadillo \
		libgsl.so:math/gsl \
		libhdf5_cpp.so:science/hdf5 \
		libsz.so:science/libaec \
		libxc.so:science/libxc

USES=		cmake fortran

USE_GITHUB=	yes
GH_ACCOUNT=	susilehtola
GH_PROJECT=	HelFEM
GH_TAGNAME=	21461e9

CMAKE_ON=	HELFEM_FIND_DEPS BUILD_SHARED_LIBS

.include <bsd.port.mk>
