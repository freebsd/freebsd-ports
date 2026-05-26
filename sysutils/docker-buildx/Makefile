PORTNAME=	docker-buildx
PORTVERSION=	0.34.1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	leafoliage@FreeBSD.org
COMMENT=	Docker CLI plugin for extended build capabilities with BuildKit
WWW=		https://github.com/docker/buildx

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	nodefault
GH_ACCOUNT=	docker
GH_PROJECT=	buildx

GO_MODULE=	github.com/docker/buildx
GO_TARGET=	./cmd/buildx:${PREFIX}/lib/docker/cli-plugins/docker-buildx
GO_BUILDFLAGS=	-ldflags="\
		-X github.com/docker/buildx/version.Version=v${PORTVERSION} \
		-X github.com/docker/buildx/version.Package=github.com/docker/buildx"

PLIST_FILES=	lib/docker/cli-plugins/docker-buildx

.include <bsd.port.mk>
