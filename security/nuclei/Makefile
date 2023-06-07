PORTNAME=	nuclei
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9.6
CATEGORIES=	security

MAINTAINER=	nulldutra@proton.me
COMMENT=	Fast vulnerability scanner
WWW=		https://github.com/projectdiscovery/nuclei

LICENSE=	MIT

USES=		go:modules
GO_MODULE=	github.com/projectdiscovery/nuclei/v2

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
