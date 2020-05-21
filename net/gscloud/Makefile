# $FreeBSD$

PORTNAME=	gscloud
DISTVERSION=	g20200504
CATEGORIES=	net devel

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Official command-line interface for gridscale's API written in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	gridscale
GH_TAGNAME=	3705cba

GO_PKGNAME=	github.com/gridscale/gscloud/cmd
GO_TARGET=	.

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
