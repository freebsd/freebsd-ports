# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	solr
PORTVERSION=	1.1.1
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz

MAINTAINER=	gaod@hychen.org
COMMENT=	The Apache Solr PHP extension

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libxml2.so:textproc/libxml2

USES=		php:ext
USE_PHP=	json:build
IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
