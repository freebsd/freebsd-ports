PORTNAME=	headscale
PORTVERSION=	0.13.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	m.muenz@gmail.com
COMMENT=	Mesh VPN that makes it easy to connect your devices

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss

USES=		go:modules

GO_MODULE=	github.com/juanfont/headscale

GO_TARGET=	./cmd/headscale

PLIST_FILES=	bin/headscale

.include <bsd.port.mk>
