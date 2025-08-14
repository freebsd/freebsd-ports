PORTNAME=	tailscale
PORTVERSION=	1.86.4
DISTVERSIONPREFIX=	v
CATEGORIES=	security net-vpn

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Mesh VPN that makes it easy to connect your devices
WWW=		https://tailscale.com/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss

USES=		go:1.24,modules

GO_MODULE=	github.com/tailscale/tailscale

USE_RC_SUBR=	tailscaled

GO_TARGET=	./cmd/tailscale \
		./cmd/tailscaled
GO_BUILDFLAGS=	-tags xversion -ldflags "\
		-X tailscale.com/version.longStamp=${PORTVERSION} \
		-X tailscale.com/version.shortStamp=${PORTVERSION}"

PLIST_FILES=	bin/tailscale  \
		bin/tailscaled

.include <bsd.port.mk>
