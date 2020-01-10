# $FreeBSD$

PORTNAME=	vipster
DISTVERSIONPREFIX=	v
DISTVERSION=	1.18b-75
DISTVERSIONSUFFIX=	-gfa5853f
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Crystalline and molecular structure visualisation program

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler
USE_GITHUB=	yes
GH_ACCOUNT=	sgsaenger
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DESKTOP PYTHON
OPTIONS_DEFAULT=	DESKTOP
OPTIONS_SUB=		yes

DESKTOP_DESC=		Build QT-based desktop app
DESKTOP_CMAKE_BOOL=	DESKTOP
DESKTOP_USES=		qt:5
DESKTOP_USE=		QT=core,gui,widgets,buildtools_build,qmake_build

PYTHON_CMAKE_BOOL=	PYTHON
PYTHON_BROKEN=		Bundles pybind11: https://github.com/sgsaenger/vipster/issues/23

# use clang from ports because older clang (clang-6) lacks the c++17 feature std::mmap::extract

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
LLVM_VER=	${LLVM_DEFAULT}
BUILD_DEPENDS+=	clang${LLVM_VER}:devel/llvm${LLVM_VER}
CPP=		clang-cpp${LLVM_VER}
CC=		clang${LLVM_VER}
CXX=		clang++${LLVM_VER}
.else
USE_GCC=	yes
.endif

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DTESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.post.mk>
