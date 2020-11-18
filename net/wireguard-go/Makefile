# $FreeBSD$

PORTNAME=	wireguard-go
PORTVERSION=	0.0.20201118
CATEGORIES=	net net-vpn
MASTER_SITES=	https://git.zx2c4.com/wireguard-go/snapshot/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	WireGuard implementation in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake go:modules,no_targets tar:xz

USE_GITHUB=	nodefault
GH_TUPLE=	golang:crypto:c1f2f97bffc9:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:69a78807bb2b:golang_net/vendor/golang.org/x/net \
		golang:sys:ba5294a509c7:golang_sys/vendor/golang.org/x/sys

MAKE_ENV+=	GOFLAGS="${GO_BUILDFLAGS}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
