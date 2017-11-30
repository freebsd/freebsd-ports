# $FreeBSD$

PORTNAME=	kbfs
PORTVERSION=	1.0.36
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Keybase Filesystem (KBFS)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	-tags production ${GO_PKGNAME}/kbfsfuse ${GO_PKGNAME}/kbfstool
USES=		go

PLIST_FILES=	bin/kbfsfuse bin/kbfstool

GH_ACCOUNT=	keybase
USE_GITHUB=	yes

.include <bsd.port.mk>
