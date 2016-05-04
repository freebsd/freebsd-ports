# Created by: Johannes Dieterich <dieterich@ogolem.org>
# $FreeBSD$

PORTNAME=	clfft
PORTVERSION=	2.12.0
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	dieterich@ogolem.org
COMMENT=	Software library containing FFT functions written in OpenCL

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	opencl>=0:devel/opencl

BROKEN_FreeBSD_9=	clFFT is only supported on FreeBSD 10.1 and newer
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON_amd64=	only builds and is supported on amd64

USE_GITHUB=	yes
GH_ACCOUNT=	clMathLibraries
GH_PROJECT=	clFFT

USE_LDCONFIG=	yes
USES=		cmake

CMAKE_ARGS+=	-DBUILD_CLIENT=OFF \
		-DBUILD_TEST=OFF \
		-DBUILD_CALLBACK_CLIENT=OFF \
		-DSUFFIX_LIB=""

CMAKE_SOURCE_PATH=	${WRKSRC}/src

.include <bsd.port.mk>
