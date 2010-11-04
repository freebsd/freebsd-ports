# Ports collection makefile for:  pear-HTTP_Download
# Date created:			  17 January 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	HTTP_Download
PORTVERSION=	1.1.4
CATEGORIES=	www devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class to send HTTP downloads

BUILD_DEPENDS=	${PEARDIR}/HTTP/Header.php:${PORTSDIR}/www/pear-HTTP_Header
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		HTTP/Download.php HTTP/Download/PgLOB.php HTTP/Download/Archive.php
TESTS=		send.php data.txt AllTests.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
