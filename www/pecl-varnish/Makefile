# Created by: Jim Ohlstein <jim@ohlste.in>
# $FreeBSD$

PORTNAME=	varnish
PORTVERSION=	1.2.1
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	jim@ohlste.in
COMMENT=	Varnish cache extension

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	varnish4>=0:${PORTSDIR}/www/varnish4

USE_PHP=	hash
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes

IGNORE_WITH_PHP=	52

.include <bsd.port.mk>
