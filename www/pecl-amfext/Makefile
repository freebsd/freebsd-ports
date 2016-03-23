# Created by: Piotr Rybicki <meritus@innervision.pl>
# $FreeBSD$

PORTNAME=	amfext
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	meritus@innervision.pl
COMMENT=	Implements encoding and decoding of AMF and AMF3 messages

LICENSE=	PHP30

USES=		dos2unix libtool tar:tgz
USE_PHP=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	amf
IGNORE_WITH_PHP=	70

CONFIGURE_ARGS=	--with-amf

CPPFLAGS+=	-I${LOCALBASE}/include/php/ext/standard
CFLAGS+=	-Wno-deprecated

.include <bsd.port.mk>
