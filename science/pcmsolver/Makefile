PORTNAME=	pcmsolver
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	API for the Polarizable Continuum Model
WWW=		https://github.com/PCMSolver/pcmsolver

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++14-lang fortran python:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	PCMSolver

BINARY_ALIAS=	git=true # see https://github.com/PCMSolver/pcmsolver/issues/198

do-configure: # full CMAKE_ARGS breaks configure: -DCMAKE_EXE_LINKER_FLAGS="${LDFLAGS}" causes configure to fail to find fortran's libraries
	@${MKDIR} ${CONFIGURE_WRKSRC}
	@cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} \
			-DCMAKE_BUILD_TYPE:STRING="Release" \
			-DCMAKE_C_FLAGS_RELEASE:STRING="${CFLAGS}" \
			-DCMAKE_CXX_FLAGS_RELEASE:STRING="${CXXFLAGS}" \
			-DCMAKE_C_COMPILER:STRING="${CC}" \
			-DCMAKE_CXX_COMPILER:STRING="${CXX}" \
			-DPYTHON_INTERPRETER:STRING="${PYTHON_CMD}" \
			${CMAKE_SOURCE_PATH}

.include <bsd.port.mk>
