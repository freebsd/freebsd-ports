# Created by: Nikolai Lifanov <lifanov@mail.lifanov.com>
# $FreeBSD$

PORTNAME=	hashcat
PORTVERSION=	3.30
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Advanced CPU-based password recovery utility

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.txt

BUILD_DEPENDS=	${LOCALBASE}/include/CL/cl.h:devel/opencl \
		gsed:textproc/gsed

USE_GITHUB=	yes

ALL_TARGET=	default
USES=		gmake localbase shebangfix
SHEBANG_FILES=	extra/tab_completion/install
USE_CSTD=	c99

MAKE_ARGS=	CC="${CC}" \
		CFLAGS_NATIVE="${CFLAGS} -Iinclude/ -IOpenCL/" \
		LFLAGS_NATIVE="${LDFLAGS} -lpthread"

pre-install:
	${STRIP_CMD} ${WRKSRC}/libhashcat.so
	${STRIP_CMD} ${WRKSRC}/hashcat

.include <bsd.port.mk>
