PORTNAME=	yamlfmt
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.2
PORTREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Simple command line tool for formatting yaml files
WWW=		https://github.com/google/yamlfmt

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/google/yamlfmt
GO_TARGET=	./cmd/yamlfmt

PLIST_FILES=	${GO_TARGET:T:S,^,bin/,}

.include <bsd.port.mk>
