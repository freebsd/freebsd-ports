PORTNAME=	katana
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.3
PORTREVISION=	4
CATEGORIES=	www

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Crawling and spidering framework
WWW=		https://github.com/projectdiscovery/katana

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:1.24,modules
GO_MODULE=	github.com/projectdiscovery/katana

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
