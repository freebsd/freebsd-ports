# $FreeBSD$

PORTNAME=	svt-av1
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0-151
DISTVERSIONSUFFIX=	-gcd79924e
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
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	NATIVE

post-patch:
# Keep using nasm and drop vendor -O/-g
	@${REINPLACE_CMD} -e '/find_program.*yasm/d' \
		-Ee '/set.*(release|debug)_flags_to_test/,/\)/d' \
		${WRKSRC}/CMakeLists.txt
# Avoid platform whitelists for generic non-Windows code
# https://github.com/OpenVisualCloud/SVT-AV1/pull/162
	@${GREP} --exclude='*/third_party/*' -Flr '__linux' ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -i .opsys -E 's/__linux(__)?/__unix__/'

.include <bsd.port.mk>
