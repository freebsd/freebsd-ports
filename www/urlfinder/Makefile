PORTNAME=	urlfinder
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.3
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	High-speed tool for passively gathering URLs
WWW=		https://github.com/projectdiscovery/urlfinder

LICENSE=	MIT

USES=		go:1.24+,modules
GO_MODULE=	github.com/projectdiscovery/${PORTNAME}

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
