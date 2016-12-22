# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	stem
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	textproc pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PECL extension which provides word stemming

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	70

post-configure:
	echo "#define HAVE_XDL_ALLOCATOR_PRIV 1" >>${WRKSRC}/config.h

.include <bsd.port.mk>
