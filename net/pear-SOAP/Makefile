# Ports collection makefile for:  pear-SOAP
# Date created:			  05 April 2004
# Whom:				  Thierry Thomas (<thierry@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	SOAP
PORTVERSION=	0.13.0
CATEGORIES=	net www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR SOAP Client/Server for PHP

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request
RUN_DEPENDS:=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request

LATEST_LINK=	pear-SOAP
OPTIONS=	PEAR_MAIL "PEAR::Mail support" off \
		PEAR_MAIL_MIME "PEAR::Mail::Mime support" off \
		PEAR_NET_DIME "PEAR::Net::DIME support" off

PEAR_AUTOINSTALL=yes

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_MAIL)
BUILD_DEPENDS+=	${PEARDIR}/Mail.php:${PORTSDIR}/mail/pear-Mail
.endif

.if defined(WITH_PEAR_MAIL_MIME)
BUILD_DEPENDS+=	${PEARDIR}/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime
.endif

.if defined(WITH_PEAR_NET_DIME)
BUILD_DEPENDS+=	${PEARDIR}/Net/DIME.php:${PORTSDIR}/net/pear-Net_DIME
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
