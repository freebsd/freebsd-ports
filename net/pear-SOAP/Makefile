# Ports collection makefile for:  pear-SOAP
# Date created:			  05 April 2004
# Whom:				  Thierry Thomas (<thierry@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	SOAP
PORTVERSION=	0.8
CATEGORIES=	net www pear
DISTNAME=	${PORTNAME}-${PORTVERSION}RC3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SOAP Client/Server for PHP

BUILD_DEPENDS=	${PEARDIR}/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime	\
		${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request	\
		${PEARDIR}/Net/DIME.php:${PORTSDIR}/net/pear-Net_DIME
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	SOAP
FILES=		Base.php Client.php Disco.php Fault.php Parser.php Server.php	\
		Transport.php Value.php WSDL.php tools/genproxy.php		\
		Transport/HTTP.php Transport/SMTP.php Transport/TCP.php		\
		Server/Email.php Server/Email_Gateway.php Server/TCP.php	\
		Type/dateTime.php Type/duration.php Type/hexBinary.php
EXAMPLES=	attachment.php client.php com_client.php disco_server.php	\
		email_client.php email_gateway.php email_pop_gateway.php	\
		email_pop_server.php email_server.php example_server.php	\
		example_types.php server.php server2.php smtp.php		\
		stockquote.php tcp_client.php tcp_daemon.pl tcp_server.php	\
		wsdl_client.php
_EXAMPLESDIR=	example

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
