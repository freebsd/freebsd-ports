# Ports collection makefile for:  pear-Services_Amazon
# Date created:			  11 May,2009
# Whom:				  Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Services_Amazon
PORTVERSION=	0.8.0
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP interface to Amazon Product Advertising API

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request \
		${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		Amazon.php AmazonECS4.php
EXAMPLES=	amazon_ecs4_cache.php \
		amazon_ecs4_cart.php \
		amazon_ecs4_itemsearch.php \
		amazon_example1.php \
		config.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
