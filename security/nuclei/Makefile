PORTNAME=	nuclei
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.10
CATEGORIES=	security

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Fast vulnerability scanner
WWW=		https://github.com/projectdiscovery/nuclei

LICENSE=	MIT

USES=		go:1.24,modules
GO_MODULE=	github.com/projectdiscovery/nuclei/v3

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
