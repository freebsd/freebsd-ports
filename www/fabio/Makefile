# $FreeBSD$

PORTNAME=	fabio
PORTVERSION=	1.5.9
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	stl@ossuary.net
COMMENT=	Zero-conf load balancing HTTP(S) router managed by Consul

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	fabiolb
GH_SUBDIR=	src/github.com/fabiolb/fabio

GO_BUILDFLAGS=	-ldflags "-X main.GitDescribe=v${PORTVERSION}"
GO_TARGET=	:${PREFIX}/sbin/fabio

USE_RC_SUBR=	fabio

post-install:
	${INSTALL_DATA} ${GO_WRKSRC}/fabio.properties ${STAGEDIR}${PREFIX}/etc/fabio.properties.sample

.include <bsd.port.mk>
