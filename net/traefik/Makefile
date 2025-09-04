PORTNAME=	traefik
PORTVERSION=	3.4.5
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	LOCAL/riggs/${PORTNAME}

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	High availability reverse proxy and load balancer
WWW=		https://traefik.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	go-bindata:devel/go-bindata

USES=		cpe go:1.24,modules tar:xz

USE_RC_SUBR=	traefik

GO_BUILDFLAGS=	-ldflags "-s -w \
		-X github.com/traefik/traefik/v3/pkg/version.Version=${DISTVERSION} \
		-X github.com/traefik/traefik/v3/pkg/version.Codename=portbuild \
		-X github.com/traefik/traefik/v3/pkg/version.BuildDate=`date -u '+%Y-%m-%d_%I:%M:%S%p'`"
GO_TARGET=	./cmd/traefik
CGO_ENABLED=	0

USERS=		traefik
GROUPS=		traefik

PLIST_FILES=	bin/traefik \
		"@sample etc/traefik.toml.sample" \
		"@sample etc/traefik.yml.sample"

# Preparing the vendor dir for a self-contained tarball now works by just
# running 'go generate && go mod vendor' as a user and bundling the resulting
# ${WRKSRC}/vendor directory.
# Building the UI with node + yarn is no longer necessary.

pre-build:
	cd ${GO_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} generate

post-install:
	${INSTALL_DATA} ${WRKSRC}/traefik.sample.toml ${STAGEDIR}${PREFIX}/etc/traefik.toml.sample
	${INSTALL_DATA} ${WRKSRC}/traefik.sample.yml ${STAGEDIR}${PREFIX}/etc/traefik.yml.sample

.include <bsd.port.mk>
