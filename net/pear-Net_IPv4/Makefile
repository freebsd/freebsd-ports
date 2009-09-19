# Ports collection makefile for:  pear-Net_IPv4
# Date created:			  19 Sep, 2009
# Whom:				  Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net_IPv4
DISTVERSION=	1.3.1
CATEGORIES=	net pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	IPv4 network calculations and validation

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		Net/IPv4.php
TESTS=		AllTests.php    IPv4Test.php    MyIPv4.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
