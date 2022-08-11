PORTNAME=	mecab
PORTVERSION=	0.6.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	textproc
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PHP bindings of the MeCab

LICENSE=	MIT

DEPRECATED=	Requires php 7.4 which is set to expire on 2022-11-29
EXPIRATION_DATE=2022-11-28

LIB_DEPENDS=	libmecab.so:japanese/mecab

USES=		php:ext
USE_GITHUB=	yes
GH_ACCOUNT=	rsky
GH_PROJECT=	php-${PORTNAME}
IGNORE_WITH_PHP=	80 81 82

WRKSRC_SUBDIR=	mecab
CONFIGURE_ARGS=	--with-mecab=${LOCALBASE}/bin/mecab-config

.include <bsd.port.mk>
