PORTNAME=	amneziawg-go
DISTVERSION=	0.2.16
CATEGORIES=	net net-vpn
MASTER_SITES=	https://github.com/amnezia-vpn/amneziawg-go/

MAINTAINER=	vova@zote.me
COMMENT=	Amnezia in Go with VPN non-detection extensions
WWW=		https://www.amnezia.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	gmake go:modules

GO_MODULE=	github.com/amnezia-vpn/amneziawg-go@v${DISTVERSION}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
