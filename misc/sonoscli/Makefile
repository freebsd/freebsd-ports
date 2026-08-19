PORTNAME=	sonoscli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.4
PORTREVISION=	2
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Discover, group, and control Sonos speakers
WWW=		https://github.com/steipete/sonoscli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.26+,modules

GO_MODULE=	github.com/steipete/sonoscli
GO_TARGET=	./cmd/sonos

PLIST_FILES=	bin/sonos

.include <bsd.port.mk>
