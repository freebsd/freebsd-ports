PORTNAME=	httpx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.10
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Multi-purpose HTTP toolkit
WWW=		https://github.com/projectdiscovery/httpx

LICENSE=	MIT

USES=		go:1.21,modules
GO_MODULE=	github.com/projectdiscovery/httpx

DEPRECATED=	Uses old go, but try building without USES=go:someversion
EXPIRATION_DATE=2026-01-01

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
