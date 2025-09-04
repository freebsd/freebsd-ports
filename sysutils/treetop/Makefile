PORTNAME=	treetop
DISTVERSIONPREFIX=	v
DISTVERSION=	${MODVERSION:S/-/./g:R}
PORTREVISION=	5
CATEGORIES=	sysutils

MAINTAINER=	hoanga@gmail.com
COMMENT=	Treetop is a fast, animated disk summarizer
WWW=		https://github.com/eigenhombre/treetop

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/README.md

USES=	go:modules
MODVERSION=	0.0.0-20220201023028-ea3c2d67e9d1
GO_MODULE=	github.com/eigenhombre/treetop@v${MODVERSION}
#GO_TARGET=	./${PORTNAME}

PLIST_FILES=	bin/treetop

.include <bsd.port.mk>
