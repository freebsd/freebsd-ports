# Ports collection makefile for:  pear-Cache_Lite
# Date created:			  26 November 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Cache_Lite
PORTVERSION=	1.3.1
CATEGORIES=	sysutils www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR fast and safe little cache system

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Cache
FILES=		Lite/Output.php Lite/Function.php Lite.php
DOCS=		docs/technical docs/examples LICENSE TODO
TESTS=		readme test.php test2.php test3.php bench.php \
		bench2.php bench3.php
_DOCSDIR=	.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
