# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	mecab
PORTVERSION=	0.6.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PHP bindings of the MeCab

LICENSE=	MIT

LIB_DEPENDS=	libmecab.so:japanese/mecab

USE_GITHUB=	yes
GH_ACCOUNT=	rsky
GH_PROJECT=	php-${PORTNAME}

WRKSRC_SUBDIR=	mecab
CONFIGURE_ARGS=	--with-mecab=${LOCALBASE}/bin/mecab-config
USES=		php:ext
IGNORE_WITH_PHP=	74

.include <bsd.port.mk>
