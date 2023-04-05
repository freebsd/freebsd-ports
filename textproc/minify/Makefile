PORTNAME=	minify
PORTVERSION=	2.12.5
DISTVERSIONPREFIX=	v
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

USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.6.0:sys

pre-patch:
	@${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	@${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
