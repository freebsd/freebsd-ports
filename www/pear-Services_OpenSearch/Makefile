# Ports collection makefile for:  pear-Services_OpenSearch
# Date created:			  10 Dez 2008
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Services_OpenSearch
PORTVERSION=	0.2.0
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Search A9 OpenSearch compatible engines.

BUILD_DEPENDS=	${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer \
		${PEARDIR}/XML/RSS.php:${PORTSDIR}/devel/pear-XML_RSS
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

CATEGORY=	Services
FILES=		OpenSearch.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
