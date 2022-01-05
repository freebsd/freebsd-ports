# Created by: Gasol Wu <gasol.wu@gmail.com>

PORTNAME=	mecab
PORTVERSION=	0.6.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	textproc
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PHP bindings of the MeCab

LICENSE=	MIT

LIB_DEPENDS=	libmecab.so:japanese/mecab

IGNORE_WITH_PHP=	80
USES=		php:ext
USE_GITHUB=	yes
GH_ACCOUNT=	rsky
GH_PROJECT=	php-${PORTNAME}

WRKSRC_SUBDIR=	mecab
CONFIGURE_ARGS=	--with-mecab=${LOCALBASE}/bin/mecab-config

.include <bsd.port.mk>
