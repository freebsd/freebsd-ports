# $FreeBSD$

PORTNAME=	traefik
PORTVERSION=	1.7.22
DISTVERSIONPREFIX=	v
CATEGORIES=	net
MASTER_SITES=	LOCAL/riggs/${PORTNAME}:webui
DISTFILES=	${PORTNAME}-webui-static-${PORTVERSION}${EXTRACT_SUFX}:webui

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

GO_BUILDFLAGS=	-ldflags "-s -w \
		-X github.com/containous/traefik/version.Version=${DISTVERSION} \
		-X github.com/containous/traefik/version.BuildDate=`date -u '+%Y-%m-%d_%I:%M:%S%p'`"
GO_TARGET=	./cmd/traefik
CGO_ENABLED=	0

USERS=		traefik
GROUPS=		traefik

PLIST_FILES=	bin/traefik \
		"@sample etc/traefik.toml.sample"

# Recipe for building the web UI
# Note this is not done during a standard port build as
# it downloads node modules from the internet during build.
# Instead, we use the pre-generated from LOCAL.
# (20180510: the upath module requires node < 10)
# BUILD_DEPENDS+=	npm:www/npm-node8 \
#		yarnpkg:www/yarn-node8
#USES+=		python:2.7,build
#build-ui:
#	@cd ${WRKSRC}/webui; \
#	yarn install && \
#	yarn run build

post-patch:
	@${MV} ${WRKDIR}/static ${WRKSRC}
	# Install a sample configuration file which works by default
	# without manual tweaking
	${REINPLACE_CMD} -e 's|:80|:8088|' \
			 -e 's|\[docker|# \[docker|' ${WRKSRC}/traefik.sample.toml

pre-build:
	cd ${GO_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} generate

post-install:
	${INSTALL_DATA} ${WRKSRC}/traefik.sample.toml ${STAGEDIR}${PREFIX}/etc/traefik.toml.sample

.include <bsd.port.mk>
