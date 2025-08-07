PORTNAME=	rest-server
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.0
PORTREVISION=	6
CATEGORIES=	sysutils

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Performant HTTP server for sysutils/restic backend API
WWW=		https://github.com/restic/rest-server

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_RC_SUBR=	restserver
GO_MODULE=	github.com/restic/rest-server
GO_TARGET=	./cmd/rest-server

USERS=		restserver
GROUPS=		restserver

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
