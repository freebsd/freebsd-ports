# Ports collection makefile for: pear-HTTP_Client
# Date created:		01 February 2005
# Whom:				Joseph Scott (<joseph@randomnetworks.com>)
#
# $FreeBSD$
#

PORTNAME=		HTTP_Client
PORTVERSION=	1.0.0
CATEGORIES=		www pear

MAINTAINER=		joseph@randomnetworks.com
COMMENT=		PEAR classes for high level HTTP requests

BUILD_DEPENDS=	${PEARDIR}/HTTP.php:${PORTSDIR}/www/pear-HTTP \
				${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=		HTTP
FILES=			Client.php Client/CookieManager.php
EXAMPLES=		link-checker.php
_EXAMPLESDIR=	examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
