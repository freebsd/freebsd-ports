PORTNAME=	pspell
DISTVERSION=	1.0.1
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Shared community extension for pspell
WWW=		https://github.com/php/pecl-text-pspell

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaspell.so:textproc/aspell

USES=		php:pecl
IGNORE_WITH_PHP=	81 82 83

TEST_TARGET=	test

.include <bsd.port.mk>
