# Created by: Bill Moran <wmoran@collaborativefusion.com>
# $FreeBSD$

PORTNAME=	crack
PORTVERSION=	0.4.1
PORTREVISION=	5
CATEGORIES=	security www
MASTER_SITES=	http://www.osuweb.net/~ahaning/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	wmoran@collaborativefusion.com
COMMENT=	PECL extension to cracklib

LIB_DEPENDS=	libcrack.so:${PORTSDIR}/security/cracklib

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	crack
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5

WRKSRC=		${WRKDIR}/crack-0.4

.include <bsd.port.mk>
