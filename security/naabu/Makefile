PORTNAME=	naabu
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.5
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Port scanning tool
WWW=		https://github.com/projectdiscovery/naabu

LICENSE=	MIT

USES=		go:1.24,modules
GO_MODULE=	github.com/projectdiscovery/naabu/v2

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
