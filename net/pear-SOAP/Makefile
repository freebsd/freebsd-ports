# Created by: Thierry Thomas (<thierry@FreeBSD.org>)
# $FreeBSD$

PORTNAME=	SOAP
PORTVERSION=	0.13.0
CATEGORIES=	net www pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	PEAR SOAP Client/Server for PHP

BUILD_DEPENDS=	${PEARDIR}/HTTP/Request.php:www/pear-HTTP_Request
RUN_DEPENDS=	${PEARDIR}/HTTP/Request.php:www/pear-HTTP_Request

USES=	pear

OPTIONS_DEFINE=	PEAR_MAIL PEAR_MAIL_MIME PEAR_NET_DIME
PEAR_MAIL_DESC=	PEAR::Mail support
PEAR_MAIL_MIME_DESC=	PEAR::Mail::Mime support
PEAR_NET_DIME_DESC=	PEAR::Net::DIME support

PEAR_MAIL_BUILD_DEPENDS=	${PEARDIR}/Mail.php:mail/pear-Mail
PEAR_MAIL_MIME_BUILD_DEPENDS=	${PEARDIR}/Mail/mime.php:mail/pear-Mail_Mime
PEAR_NET_DIME_BUILD_DEPENDS=	${PEARDIR}/Net/DIME.php:net/pear-Net_DIME

.include <bsd.port.mk>
