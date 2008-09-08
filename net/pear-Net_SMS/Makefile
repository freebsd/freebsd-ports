# Ports collection makefile for:  pear-Net_SMS
# Date created:		2006/08/03
# Whom:			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Net_SMS
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	net pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR SMS functionality

BUILD_DEPENDS=	${PEARDIR}/Mail.php:${PORTSDIR}/mail/pear-Mail \
		${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	gettext

CATEGORY=	Net
FILES=		SMS.php SMS/clickatell_http.php SMS/generic_smtp.php \
		SMS/sms2email_http.php SMS/vodafoneitaly_smtp.php SMS/win_http.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
