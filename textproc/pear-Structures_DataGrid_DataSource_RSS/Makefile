# New ports collection makefile for:	Structures_DataGrid_DataSource_RSS
# Date created:				19 Dec 2007
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Structures_DataGrid_DataSource_RSS
PORTVERSION=	0.1.1
CATEGORIES=	textproc databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	DataSource driver using RSS files

BUILD_DEPENDS=	${PEARDIR}/Structures/DataGrid/DataSource/Array.php:${PORTSDIR}/databases/pear-Structures_DataGrid_DataSource_Array
RUN_DEPENDS=	${PEARDIR}/Structures/DataGrid/DataSource/Array.php:${PORTSDIR}/databases/pear-Structures_DataGrid_DataSource_Array

USE_PHP=	mysql

CATEGORY=	Structures

FILES=		DataGrid/DataSource/RSS.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
