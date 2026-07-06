PORTNAME=	pspell
DISTVERSION=	1.0.1
CATEGORIES=	textproc
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Shared community extension for pspell
WWW=		https://github.com/php/pecl-text-pspell

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaspell.so:textproc/aspell

USES=		php:ext
USE_GITHUB=	yes
GH_ACCOUNT=	php
GH_PROJECT=	pecl-text-pspell
IGNORE_WITH_PHP=	82 83

TEST_TARGET=	test

.include <bsd.port.pre.mk>

.if ${PHP_VER} >= 86
post-patch:
	@${REINPLACE_CMD} -e 's|XtOffsetOf|offsetof|' ${WRKSRC}/pspell.c
.endif

.include <bsd.port.post.mk>
