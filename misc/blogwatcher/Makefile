PORTNAME=	blogwatcher
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.3
PORTREVISION=	2
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Stay on top of your favorite blogs
WWW=		https://github.com/Hyaxia/blogwatcher

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	module modernc.org/sqlite only supported on aarch64 and amd64

USES=		go:1.24+,modules

GO_MODULE=	github.com/Hyaxia/blogwatcher
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
