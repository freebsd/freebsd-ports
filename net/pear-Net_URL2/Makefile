# Ports collection makefile for:  pear-Net_URL
# Date created:			  2003-04-04
# Whom:				  Roman Neuhauser (<neuhauser@bellavista.cz>)
#
# $FreeBSD$
#

PORTNAME=	Net_URL
PORTVERSION=	1.0.10
PORTREVISION=	1
CATEGORIES=	net www pear
MASTER_SITES=	http://pear.php.net/get/
PKGNAMEPREFIX=	pear-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PEAR

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy parsing of Urls

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		URL.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
