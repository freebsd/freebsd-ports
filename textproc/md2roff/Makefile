PORTNAME=	md2roff
DISTVERSIONPREFIX=	v
DISTVERSION=	2.14.3-0.20200416233007
DISTVERSIONSUFFIX=	-c4dfa597b8d5
PORTREVISION=	15
CATEGORIES=	textproc print

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Markdown to roff converter
WWW=		https://github.com/github/hub

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/github/hub/v2
GO_TARGET=	./md2roff-bin:md2roff

PLIST_FILES=	bin/md2roff

.include <bsd.port.mk>
