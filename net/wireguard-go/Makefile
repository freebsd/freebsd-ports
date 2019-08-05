# $FreeBSD$

PORTNAME=	wireguard-go
PORTVERSION=	0.0.20190805
CATEGORIES=	net
MASTER_SITES=	https://git.zx2c4.com/wireguard-go/snapshot/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	WireGuard implementation in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake go:modules,no_targets tar:xz

USE_GITHUB=	nodefault
GH_TUPLE=	golang:crypto:57b3e21c3d56:crypto/vendor/golang.org/x/crypto \
		golang:net:d28f0bde5980:net/vendor/golang.org/x/net \
		golang:sys:516e3c20635f:sys/vendor/golang.org/x/sys

MAKE_ENV+=	GOFLAGS="${GO_BUILDFLAGS}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
