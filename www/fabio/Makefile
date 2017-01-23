# $FreeBSD$

PORTNAME=	fabio
PORTVERSION=	1.3.7
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	stl@ossuary.net
COMMENT=	Zero-conf load balancing HTTP(S) router managed by Consul

LICENSE=	MIT

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	eBay
GH_PROJECT=	fabio
GH_SUBDIR=	src/github.com/eBay/fabio

USE_RC_SUBR=	fabio

do-build:
	@cd ${WRKSRC}/src/github.com/eBay/fabio; \
	${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -v -x \
		-ldflags "-X main.GitDescribe=v${PORTVERSION}" -o bin/fabio

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/eBay/fabio/bin/fabio \
		${STAGEDIR}${PREFIX}/sbin/fabio
	${INSTALL_DATA} ${WRKSRC}/src/github.com/eBay/fabio/fabio.properties \
		${STAGEDIR}${PREFIX}/etc/fabio.properties.sample

.include <bsd.port.mk>
