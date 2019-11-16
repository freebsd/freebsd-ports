# $FreeBSD$

PORTNAME=	rest-server
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.8
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Performant HTTP server for sysutils/restic backend API

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	restic

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	${GO_PKGNAME}/cmd/${PORTNAME}

USE_RC_SUBR=	restserver

USERS=		restserver
GROUPS=		restserver

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
