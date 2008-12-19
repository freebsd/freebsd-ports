# New ports collection makefile for:	pecl-mnogosearch
# Date created:				10 October 2006
# Whom:					breaker1 <breaker1@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mnogosearch
PORTVERSION=	1.0.0
CATEGORIES=	www pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	breaker1@gmail.com
COMMENT=	The mnoGoSearch Bindings for php51+

BUILD_DEPENDS=	indexer:${PORTSDIR}/www/mnogosearch

BROKEN=		does not compile
DEPRECATED=	has been broken for more than 6 months
EXPIRATION_DATE=2009-01-19

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--with-mnogosearch=${LOCALBASE}

.include <bsd.port.mk>
