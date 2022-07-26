PORTNAME=	kopia
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.3
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Fast and secure open-source backup/restore tool

LICENSE=	APACHE20

USES=		go:modules
GO_MODULE=	github.com/kopia/kopia
GO_BUILDFLAGS=	-ldflags "\
		-X github.com/kopia/kopia/repo.BuildVersion=${DISTVERSION} \
		-X github.com/kopia/kopia/repo.BuildInfo="`date +%Y%m%d`" \
		-X github.com/kopia/kopia/repo.BuildGitHubRepo="FreeBSD/ports""

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
