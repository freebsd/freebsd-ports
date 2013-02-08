# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	solr
PORTVERSION=	1.0.2
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz

MAINTAINER=	gaod@hychen.org
COMMENT=	The Apache Solr PHP extension

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
    		xml2:${PORTSDIR}/textproc/libxml2

USE_PHP=	yes
USE_PHPEXT=	yes

.include <bsd.port.mk>
