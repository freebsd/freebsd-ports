# $FreeBSD$

PORTNAME=	seal
DISTVERSION=	3.4.5
CATEGORIES=	security

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	4d57e56649d2dd1b8333457e301661121b05c827.patch:-p1 # PR https://github.com/microsoft/SEAL/pull/111

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Microsoft Simple Encrypted Arithmetic Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	Microsoft
GH_PROJECT=	SEAL
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DSEAL_LIB_BUILD_TYPE="Shared"

CMAKE_SOURCE_PATH=	${WRKSRC}/native/src

PLIST_SUB+=	FILE_VER=${DISTVERSION:R}

.include <bsd.port.mk>
