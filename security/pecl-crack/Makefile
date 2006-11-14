# Ports collection makefile for:  pecl-crack
# Date created:			  07 March 2006
# Whom:				  Bill Moran <wmoran@collaborativefusion.com>
#
# $FreeBSD$
#

PORTNAME=	crack
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	http://www.osuweb.net/~ahaning/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	wmoran@collaborativefusion.com
COMMENT=	PECL extension to cracklib

RUN_DEPENDS=	${LOCALBASE}/libdata/cracklib/pw_dict.pwi:${PORTSDIR}/security/cracklib

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	crack

WRKSRC=		${WRKDIR}/crack-0.4

.include <bsd.port.mk>
