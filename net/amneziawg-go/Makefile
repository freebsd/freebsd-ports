PORTNAME=	amneziawg-go
DISTVERSION=	3.1.20260828
CATEGORIES=	net net-vpn

MAINTAINER=	vova@zote.me
COMMENT=	Amnezia in Go with VPN non-detection extensions
WWW=		https://www.amnezia.org/ \
		https://github.com/amnezia-vpn/amneziawg-go/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake go:modules

GO_MODULE=	github.com/amnezia-vpn/amneziawg-go/v3@v${DISTVERSION}

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's|^const Version = .*|const Version = "${DISTVERSION}"|' \
		${WRKSRC}/version.go

.include <bsd.port.mk>
