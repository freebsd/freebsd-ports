# Ports collection makefile for:	pear-File_Find
# Date created:				29 November 2002
# Whom:					Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	File_Find
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	sysutils www pear
MASTER_SITES=	http://pear.php.net/get/
PKGNAMEPREFIX=	pear-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PEAR

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A PEAR Class to facilitate the search of filesystems

BUILD_DEPENDS=	${PEARDIR}/File.php:${PORTSDIR}/sysutils/pear-File
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	File
FILES=		Find.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
