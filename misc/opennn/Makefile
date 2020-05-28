# $FreeBSD$

PORTNAME=	opennn
DISTVERSION=	4.0
CATEGORIES=	misc # machine-learning
MASTER_SITES=	SF/${PORTNAME}/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open neural networks library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler dos2unix zip
DOS2UNIX_FILES=	opennn/CMakeLists.txt
USE_LDCONFIG=	yes

CMAKE_OFF=	OpenNN_BUILD_EXAMPLES OpenNN_BUILD_TESTS

OPTIONS_DEFINE=		MPI OPENMP
OPTIONS_DEFAULT=	OPENMP

MPI_CMAKE_BOOL=		__OPENNN_MPI__
MPI_BROKEN=		https://github.com/Artelnics/OpenNN/issues/86

OPENMP_CMAKE_BOOL=	__OPENNN_OMP__

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
USE_GCC=	yes
.else
# workaround for breakage with clang-10: https://github.com/Artelnics/OpenNN/issues/105
LLVM_VER=	80
BUILD_DEPENDS+=	clang${LLVM_VER}:devel/llvm${LLVM_VER}
CPP=		clang-cpp${LLVM_VER}
CC=		clang${LLVM_VER}
CXX=		clang++${LLVM_VER}
# clang-8 defaults to elfv1 on FreeBSD, to be removed after moving to 9 or newer
.if ${ARCH} == powerpc64
CFLAGS+=	-mabi=elfv2
.endif
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME} && ${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${BUILD_WRKSRC}/${PORTNAME}/libopennn.so ${STAGEDIR}${PREFIX}/lib
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libopennn.so

.include <bsd.port.post.mk>
