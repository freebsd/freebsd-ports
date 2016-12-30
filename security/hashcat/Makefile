# Created by: Nikolai Lifanov <lifanov@mail.lifanov.com>
# $FreeBSD$

PORTNAME=	hashcat
PORTVERSION=	3.20
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Advanced CPU-based password recovery utility

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.txt

BUILD_DEPENDS=	${LOCALBASE}/include/CL/cl.h:devel/opencl \
		gsed:textproc/gsed

BROKEN_FreeBSD_9=	does not build

USE_GITHUB=	yes

ALL_TARGET=	native
USES=		gmake localbase shebangfix
SHEBANG_FILES=	extra/tab_completion/install
USE_CSTD=	c99

MAKE_ARGS=	CC="${CC}" \
		CFLAGS_NATIVE="${CFLAGS} -Iinclude/ -IOpenCL/" \
		LFLAGS_NATIVE="${LDFLAGS} -lpthread"

pre-install:
	${STRIP_CMD} ${WRKSRC}/hashcat

.include <bsd.port.mk>
