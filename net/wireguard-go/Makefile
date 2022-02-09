PORTNAME=	wireguard-go
PORTVERSION=	0.0.20220117
PORTEPOCH=	1
CATEGORIES=	net net-vpn
MASTER_SITES=	https://git.zx2c4.com/wireguard-go/snapshot/ \
		LOCAL/decke
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}-vendor${EXTRACT_SUFX}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	WireGuard implementation in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake go:modules,no_targets tar:xz

USE_GITHUB=	nodefault

MAKE_ENV+=	${GO_ENV} GOFLAGS="${GO_BUILDFLAGS}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
