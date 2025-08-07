PORTNAME=	fabio
PORTVERSION=	1.6.4
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	www

MAINTAINER=	stl@ossuary.net
COMMENT=	Zero-conf load balancing HTTP(S) router managed by Consul
WWW=		https://github.com/fabiolb/fabio

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules

USE_RC_SUBR=	fabio

GO_MODULE=	github.com/fabiolb/fabio
GO_TARGET=	:${PREFIX}/sbin/fabio
GO_BUILDFLAGS=	-ldflags "-X main.GitDescribe=v${PORTVERSION}"

PLIST_FILES=	"@sample etc/fabio.properties.sample" \
		sbin/fabio

post-install:
	${INSTALL_DATA} ${GO_WRKSRC}/fabio.properties ${STAGEDIR}${PREFIX}/etc/fabio.properties.sample

.include <bsd.port.mk>
