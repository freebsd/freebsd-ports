# $FreeBSD$

PORTNAME=	kbfs
PORTVERSION=	2.13.1
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Keybase Filesystem (KBFS)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTSCOUT=	skipv:initial-git-on-android

USES=		go

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	-tags production ${GO_PKGNAME}/go/kbfs/kbfsfuse ${GO_PKGNAME}/go/kbfs/kbfsgit/git-remote-keybase ${GO_PKGNAME}/go/kbfs/kbfstool

PLIST_FILES=	bin/git-remote-keybase bin/kbfsfuse bin/kbfstool

GH_ACCOUNT=	keybase
GH_PROJECT=	client
USE_GITHUB=	yes

.include <bsd.port.mk>
