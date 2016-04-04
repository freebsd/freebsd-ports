# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yaz
PORTVERSION=	1.1.6
CATEGORIES=	net pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	fw@moov.de
COMMENT=	PECL extension that implements a Z39.50 client

LICENSE=	PHP301

LIB_DEPENDS=	libyaz.so:net/yaz

USE_PHP=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=	70

CONFIGURE_ARGS=	--with-yaz=${LOCALBASE}

.include <bsd.port.mk>
