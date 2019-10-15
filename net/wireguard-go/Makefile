# $FreeBSD$

PORTNAME=	wireguard-go
PORTVERSION=	0.0.20191012
CATEGORIES=	net net-vpn
MASTER_SITES=	https://git.zx2c4.com/wireguard-go/snapshot/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	WireGuard implementation in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake go:modules,no_targets tar:xz

USE_GITHUB=	nodefault
GH_TUPLE=	golang:crypto:34f69633bfdc:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:d98b1b443823:golang_net/vendor/golang.org/x/net \
		golang:sys:c178f38b412c:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text

MAKE_ENV+=	GOFLAGS="${GO_BUILDFLAGS}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
