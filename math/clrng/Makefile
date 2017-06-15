# Created by: Johannes Dieterich <dieterich@ogolem.org>
# $FreeBSD$

PORTNAME=	clrng
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-beta
CATEGORIES=	math

MAINTAINER=	dieterich@ogolem.org
COMMENT=	Library for uniform random number generation in OpenCL

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	opencl>=0:devel/opencl

ONLY_FOR_ARCHS=		amd64 i386 powerpc powerpc64
ONLY_FOR_ARCHS_REASON=	this code has only been tested on x86 and powerpc platforms

USE_GITHUB=	yes
GH_ACCOUNT=	clMathLibraries
GH_PROJECT=	clRNG

USE_LDCONFIG=	yes
USES=		cmake

CMAKE_ARGS+=	-DBUILD_CLIENT=OFF \
		-DBUILD_TEST=OFF \
		-DSUFFIX_LIB="" \
		-DSUFFIX_BIN=""

CMAKE_SOURCE_PATH=	${WRKSRC}/src

.include <bsd.port.mk>
