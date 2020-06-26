# $FreeBSD$

PORTNAME=	keybase
PORTVERSION=	5.5.1
DISTVERSIONPREFIX=	v
MASTER_SITES=	https://github.com/keybase/client/releases/download/v${PORTVERSION}/
CATEGORIES=	security

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Keybase.io client and Keybase Filesystem (KBFS)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		go tar:xz

GO_BUILDFLAGS=	-tags production
GO_PKGNAME=	github.com/keybase/client/go
GO_TARGET=	${GO_PKGNAME}/keybase ${GO_PKGNAME}/kbfs/kbfsfuse ${GO_PKGNAME}/kbfs/kbfsgit/git-remote-keybase ${GO_PKGNAME}/kbfs/kbfstool
WRKSRC=		${WRKDIR}/client-v${PORTVERSION}/go

PLIST_FILES=	bin/git-remote-keybase bin/kbfsfuse bin/kbfstool bin/keybase 

post-patch:
	@${REINPLACE_CMD} -e '/+build/ s|,amd64||' ${WRKSRC}/vendor/github.com/keybase/go-ps/process_freebsd.go

.include <bsd.port.mk>
