# $FreeBSD$

PORTNAME=	traefik
PORTVERSION=	1.4.6
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	High availability reverse proxy and load balancer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	containous
GH_SUBDIR=	src/github.com/containous/traefik
GH_TUPLE=	jteeuwen:go-bindata:a0ff256:gobindata/src/github.com/jteeuwen/go-bindata

USE_RC_SUBR=	traefik

USERS=		traefik
GROUPS=		traefik

PLIST_FILES=	bin/traefik \
		"@sample etc/traefik.toml.sample"

do-build:
	@cd ${WRKSRC}/src/github.com/jteeuwen/go-bindata/go-bindata; \
	${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -v -x
	@cd ${WRKSRC}/src/github.com/containous/traefik; \
	${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go generate && \
	${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -v -x ./cmd/traefik

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/containous/traefik/traefik ${STAGEDIR}${PREFIX}/bin/traefik
	${INSTALL_DATA} ${WRKSRC}/src/github.com/containous/traefik/traefik.sample.toml ${STAGEDIR}${PREFIX}/etc/traefik.toml.sample

.include <bsd.port.mk>
