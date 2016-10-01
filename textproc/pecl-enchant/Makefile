# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	enchant
DISTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	textproc devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libenchant Binder that Support Near All Spelling Tools

DEPRECATED=	Works only with EOL php 5.5
EXPIRATION_DATE=	2016-10-20

LICENSE=	PHP30

LIB_DEPENDS=	libenchant.so:textproc/enchant

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	56 70
CONFIGURE_ARGS+=	--with-enchant=${LOCALBASE}

.include <bsd.port.mk>
