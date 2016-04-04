# Created by: Jim Ohlstein <jim@ohlste.in>
# $FreeBSD$

PORTNAME=	varnish
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	jim@ohlste.in
COMMENT=	Varnish cache extension

LICENSE=	BSD2CLAUSE

BROKEN=		fails to build

BUILD_DEPENDS=	varnish4>=0:www/varnish4

USES=	tar:tgz
USE_PHP=	hash
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes

IGNORE_WITH_PHP=	52

.include <bsd.port.mk>
