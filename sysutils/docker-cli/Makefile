PORTNAME=	docker-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	29.4.2
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
#TAG_HASH!=	fetch -qo - https://api.github.com/repos/docker/cli/git/ref/tags/${DISTVERSIONPREFIX}${PORTVERSION} | grep -oE '"[a-f0-9]*"' | cut -c 2-41
#COMMIT_HASH!=	fetch -qo - https://api.github.com/repos/docker/cli/git/tags/${TAG_HASH} | grep -oE '"object":\{"sha":"[a-f0-9]*"' | grep -oE '"[a-f0-9]*"' | cut -c 2-8
COMMIT_HASH=	055a478
GO_BUILDFLAGS=	-ldflags "\
		-X github.com/docker/cli/cli/version.Version=${PORTVERSION} \
		-X github.com/docker/cli/cli/version.GitCommit=${COMMIT_HASH}"

CONFLICTS_INSTALL=	docker-tray # bin/docker

PLIST_FILES=	bin/docker

.include <bsd.port.mk>
