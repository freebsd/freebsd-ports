PORTNAME=	docker-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	29.7.2
CATEGORIES=	sysutils

MAINTAINER=	leafoliage@FreeBSD.org
COMMENT=	Open-source application container engine
WWW=		https://www.docker.com/

LICENSE=	APACHE20

USES=		cpe go
USE_GITHUB=	yes
GH_ACCOUNT=	docker
GH_PROJECT=	cli

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	${GO_PKGNAME}/cmd/docker
COMMIT_HASH=	a7dcaa6
GO_BUILDFLAGS=	-ldflags "\
		-X github.com/docker/cli/cli/version.Version=${PORTVERSION} \
		-X github.com/docker/cli/cli/version.GitCommit=${COMMIT_HASH}"

CONFLICTS_INSTALL=	docker-tray # bin/docker

PLIST_FILES=	bin/docker

.include <bsd.port.mk>
