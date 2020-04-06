# $FreeBSD$

PORTNAME=	traefik2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
DISTVERSIONSUFFIX=	-vendor
CATEGORIES=	net

MAINTAINER=	freebsd@funzi.org
COMMENT=	High availability reverse proxy and load balancer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	Funzinator
GH_PROJECT=	traefik
GH_SUBDIR=	src/github.com/containous/traefik

USE_RC_SUBR=	traefik

GO_BUILDFLAGS=	-ldflags "-s -w \
		-X github.com/containous/traefik/v2/pkg/version.Version=${DISTVERSION} \
		-X github.com/containous/traefik/v2/pkg/version.Codename=chevrotin \
		-X github.com/containous/traefik/v2/pkg/version.BuildDate=`date -u '+%Y-%m-%d_%I:%M:%S%p'`"
GO_TARGET=	./cmd/traefik
CGO_ENABLED=	0

USERS=		traefik
GROUPS=		traefik

PLIST_FILES=	bin/traefik \
		"@sample etc/traefik.toml.sample"

post-patch:
	# Install a sample configuration file which works by default
	# without manual tweaking
	${REINPLACE_CMD} -e 's|:80|:8088|' -e 's|:443|:8443|' \
			 -e 's|\[docker|# \[docker|' ${WRKSRC}/traefik.sample.toml

post-install:
	${INSTALL_DATA} ${WRKSRC}/traefik.sample.toml ${STAGEDIR}${PREFIX}/etc/traefik.toml.sample

.include <bsd.port.mk>
