PORTNAME=	wireguard-go
PORTVERSION=	0.0.20230223
PORTREVISION=	16
PORTEPOCH=	1
CATEGORIES=	net net-vpn
MASTER_SITES=	https://git.zx2c4.com/wireguard-go/snapshot/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	WireGuard implementation in Go
WWW=		https://www.wireguard.com

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake go:modules,no_targets tar:xz

USE_GITHUB=	nodefault
GH_TUPLE=	\
		golang:crypto:3147a52a75dd:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.8.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		google:btree:v1.0.1:google_btree/vendor/github.com/google/btree \
		google:gvisor:703fd9b7fbc0:google_gvisor/vendor/gvisor.dev/gvisor

MAKE_ENV+=	${GO_ENV} GOFLAGS="${GO_BUILDFLAGS}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
