# $FreeBSD$

PORTNAME=	fabio
PORTVERSION=	1.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	stl@ossuary.net
COMMENT=	Zero-conf load balancing HTTP(S) router managed by Consul

LICENSE=	MIT

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	eBay:DEFAULT
GH_PROJECT=	fabio

USE_RC_SUBR=	fabio

USERS=		nobody
GROUPS=		nobody

do-build:
	@${MKDIR} ${WRKSRC}/src/github.com/eBay/fabio

.for src in .gitignore .travis.yml CHANGELOG.md Dockerfile LICENSE Makefile \
	README.md Vagrantfile admin build cert config demo exit fabio.png \
	fabio.properties listen.go listen_test.go main.go metrics proxy \
	registry route routes.txt vendor
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/eBay/fabio
.endfor

	@cd ${WRKSRC}/src/github.com/eBay/fabio; \
	${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -v -x \
		-ldflags "-X main.GitDescribe=v${PORTVERSION}" -o bin/fabio

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/eBay/fabio/bin/fabio \
		${STAGEDIR}${PREFIX}/sbin/fabio
	${INSTALL_DATA} ${WRKSRC}/src/github.com/eBay/fabio/fabio.properties \
		${STAGEDIR}${PREFIX}/etc/fabio.properties.sample

.include <bsd.port.mk>
