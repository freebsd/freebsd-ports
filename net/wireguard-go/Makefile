PORTNAME=	wireguard-go
PORTVERSION=	0.0.20250522
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net net-vpn
MASTER_SITES=	https://git.zx2c4.com/wireguard-go/snapshot/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	WireGuard implementation in Go
WWW=		https://www.wireguard.com

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules tar:xz
GO_MODULE=	golang.zx2c4.com/wireguard
GO_MOD_DIST=	LOCAL/decke/wireguard-go/${PORTVERSION}/

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
