PORTNAME=	nuclei
DISTVERSIONPREFIX=	v
DISTVERSION=	3.11.0
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Fast vulnerability scanner
WWW=		https://github.com/projectdiscovery/nuclei

LICENSE=	MIT

USES=		go:modules
GO_MODULE=	github.com/projectdiscovery/nuclei/v3

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
