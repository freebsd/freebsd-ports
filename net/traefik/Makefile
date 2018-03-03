# $FreeBSD$

PORTNAME=	traefik
PORTVERSION=	1.5.3
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	High availability reverse proxy and load balancer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	go-bindata:devel/go-bindata

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	containous
GH_SUBDIR=	src/github.com/containous/traefik

USE_RC_SUBR=	traefik

USERS=		traefik
GROUPS=		traefik

PLIST_FILES=	bin/traefik \
		"@sample etc/traefik.toml.sample"

TRAEFIK_BUILD_ENV=	${MAKE_ENV} \
			CGO_ENABLED=0

TRAEFIK_LDARGS=	-ldflags "-s -w \
		-X github.com/containous/traefik/version.Version=${DISTVERSION} \
		-X github.com/containous/traefik/version.BuildDate=`date -u '+%Y-%m-%d_%I:%M:%S%p'`"

do-build:
	@cd ${WRKSRC}/src/github.com/containous/traefik; \
	${SETENV} ${BUILD_ENV} ${TRAEFIK_BUILD_ENV} GOPATH=${WRKSRC} go generate && \
	${SETENV} ${BUILD_ENV} ${TRAEFIK_BUILD_ENV} GOPATH=${WRKSRC} go build ${TRAEFIK_LDARGS} -v -x ./cmd/traefik

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/containous/traefik/traefik ${STAGEDIR}${PREFIX}/bin/traefik
	${INSTALL_DATA} ${WRKSRC}/src/github.com/containous/traefik/traefik.sample.toml ${STAGEDIR}${PREFIX}/etc/traefik.toml.sample

.include <bsd.port.mk>
