# $FreeBSD$

PORTNAME=	tailscale
PORTVERSION=	1.4.5
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Mesh VPN that makes it easy to connect your devices

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/tailscale/tailscale

USE_RC_SUBR=	tailscaled

GO_TARGET=	./cmd/tailscale \
		./cmd/tailscaled
GO_BUILDFLAGS=	-tags xversion -ldflags "\
		-X tailscale.com/version.Long=${PORTVERSION} \
		-X tailscale.com/version.Short=${PORTVERSION}"

PLIST_FILES=	bin/tailscale  \
		bin/tailscaled

.include <bsd.port.mk>
