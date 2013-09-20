# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	stem
PORTVERSION=	1.5.1
CATEGORIES=	textproc pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A PECL extension which provides word stemming

USE_PHP=	yes
USE_PHPEXT=	yes

NO_STAGE=	yes
post-configure:
	echo "#define HAVE_XDL_ALLOCATOR_PRIV 1" >>${WRKSRC}/config.h
.include <bsd.port.mk>
