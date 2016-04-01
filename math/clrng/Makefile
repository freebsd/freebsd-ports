# Created by: Johannes Dieterich <dieterich@ogolem.org>
# $FreeBSD$

PORTNAME=	clrng
DISTVERSION=	1.0.0-beta
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	dieterich@ogolem.org
COMMENT=	Library for uniform random number generation in OpenCL

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	opencl>=0:devel/opencl

BROKEN_FreeBSD_9=	clRNG is only supported on FreeBSD 10.1 and newer

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
