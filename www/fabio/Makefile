PORTNAME=	fabio
PORTVERSION=	1.6.0
PORTREVISION=	15
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	stl@ossuary.net
COMMENT=	Zero-conf load balancing HTTP(S) router managed by Consul
WWW=		https://github.com/fabiolb/fabio

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.6.0:sys

USE_RC_SUBR=	fabio

GO_MODULE=	github.com/fabiolb/fabio
GO_TARGET=	:${PREFIX}/sbin/fabio
GO_BUILDFLAGS=	-ldflags "-X main.GitDescribe=v${PORTVERSION}"

PLIST_FILES=	"@sample etc/fabio.properties.sample" \
		sbin/fabio

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

post-install:
	${INSTALL_DATA} ${GO_WRKSRC}/fabio.properties ${STAGEDIR}${PREFIX}/etc/fabio.properties.sample

.include <bsd.port.mk>
