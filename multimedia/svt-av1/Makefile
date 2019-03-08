# $FreeBSD$

PORTNAME=	svt-av1
PORTVERSION=	s20180307
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Scalable AV1 encoder

LICENSE=	BSD2CLAUSE+PATENT
LICENSE_GROUPS=	FSF OSI COPYFREE
LICENSE_NAME=	BSD-2-Clause Plus Patent License
LICENSE_FILE=	${WRKSRC}/LICENSE.md
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	uses x86-64 assembly

BUILD_DEPENDS=	nasm:devel/nasm

USES=		cmake compiler:c11
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	OpenVisualCloud
GH_PROJECT=	SVT-AV1
GH_TAGNAME=	a30e1f6
CMAKE_OFF=	BUILD_TESTING # no useful tests yet

post-patch:
# Default CFLAGS are already set by USES=cmake
	@${REINPLACE_CMD} -i .flags -E -e 's/ -mavx//' \
		-e 's/CMAKE_C_FLAGS "/&$${CMAKE_C_FLAGS} /' \
		-e '/C_FLAGS_(RELEASE|DEBUG)/d' \
		-e '/NASM_FLAGS_DEBUG/d' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -i .flags -e 's/-march=core-avx2/-mavx2/' \
		${WRKSRC}/Source/Lib/ASM_AVX2/CMakeLists.txt \
# Avoid lang/gcc* dependency
	@${REINPLACE_CMD} -i .gcc -e 's/gcc-//' \
		-e '/CMAKE_C/{ s/STREQUAL/MATCHES/; s/"GNU/&|Clang/; }' \
		${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/Source/Lib/*/CMakeLists.txt
# Avoid platform whitelists for generic non-Windows code
	@${REINPLACE_CMD} -i .opsys 's/Linux/${OPSYS}/' \
		${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/Source/Lib/*/CMakeLists.txt
	@${GREP} --exclude='*/third_party/*' -Flr '__linux' ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -i .opsys -E 's/__linux(__)?/__${OPSYS}__/'
# Avoid -msse4.1 for (unused) function not under Source/Lib/ASM_SSE4_1/
	@${REINPLACE_CMD} -e '/_sse4_1/,/}/d; /smmintrin\.h/d' \
		${WRKSRC}/Source/Lib/Codec/EbInterPrediction.c

.include <bsd.port.mk>
