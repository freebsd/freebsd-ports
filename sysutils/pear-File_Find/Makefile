# Ports collection makefile for:	pear-File_Find
# Date created:				29 November 2002
# Whom:					Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	File_Find
PORTVERSION=	0.4.0
CATEGORIES=	sysutils www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class that facillitates the search of filesystems

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	File
FILES=		Find.php
TESTS=		setup.php 01glob.phpt 02maptree.phpt 03maptreemultiple.phpt \
		04search.phpt 05search_inside.phpt bug2773.phpt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
