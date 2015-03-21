# Created by: Piotr Rybicki <meritus@innervision.pl>
# $FreeBSD$

PORTNAME=	amfext
PORTVERSION=	0.9.2
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	meritus@innervision.pl
COMMENT=	Implements encoding and decoding of AMF and AMF3 messages

DEPRECATED=	requires php53, security EOL reached 14 Aug 2014
EXPIRATION_DATE=	2015-04-15

IGNORE_WITH_PHP=5 55 56
USE_PHP=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	amf

CONFIGURE_ARGS=	--enable-amf
CPPFLAGS+=	-I${LOCALBASE}/include/php/ext/standard

.include <bsd.port.mk>
