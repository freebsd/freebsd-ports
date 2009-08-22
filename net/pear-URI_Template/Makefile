# Ports collection makefile for:  pear-URI_Template
# Date created:			  07 April 2008
# Whom:				  wenheping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	URI_Template
PORTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	net pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Parser for URI Templates

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

CATEGORY=	URI
FILES=		Template.php
TESTS=		AllTests.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
