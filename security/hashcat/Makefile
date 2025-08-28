PORTNAME=	hashcat
PORTVERSION=	6.2.6
DISTVERSIONPREFIX=	v
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	security

MAINTAINER=	se@FreeBSD.org
COMMENT=	Advanced CPU-based password recovery utility
WWW=		https://hashcat.net/hashcat/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.txt

NOT_FOR_ARCHS=	powerpc powerpc64 powerpcspe
NOT_FOR_ARCHS_REASON=	fails to compile: compiling for big-endian architecture not supported

BUILD_DEPENDS=	minizip:archivers/minizip

USES=		compiler:c11 gmake iconv localbase python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup:opencl Cyan4973:xxhash
GH_PROJECT=	OpenCL-Headers:opencl xxHash:xxhash
GH_SUBDIR=	deps/git/OpenCL-Headers:opencl deps/git/xxHash:xxhash
GH_TAGNAME=	1d3dc4e:opencl c0e86bc:xxhash
PYTHON_NO_DEPENDS=	yes

SHEBANG_FILES=	extra/tab_completion/install tools/*.py

MAKE_ARGS+=	SHARED=1 \
		CC="${CC}" \
		LFLAGS_NATIVE="${LDFLAGS} -lpthread -lm" \
		CFLAGS_NATIVE="${CFLAGS} -Iinclude -IOpenCL -Ideps/LZMA-SDK/C \
						-Ideps/git/OpenCL-Headers"
ALL_TARGET=	default
CFLAGS_aarch64+=	-march=armv8-a+crc+crypto

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=		BRAIN DOCS
OPTIONS_DEFAULT=	BRAIN
BRAIN_DESC=		Build Hashcat Brain
BRAIN_MAKE_ARGS_OFF=	ENABLE_BRAIN=0
BRAIN_CFLAGS=		-DWITH_BRAIN -Ideps/git/xxHash

pre-install:
	${STRIP_CMD} ${WRKSRC}/libhashcat.so.${PORTVERSION}
	${STRIP_CMD} ${WRKSRC}/modules/*.so
	${STRIP_CMD} ${WRKSRC}/hashcat

.include <bsd.port.mk>
