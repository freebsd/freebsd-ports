# $FreeBSD$

PORTNAME=	httptreemux
PORTVERSION=	3.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net
PKGNAMEPREFIX=	go-

MAINTAINER=	cs@FreeBSD.org
COMMENT=	High-speed, flexible, tree-based HTTP router for Go

LICENSE=	MIT

BUILD_DEPENDS= ${LOCALBASE}/${GO_LIBDIR}/github.com/dimfeld/httppath.a:net/go-httppath

USE_GITHUB=	yes
GH_ACCOUNT=	dimfeld
USES=		go
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

.include <bsd.port.mk>
