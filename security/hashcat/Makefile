# Created by: Nikolai Lifanov <lifanov@mail.lifanov.com>
# $FreeBSD$

PORTNAME=	hashcat
PORTVERSION=	3.20
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Advanced CPU-based password recovery utility

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.txt

BUILD_DEPENDS=	${LOCALBASE}/include/CL/cl.h:devel/opencl \
		${LOCALBASE}/bin/gsed:textproc/gsed

BROKEN_FreeBSD_9=	does not build

USE_GITHUB=	yes

ALL_TARGET=	native
USES=		gmake localbase
USE_CSTD=	c99

pre-install:
	${STRIP_CMD} ${WRKSRC}/hashcat

.include <bsd.port.mk>
