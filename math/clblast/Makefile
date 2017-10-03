# Created by: Johannes M Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clblast
PORTVERSION=	1.1.0
CATEGORIES=	math

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Modern, lightweight, performant and tunable OpenCL BLAS library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	opencl>=0:devel/opencl

USE_GITHUB=	yes
GH_ACCOUNT=	CNugteren
GH_PROJECT=	CLBlast

USE_LDCONFIG=	yes
USES=		cmake

.include <bsd.port.mk>
