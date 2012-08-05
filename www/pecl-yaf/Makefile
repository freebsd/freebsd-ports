# New ports collection makefile for:	php-yaf
# Date created:		13 May 2011
# Whom:			johnpupu <johnpupu@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	yaf
PORTVERSION=	2.1.17
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	johnpupu@gmail.com
COMMENT=	Yaf is a php framework, the difference is yaf is a PHP Extension

LIB_DEPENDS=	pcre.1:${PORTSDIR}/devel/pcre

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--with-php-config=${PREFIX}/bin/php-config

USE_PHP=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes

.include <bsd.port.mk>
