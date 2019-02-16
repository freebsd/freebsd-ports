# $FreeBSD$

PORTNAME=	svt-av1
PORTVERSION=	s20180215
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Scalable AV1 encoder

LICENSE=	BSD2CLAUSE+PATENT
LICENSE_GROUPS=	FSF OSI COPYFREE
LICENSE_NAME=	BSD-2-Clause Plus Patent License
LICENSE_FILE=	${WRKSRC}/LICENSE.md
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	requires AVX support and uses x86-64 assembly

BUILD_DEPENDS=	nasm:devel/nasm

USES=		cmake
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	OpenVisualCloud
GH_PROJECT=	SVT-AV1
GH_TAGNAME=	37a5b96

post-patch:
# Avoid platform whitelists for generic non-Windows code
	@${REINPLACE_CMD} 's/Linux/${OPSYS}/' ${WRKSRC}/CMakeLists.txt
	@${GREP} -Flr '__linux__' ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -i .opsys 's/__linux__/__${OPSYS}__/'

.include <bsd.port.mk>
