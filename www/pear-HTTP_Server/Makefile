# Ports collection makefile for:  pear-HTTP_Server
# Date created:			  24 Octobre 2004
# Whom:				  Gerrit Beine (<tux@pinguru.net>)
#
# $FreeBSD$
#

PORTNAME=	HTTP_Server
PORTVERSION=	0.4.0
CATEGORIES=	www devel pear

MAINTAINER=	tux@pinguru.net
COMMENT=	HTTP server class

BUILD_DEPENDS=	${PEARDIR}/HTTP.php:${PORTSDIR}/www/pear-HTTP \
		${PEARDIR}/Net/Server.php:${PORTSDIR}/net/pear-Net_Server
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTTP
FILES=		Server.php Server/Request.php
EXAMPLES=	HTTP_Server_File.php www/index.html

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
