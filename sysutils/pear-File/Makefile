# Ports collection makefile for:  pear-File
# Date created:			  24 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	File
PORTVERSION=	1.1.0
CATEGORIES=	sysutils www pear
DISTNAME=	${PORTNAME}-${PORTVERSION}RC1

MAINTAINER=	antonio@php.net
COMMENT=	PEAR common file and directory routines

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		File.php File/CSV.php
TESTS=		parser.php test.csv FileTest.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
