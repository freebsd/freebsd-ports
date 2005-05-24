# Ports collection makefile for:  pear-Numbers_Roman
# Date created:			  24 May 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Numbers_Roman
PORTVERSION=	0.2.0
CATEGORIES=	textproc devel pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR methods for converting to and from Roman Numerals

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Numbers
FILES=		Roman.php
EXAMPLES=	example.php
_EXAMPLESDIR=	docs

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
