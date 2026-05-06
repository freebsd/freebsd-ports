PORTNAME=	docker-compose
PORTVERSION=	5.1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	leafoliage@FreeBSD.org
COMMENT=	Define and run multi-container applications with Docker
WWW=		https://github.com/docker/compose/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	nodefault
GH_ACCOUNT=	docker
GH_PROJECT=	compose

GO_MODULE=	github.com/docker/compose/v5
GO_TARGET=	./cmd:${PREFIX}/lib/docker/cli-plugins/docker-compose
GO_BUILDFLAGS=	-ldflags="\
		-X github.com/docker/compose/v5/internal.Version=v${PORTVERSION}"


PLIST_FILES=	lib/docker/cli-plugins/docker-compose

.include <bsd.port.mk>
