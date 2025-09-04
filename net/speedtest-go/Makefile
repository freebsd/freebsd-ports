PORTNAME=	speedtest-go
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.10
PORTREVISION=	7
CATEGORIES=	net www

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	CLI and Go API to test internet speed using speedtest.net
WWW=		https://github.com/showwin/speedtest-go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/showwin/speedtest-go
GO_TARGET=	.:${PORTNAME}

PLIST_FILES=	bin/speedtest-go

.include <bsd.port.mk>
