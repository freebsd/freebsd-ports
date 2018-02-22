# Created by: Nikolai Lifanov <lifanov@mail.lifanov.com>
# $FreeBSD$

PORTNAME=	hashcat
PORTVERSION=	4.1.0
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	security

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Advanced CPU-based password recovery utility

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.txt

NOT_FOR_ARCHS=		powerpc powerpc64 sparc64
NOT_FOR_ARCHS_REASON=	fails to compile: compiling for big-endian architecture not supported

BUILD_DEPENDS=	${LOCALBASE}/include/CL/cl.h:devel/opencl \
		gsed:textproc/gsed

ALL_TARGET=	default
USES=		gmake iconv localbase shebangfix
SHEBANG_FILES=	extra/tab_completion/install

USE_GITHUB=	yes
USE_CSTD=	gnu99

PLIST_SUB=	PORTVERSION=${PORTVERSION}

MAKE_ARGS=	SHARED=1 \
		CC="${CC}" \
		LFLAGS_NATIVE="${LDFLAGS} -lpthread" \
		CFLAGS_NATIVE="${CFLAGS} -Iinclude -IOpenCL -Iinclude/lzma_sdk"

pre-install:
	${STRIP_CMD} ${WRKSRC}/libhashcat.so.${PORTVERSION}
	${STRIP_CMD} ${WRKSRC}/hashcat

.include <bsd.port.mk>
