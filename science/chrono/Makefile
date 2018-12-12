# $FreeBSD$

PORTNAME=	chrono
DISTVERSION=	2.0.0-9070
DISTVERSIONSUFFIX=	-g57a828dc0
PORTREVISION=	2
CATEGORIES=	science devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for multi-physics simulation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTSCOUT=	skipv:3.0.0 # their development continues under the branch 2.X. 3.0.0 should be ignored until they release a higher version

BUILD_DEPENDS=	openmpi>0:net/openmpi

USES=		cmake:outsource compiler:c++14-lang fortran
USE_GITHUB=	yes
GH_ACCOUNT=	project${PORTNAME}
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		HDF5 DEMOS TESTS
OPTIONS_SUB=		yes

HDF5_CMAKE_BOOL=	ENABLE_HDF5
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5

DEMOS_DESC=		Build and install demo programs
DEMOS_CMAKE_BOOL=	BUILD_DEMOS

TESTS_DESC=		Build and install unit test programs
TESTS_CMAKE_BOOL=	BUILD_TESTING

post-extract:
	@${RM} ${WRKSRC}/data/opensim/Rajagopal2015.orig

post-patch:
	@${FIND} ${WRKSRC} -name CMakeLists.txt -o -name "*.cmake*" | ${XARGS} ${REINPLACE_CMD} -i '' 's|lib64|lib|'

.include <bsd.port.mk>
