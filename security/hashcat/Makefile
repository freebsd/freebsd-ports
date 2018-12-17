# $FreeBSD$

PORTNAME=	hashcat
PORTVERSION=	5.1.0
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	security

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Advanced CPU-based password recovery utility

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.txt

NOT_FOR_ARCHS=		powerpc powerpc64 sparc64
NOT_FOR_ARCHS_REASON=	fails to compile: compiling for big-endian architecture not supported

BUILD_DEPENDS=	gsed:textproc/gsed

USES=		gmake iconv localbase shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup:opencl Cyan4973:xxhash
GH_PROJECT=	OpenCL-Headers:opencl xxHash:xxhash
GH_TAGNAME=	d516924:opencl 0f2dd4a:xxhash
GH_SUBDIR=	deps/git/OpenCL-Headers:opencl deps/git/xxHash:xxhash

SHEBANG_FILES=	extra/tab_completion/install

ALL_TARGET=	default
PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS BRAIN
BRAIN_DESC=	Build Hashcat Brain

OPTIONS_DEFAULT=BRAIN
BRAIN_CFLAGS=	-DWITH_BRAIN -Ideps/git/xxHash
BRAIN_MAKE_ARGS_OFF=ENABLE_BRAIN=0

MAKE_ARGS+=	SHARED=1 \
		CC="${CC}" \
		LFLAGS_NATIVE="${LDFLAGS} -lpthread -lm" \
		CFLAGS_NATIVE="${CFLAGS} -Iinclude -IOpenCL -Ideps/LZMA-SDK/C -Ideps/git/OpenCL-Headers"

pre-install:
	${STRIP_CMD} ${WRKSRC}/libhashcat.so.${PORTVERSION}
	${STRIP_CMD} ${WRKSRC}/hashcat

.include <bsd.port.mk>
