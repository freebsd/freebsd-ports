# Created by: Johannes Dieterich <dieterich@ogolem.org>
# $FreeBSD$

PORTNAME=	clrng
DISTVERSION=	1.0.0-beta
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	dieterich@ogolem.org
COMMENT=	Software library containing BLAS functions written in OpenCL

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	opencl>=0:${PORTSDIR}/devel/opencl
LIB_DEPENDS=	libOpenCL.so:${PORTSDIR}/devel/ocl-icd
RUN_DEPENDS=	opencl>=0:${PORTSDIR}/devel/opencl

ONLY_FOR_ARCHS=	amd64

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
