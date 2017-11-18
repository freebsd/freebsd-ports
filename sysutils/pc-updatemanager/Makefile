# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pc-updatemanager
PORTVERSION=	201711181009
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	TrueOS update manager

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${LOCALBASE}/bin/ipfs-go:sysutils/ipfs-go

USES=		pkgconfig tar:xz
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	pc-updatemanager
GH_TAGNAME=	2a82a326efbc6cc3ff00f0cbc25c51ef06a40a91

.include <bsd.port.mk>
