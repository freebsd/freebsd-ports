PORTNAME=		docker
PORTVERSION=		18.09.5
DISTVERSIONPREFIX=	v
PORTREVISION=	28
CATEGORIES=		sysutils

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Open-source application container engine
WWW=		https://www.docker.com/

LICENSE=		APACHE20

BROKEN_aarch64=		fails to build: golang.org/x/sys/unix/cap_freebsd.go:18:23: undefined: CAP_RIGHTS_VERSION_00

PLIST_FILES=		bin/docker

USE_GITHUB=		yes
GH_PROJECT=		docker-ce

USES=	cpe go

CONFLICTS_INSTALL=	docker-tray # bin/docker

GO_PKGNAME=	github.com/${PORTNAME}
GO_TARGET=	${GO_PKGNAME}/cli/cmd/docker

pre-build:
		@${MV} ${GO_WRKSRC}/components/* ${GO_WRKSRC}/
		@${CP} ${FILESDIR}/default_store_freebsd.go \
			${GO_WRKSRC}/cli/cli/config/credentials/

.include <bsd.port.mk>
