# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	php-mecab
PORTVERSION=	0.6.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PHP bindings of the MeCab

LICENSE=	MIT

LIB_DEPENDS=	libmecab.so:japanese/mecab

USE_GITHUB=	yes
GH_ACCOUNT=	rsky

WRKSRC_SUBDIR=	mecab
CONFIGURE_ARGS=	--with-mecab=${LOCALBASE}/bin/mecab-config
USES=		php:ext
PHP_MODNAME=	mecab

.include <bsd.port.mk>
