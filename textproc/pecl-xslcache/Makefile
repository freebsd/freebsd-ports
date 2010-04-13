# New ports collection makefile for:	pecl-xslcache
# Date created:			2007/10/28
# Whom:				chinsan
#
# $FreeBSD$
#

PORTNAME=	xslcache
PORTVERSION=	0.7.1
CATEGORIES=	textproc pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL
EXTRACT_SUFX=	.tgz

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Caches the parsed XSL stylesheet between sessions

DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=4

USE_PHP=	dom xml xsl
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes

.include <bsd.port.mk>
