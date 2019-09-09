# $FreeBSD$

PORTNAME=	wireguard-go
PORTVERSION=	0.0.20190908
CATEGORIES=	net net-vpn
MASTER_SITES=	https://git.zx2c4.com/wireguard-go/snapshot/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	WireGuard implementation in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake go:modules,no_targets tar:xz

USE_GITHUB=	nodefault
GH_TUPLE=	golang:crypto:9756ffdc2472:crypto/vendor/golang.org/x/crypto \
		golang:net:ba9fcec4b297:net/vendor/golang.org/x/net \
		golang:sys:19e00faab6ad:sys/vendor/golang.org/x/sys

MAKE_ENV+=	GOFLAGS="${GO_BUILDFLAGS}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
