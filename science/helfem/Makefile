PORTNAME=	helfem
DISTVERSION=	g20210912
PORTREVISION=	3
CATEGORIES=	science # chemistry

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	4c0196c3ef3f254a22030eda787105c8a48df919.patch:-p1 # https://github.com/susilehtola/HelFEM/pull/7

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
