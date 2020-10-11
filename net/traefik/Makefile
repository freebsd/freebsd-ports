# $FreeBSD$

PORTNAME=	traefik
PORTVERSION=	2.3.1
CATEGORIES=	net
MASTER_SITES=	LOCAL/riggs/${PORTNAME}

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	High availability reverse proxy and load balancer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	go-bindata:devel/go-bindata

USES=		go:modules tar:xz

USE_RC_SUBR=	traefik

GO_BUILDFLAGS=	-ldflags "-s -w \
		-X github.com/traefik/traefik/v2/pkg/version.Version=${DISTVERSION} \
		-X github.com/traefik/traefik/v2/pkg/version.Codename=portbuild \
		-X github.com/traefik/traefik/v2/pkg/version.BuildDate=`date -u '+%Y-%m-%d_%I:%M:%S%p'`"
GO_TARGET=	./cmd/traefik
CGO_ENABLED=	0

USERS=		traefik
GROUPS=		traefik

PLIST_FILES=	bin/traefik \
		"@sample etc/traefik.toml.sample"

# Preparing the vendor dir for a self-contained tarball now works by just
# executing 'make gomod-vendor' and bundling the resulting ${WRKSRC}/vendor.
# Building the UI with node + yarn is no longer necessary.

post-patch:
	# Install a sample configuration file which at least allows the daemon
	# to start without manual tweaking.
	${REINPLACE_CMD} -e 's|:80|:8088|' \
			 -e 's|:443|:8433|' \
			 -e 's|\[providers.docker|# \[providers.docker|' ${WRKSRC}/traefik.sample.toml

pre-build:
	cd ${GO_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} generate

post-install:
	${INSTALL_DATA} ${WRKSRC}/traefik.sample.toml ${STAGEDIR}${PREFIX}/etc/traefik.toml.sample

.include <bsd.port.mk>
