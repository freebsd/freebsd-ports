# Created by: Thierry Thomas (<thierry@FreeBSD.org>)
# $FreeBSD$

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
OPTIONS_DEFINE=	PEAR_MAIL PEAR_MAIL_MIME PEAR_NET_DIME
PEAR_MAIL_DESC=	PEAR::Mail support
PEAR_MAIL_MIME_DESC=	PEAR::Mail::Mime support
PEAR_NET_DIME_DESC=	PEAR::Net::DIME support

PEAR_AUTOINSTALL=yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPEAR_MAIL}
BUILD_DEPENDS+=	${PEARDIR}/Mail.php:${PORTSDIR}/mail/pear-Mail
.endif

.if ${PORT_OPTIONS:MPEAR_MAIL_MIME}
BUILD_DEPENDS+=	${PEARDIR}/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime
.endif

.if ${PORT_OPTIONS:MPEAR_NET_DIME}
BUILD_DEPENDS+=	${PEARDIR}/Net/DIME.php:${PORTSDIR}/net/pear-Net_DIME
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.mk>
