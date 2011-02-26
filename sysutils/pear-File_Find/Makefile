# Ports collection makefile for:	pear-File_Find
# Date created:				29 November 2002
# Whom:					Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	File_Find
PORTVERSION=	1.3.1
CATEGORIES=	sysutils www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class that facillitates the search of filesystems

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

PEAR_CATSRC=	yes
CATEGORY=	File
FILES=		Find.php
TESTS=		setup.php 01glob.phpt 02maptree.phpt 03maptreemultiple.phpt \
		04search.phpt 05search_inside.phpt bug2773.phpt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
