# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fileinfo
PORTVERSION=	1.0.4
CATEGORIES=	sysutils pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	Fileinfo-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A PECL extension to retrieve info about files

USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=52
IGNORE_WITH_PHP=5 53

CONFIGURE_ARGS=	--with-fileinfo=/usr

NO_STAGE=	yes
.include <bsd.port.mk>
