# Created by: Nikolai Lifanov <lifanov@mail.lifanov.com>
# $FreeBSD$

PORTNAME=	hashcat
PORTVERSION=	3.6.0
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	security

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Advanced CPU-based password recovery utility

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.txt

BUILD_DEPENDS=	${LOCALBASE}/include/CL/cl.h:devel/opencl \
		gsed:textproc/gsed

USE_GITHUB=	yes

ALL_TARGET=	default
USES=		gmake iconv localbase shebangfix
SHEBANG_FILES=	extra/tab_completion/install
USE_CSTD=	c99

MAKE_ARGS=	SHARED=1 \
		CC="${CC}" \
		LFLAGS_NATIVE="${LDFLAGS} -lpthread" \
		CFLAGS_NATIVE="${CFLAGS} -Iinclude -IOpenCL -Iinclude/lzma_sdk"

pre-install:
	${STRIP_CMD} ${WRKSRC}/libhashcat.so
	${STRIP_CMD} ${WRKSRC}/hashcat

.include <bsd.port.mk>
