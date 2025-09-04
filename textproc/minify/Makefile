PORTNAME=	minify
PORTVERSION=	2.20.37
DISTVERSIONPREFIX=	v
PORTREVISION=	8
CATEGORIES=	textproc www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Go minifiers for web formats
WWW=		https://github.com/tdewolff/minify

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/tdewolff/minify/v2
GO_TARGET=	./cmd/minify

PLIST_FILES=	bin/minify

.include <bsd.port.mk>
