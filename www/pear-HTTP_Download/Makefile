# Ports collection makefile for:  pear-HTTP_Download
# Date created:			  17 January 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	HTTP_Download
PORTVERSION=	1.0.0
CATEGORIES=	www devel pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class to send HTTP downloads

BUILD_DEPENDS=	${PEARDIR}/HTTP/Header.php:${PORTSDIR}/www/pear-HTTP_Header
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTTP
FILES=		Download.php Download/PgLOB.php Download/Archive.php
TESTS=		send.php testcase.php data.txt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
