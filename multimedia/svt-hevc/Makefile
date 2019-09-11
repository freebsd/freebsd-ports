# $FreeBSD$

PORTNAME=	svt-hevc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1
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
GH_ACCOUNT=	OpenVisualCloud
GH_PROJECT=	SVT-HEVC
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	NATIVE
CFLAGS+=	-D__STDC_WANT_LIB_EXT1__=0

post-patch:
# Keep using nasm and drop vendor -O/-g
	@${REINPLACE_CMD} -e '/find_program.*yasm/d' \
		-Ee '/set.*(release|debug)_flags_to_test/,/\)/d' \
		${WRKSRC}/CMakeLists.txt
# Avoid conflict with standard types
	@${GREP} -Flr '_T_DEFINED' ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -i .types 's/_T_DEFINED/_DEFINED/'
# Avoid platform whitelists for generic non-Windows code
	@${GREP} --exclude='*/third_party/*' -Flr '__linux' ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -i .opsys -E 's/__linux(__)?/__unix__/'

.include <bsd.port.mk>
