PORTNAME=	clrng
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-beta
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for uniform random number generation in OpenCL
WWW=		https://github.com/clMathLibraries/clRNG

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		amd64 i386 powerpc powerpc64 powerpc64le powerpcspe
ONLY_FOR_ARCHS_REASON=	this code has only been tested on x86 and powerpc platforms

BUILD_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	opencl>=0:devel/opencl

USE_GITHUB=	yes
GH_ACCOUNT=	clMathLibraries
GH_PROJECT=	clRNG

USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DBUILD_CLIENT=OFF \
		-DBUILD_TEST=OFF \
		-DSUFFIX_LIB="" \
		-DSUFFIX_BIN=""

CMAKE_SOURCE_PATH=	${WRKSRC}/src

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
CFLAGS+= -Wno-expansion-to-defined
.endif

.include <bsd.port.post.mk>
