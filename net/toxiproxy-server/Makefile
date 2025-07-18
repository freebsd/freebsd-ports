PORTNAME?=	toxiproxy-server
DISTVERSIONPREFIX=	v
DISTVERSION=	2.12.0
CATEGORIES=	net

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT?=	TCP proxy to simulate network and system conditions (server)
WWW=		https://github.com/shopify/toxiproxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	shopify
GH_PROJECT=	toxiproxy

.if ${PORTNAME} == toxiproxy-server
USE_RC_SUBR=	${PORTNAME}
.endif

GO_MOD_DIST=	github
GO_MODULE=	github.com/shopify/toxiproxy
GO_TARGET?=	./cmd/server:${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
			-X 'github.com/Shopify/toxiproxy/v2.Version=${DISTVERSION}'"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
