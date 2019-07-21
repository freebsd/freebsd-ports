# $FreeBSD$

PORTNAME=	keybase
PORTVERSION=	4.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Keybase.io client and Keybase Filesystem (KBFS)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		go

GO_BUILDFLAGS=	-tags production
GO_PKGNAME=	github.com/keybase/client/go
GO_TARGET=	${GO_PKGNAME}/keybase ${GO_PKGNAME}/kbfs/kbfsfuse ${GO_PKGNAME}/kbfs/kbfsgit/git-remote-keybase ${GO_PKGNAME}/kbfs/kbfstool
WRKSRC_SUBDIR=	go

PLIST_FILES=	bin/git-remote-keybase bin/kbfsfuse bin/kbfstool bin/keybase 

GH_PROJECT=	client
USE_GITHUB=	yes

post-patch:
	@${MV} ${WRKSRC}/install/stop_linux.go ${WRKSRC}/install/stop_freebsd.go
	@${REINPLACE_CMD} -e '/+build/ s|$$| freebsd|' ${WRKSRC}/client/platform_specific_ctl_commands_other.go ${WRKSRC}/install/stop_freebsd.go
	@${REINPLACE_CMD} -e '/+build/ s|,amd64||' ${WRKSRC}/vendor/github.com/keybase/go-ps/process_freebsd.go

.include <bsd.port.mk>
