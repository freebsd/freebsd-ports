PORTNAME=	nuclei
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.8
CATEGORIES=	security

MAINTAINER=	0xdutra@gmail.com
COMMENT=	Fast vulnerability scanner
WWW=		https://github.com/projectdiscovery/nuclei

LICENSE=	MIT

ONLY_FOR_ARCHS=	aarch64	amd64
ONLY_FOR_ARCHS_REASON=	32 bit upstream issue being solved # https://github.com/projectdiscovery/ratelimit/issues/4

USES=		go:modules
GO_MODULE=	github.com/projectdiscovery/nuclei/v2

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
