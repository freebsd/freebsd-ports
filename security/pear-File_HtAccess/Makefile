# Ports collection makefile for:  pear-File_HtAccess
# Date created:			  08 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	File_HtAccess
PORTVERSION=	1.1.0
CATEGORIES=	security www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class to manipulate .htaccess files

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	File
FILES=		HtAccess.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
