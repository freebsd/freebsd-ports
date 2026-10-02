PORTNAME=	rayfish
DISTVERSIONPREFIX=v
DISTVERSION=	0.5.3
CATEGORIES=	net

MAINTAINER=	feld@FreeBSD.org
COMMENT=	P2P mesh VPN powered by Iroh
WWW=		https://rayfish.xyz

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	route_manager crate only supports target x86_64-unknown-freebsd

LICENSE=	MPL20

USES=		cargo

GROUPS=	rayfish

USE_GITHUB=	yes
GH_ACCOUNT=	rayfish

USE_RC_SUBR=	rayfish

PLIST_FILES=	bin/ray

.include <bsd.port.mk>
