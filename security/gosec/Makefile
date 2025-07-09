PORTNAME=	gosec
DISTVERSIONPREFIX=	v
DISTVERSION=	2.22.0
PORTREVISION=	5
CATEGORIES=	security devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Go security checker
WWW=		https://securego.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules

GO_MODULE=	github.com/securego/gosec/v2
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
