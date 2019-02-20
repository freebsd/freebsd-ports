# $FreeBSD$

PORTNAME=	svt-hevc
DISTVERSIONPREFIX=	v
PORTVERSION=	1.3.0
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Scalable HEVC encoder

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
GH_ACCOUNT=	Intel
GH_PROJECT=	SVT-HEVC

post-patch:
# Default CFLAGS are already set by USES=cmake
	@${REINPLACE_CMD} -i .flags -E -e 's/ -march=native//' \
		-e 's/-O2 -flto //' \
		-e '/C_FLAGS_(RELEASE|DEBUG)/d' \
		-e '/NASM_FLAGS_DEBUG/d' \
		${WRKSRC}/CMakeLists.txt
# Avoid devel/yasm dependency
	@${REINPLACE_CMD} -i .typo 's/MAKE_ASM_NASM_COMPILER/s&/' \
		${WRKSRC}/CMakeLists.txt
# Avoid lang/gcc* dependency
	@${REINPLACE_CMD} -i .gcc -e 's/gcc-//' \
		-e '/CMAKE_C/{ s/STREQUAL/MATCHES/; s/"GNU/&|Clang/; }' \
		${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/Source/Lib/*/CMakeLists.txt
# Avoid conflict with standard types
	@${GREP} -Flr '_T_DEFINED' ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -i .types 's/_T_DEFINED/_DEFINED/'
# Avoid platform whitelists for generic non-Windows code
	@${REINPLACE_CMD} -i .opsys 's/Linux/${OPSYS}/' \
		${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/Source/Lib/*/CMakeLists.txt
	@${GREP} -Flr '__linux' ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -i .opsys -E 's/__linux(__)?/__${OPSYS}__/'

.include <bsd.port.mk>
