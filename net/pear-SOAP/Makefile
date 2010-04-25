# Ports collection makefile for:  pear-SOAP
# Date created:			  05 April 2004
# Whom:				  Thierry Thomas (<thierry@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	SOAP
PORTVERSION=	0.12.0
PORTREVISION=	1
CATEGORIES=	net www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR SOAP Client/Server for PHP

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request
RUN_DEPENDS=	${BUILD_DEPENDS}

LATEST_LINK=	pear-SOAP
OPTIONS=	PEAR_MAIL "PEAR::Mail support" off \
		PEAR_MAIL_MIME "PEAR::Mail::Mime support" off \
		PEAR_NET_DIME "PEAR::Net::DIME support" off

CATEGORY=	SOAP
FILES=		Base.php Client.php Disco.php Fault.php Parser.php \
		Server.php Transport.php Value.php WSDL.php \
		tools/genproxy.php Transport/HTTP.php \
		Transport/SMTP.php Transport/TCP.php \
		Server/Email.php Server/Email_Gateway.php \
		Server/TCP.php Type/dateTime.php Type/duration.php \
		Type/hexBinary.php
EXAMPLES=	attachment.php client.php com_client.php \
		disco_server.php email_client.php email_gateway.php \
		email_pop_gateway.php email_pop_server.php \
		email_server.php example_server.php \
		example_types.php server.php server2.php smtp.php \
		stockquote.php tcp_client.php tcp_daemon.pl \
		tcp_server.php wsdl_client.php
_EXAMPLESDIR=	example

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
