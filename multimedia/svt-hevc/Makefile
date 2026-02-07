PORTNAME=	svt-hevc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Scalable HEVC encoder
WWW=		https://01.org/svt

LICENSE=	BSD2CLAUSE+PATENT
LICENSE_GROUPS=	FSF OSI COPYFREE
LICENSE_NAME=	BSD-2-Clause Plus Patent License
LICENSE_FILE=	${WRKSRC}/LICENSE.md
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	uses x86-64 assembly
DEPRECATED=	Project discontinued

BUILD_DEPENDS=	nasm:devel/nasm

USES=		cmake compiler:c11
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	OpenVisualCloud
GH_PROJECT=	SVT-HEVC
CMAKE_OFF=	NATIVE

OPTIONS_DEFINE=	LTO
OPTIONS_DEFAULT=LTO

LTO_CMAKE_BOOL=		CMAKE_INTERPROCEDURAL_OPTIMIZATION
LTO_CMAKE_ON=		-DCMAKE_POLICY_DEFAULT_CMP0069:STRING=NEW

post-patch:
# Keep using nasm and drop vendor -O/-g
	@${REINPLACE_CMD} -e '/find_program.*yasm/d' \
		-Ee '/set.*(release|debug)_flags_to_test/,/\)/d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
