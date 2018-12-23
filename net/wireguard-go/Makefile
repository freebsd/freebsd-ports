# $FreeBSD$

PORTNAME=	wireguard-go
PORTVERSION=	0.0.20181222
CATEGORIES=	net
MASTER_SITES=	https://git.zx2c4.com/wireguard-go/snapshot/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	WireGuard implementation in Go

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	go:lang/go

USES=		gmake tar:xz

USE_GITHUB=	nodefault
GH_TUPLE=	golang:crypto:505ab145d0a9:crypto/vendor/golang.org/x/crypto \
		golang:net:610586996380:net/vendor/golang.org/x/net \
		golang:sys:2a47403f2ae5:sys/vendor/golang.org/x/sys

MAKE_ENV+=	GOFLAGS=-mod=vendor

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
