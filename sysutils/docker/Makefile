PORTNAME=		docker
PORTVERSION=		29.4.2
DISTVERSIONPREFIX=	v
CATEGORIES=		sysutils

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Open-source application container engine
WWW=			https://www.docker.com/

LICENSE=		APACHE20

PLIST_FILES=		bin/docker

USE_GITHUB=		yes
GH_ACCOUNT=		docker
GH_PROJECT=		cli

USES=			cpe go:1.23+

GO_PKGNAME=		github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=		${GO_PKGNAME}/cmd/docker

CONFLICTS_INSTALL=	docker-tray # bin/docker

TAG_HASH!=		fetch -qo - https://api.github.com/repos/docker/cli/git/ref/tags/${DISTVERSIONPREFIX}${PORTVERSION} | grep -oE '"[a-f0-9]*"' | cut -c 2-41
COMMIT_HASH!=		fetch -qo - https://api.github.com/repos/docker/cli/git/tags/${TAG_HASH} | grep -oE '"object":\{"sha":"[a-f0-9]*"' | grep -oE '"[a-f0-9]*"' | cut -c 2-8
GO_BUILDFLAGS=		-ldflags "\
			-X github.com/docker/cli/cli/version.Version=${PORTVERSION} \
			-X github.com/docker/cli/cli/version.GitCommit=${COMMIT_HASH}"

.include <bsd.port.mk>
