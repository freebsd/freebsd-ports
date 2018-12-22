# $FreeBSD$

PORTNAME=	pcmsolver
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
PORTREVISION=	4
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	API for the Polarizable Continuum Model

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	fails to compile: SphericalDiffuse.cpp:182: invalid initialization of non-const reference

USES=		cmake:outsource,noninja fortran python
USE_GITHUB=	yes
GH_ACCOUNT=	PCMSolver
USE_LDCONFIG=	yes

do-configure: # full CMAKE_ARGS breaks configure: -DCMAKE_EXE_LINKER_FLAGS="${LDFLAGS}" causes configure to fail to find fortran's libraries
	@${MKDIR} ${CONFIGURE_WRKSRC}
	@cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} \
			-DCMAKE_BUILD_TYPE:STRING="Release" \
			-DCMAKE_C_FLAGS_RELEASE:STRING="${CFLAGS}" \
			-DCMAKE_CXX_FLAGS_RELEASE:STRING="${CXXFLAGS}" \
			-DCMAKE_EXE_LINKER_FLAGS:STRING="${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so" \
			${CMAKE_SOURCE_PATH}

post-patch:
	@${REINPLACE_CMD} -e 's|"-O3 |"$${CMAKE_C_FLAGS} |' \
		${WRKSRC}/cmake/custom/compilers/*.cmake

.include <bsd.port.mk>
