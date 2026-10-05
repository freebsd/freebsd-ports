PORTNAME=	rayfish
DISTVERSIONPREFIX=v
DISTVERSION=	0.5.3
CATEGORIES=	net

MAINTAINER=	feld@FreeBSD.org
COMMENT=	P2P mesh VPN powered by Iroh
WWW=		https://rayfish.xyz

LICENSE=	MPL20

NOT_FOR_ARCHS=	armv6 armv7 i386 powerpc powerpcspe
NOT_FOR_ARCHS_REASON=	route_manager crate ships bindings pregenerated for LP64 targets

USES=		cargo

GROUPS=	rayfish

USE_GITHUB=	yes
GH_ACCOUNT=	rayfish

USE_RC_SUBR=	rayfish

PLIST_FILES=	bin/ray

.include <bsd.port.mk>
