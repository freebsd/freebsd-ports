# Ports collection makefile for:  pear-File
# Date created:			  24 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	File
PORTVERSION=	1.3.0r1
PORTEPOCH=	1
CATEGORIES=	sysutils www pear
DISTNAME=	${PORTNAME}-1.3.0RC1

MAINTAINER=	bg1tpt@gmail.com
COMMENT=	PEAR common file and directory routines

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	pcre

FILES=		File.php File/Util.php File/CSV.php
TESTS=		parser.php test.csv FileTest.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
