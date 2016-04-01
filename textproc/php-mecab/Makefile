# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	mecab
PORTVERSION=	0.6.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc
PKGNAMEPREFIX=	php-

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PHP bindings of the MeCab

LICENSE=	MIT

LIB_DEPENDS=	libmecab.so:japanese/mecab

USE_GITHUB=	yes
GH_ACCOUNT=	rsky
GH_PROJECT=	${PKGNAMEPREFIX}${PORTNAME}

WRKSRC=		${WRKDIR}/${GH_PROJECT}-${GH_TAGNAME_EXTRACT}/mecab
CONFIGURE_ARGS+=	--with-mecab=${LOCALBASE}/bin/mecab-config
USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
USES=		tar:tgz

.include <bsd.port.mk>
