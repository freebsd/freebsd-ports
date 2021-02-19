# $FreeBSD$

PORTNAME=	modules2tuple
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.3
PORTREVISION=	1
CATEGORIES=	ports-mgmt

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Generate GH_TUPLE from modules.txt

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/dmgk/modules2tuple/v2
GO_BUILDFLAGS=	-ldflags="-s -w -X main.version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
