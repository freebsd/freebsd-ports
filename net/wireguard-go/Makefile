PORTNAME=	wireguard-go
PORTVERSION=	0.0.20220316
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	net net-vpn
MASTER_SITES=	https://git.zx2c4.com/wireguard-go/snapshot/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	WireGuard implementation in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake go:modules,no_targets tar:xz

USE_GITHUB=	nodefault
GH_TUPLE=	golang:crypto:3147a52a75dd:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:27dd8689420f:golang_net/vendor/golang.org/x/net \
		golang:sys:039c03cc5b86:golang_sys/vendor/golang.org/x/sys

MAKE_ENV+=	${GO_ENV} GOFLAGS="${GO_BUILDFLAGS}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
