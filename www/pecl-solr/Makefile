# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	solr
PORTVERSION=	2.4.0
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-

MAINTAINER=	gaod@hychen.org
COMMENT=	PHP extension for Apache Solr

LICENSE=	PHP301

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libxml2.so:textproc/libxml2

USES=		php:ext tar:tgz
USE_PHP=	json:build

.include <bsd.port.mk>
