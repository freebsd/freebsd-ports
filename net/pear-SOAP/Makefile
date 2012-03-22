# Ports collection makefile for:  pear-SOAP
# Date created:			  05 April 2004
# Whom:				  Thierry Thomas (<thierry@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	SOAP
PORTVERSION=	0.13.0
CATEGORIES=	net www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR SOAP Client/Server for PHP

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request
RUN_DEPENDS:=	${BUILD_DEPENDS}

LATEST_LINK=	pear-SOAP
OPTIONS=	PEAR_MAIL "PEAR::Mail support" off \
		PEAR_MAIL_MIME "PEAR::Mail::Mime support" off \
		PEAR_NET_DIME "PEAR::Net::DIME support" off

CATEGORY=	SOAP
FILES=		SOAP/Base.php SOAP/Client.php SOAP/Disco.php \
		SOAP/Fault.php SOAP/Parser.php \
		SOAP/Server.php SOAP/Transport.php SOAP/Value.php \
		SOAP/WSDL.php \
		SOAP/Transport/HTTP.php SOAP/Transport/SMTP.php \
		SOAP/Transport/TCP.php SOAP/Transport/TEST.php \
		SOAP/Server/Email.php SOAP/Server/Email_Gateway.php \
		SOAP/Server/TCP.php SOAP/Server/TCP/Handler.php \
		SOAP/Type/dateTime.php SOAP/Type/duration.php \
		SOAP/Type/hexBinary.php \
		tools/genproxy.php
EXAMPLES=	attachment.php client.php com_client.php \
		disco_server.php email_client.php email_gateway.php \
		email_pop_gateway.php email_pop_server.php \
		email_server.php example_server.php \
		example_types.php server.php server2.php smtp.php \
		stockquote.php tcp_client.php tcp_daemon.pl \
		tcp_server.php wsdl_client.php
_EXAMPLESDIR=	example
TESTS=		AllTests.php bug1927.phpt bug4523.phpt \
		bug11013.phpt bug12615.phpt bug12880.phpt \
		bug14756.phpt bug16968.phpt bug16968.wsdl \
		dateTime.phpt example.wsdl \
		example_server.phpt example_server_php5.phpt \
		parser.phpt qnames_1.phpt qnames_2.phpt \
		smtp.php SOAP_BugsTest.php test.utility.php \
		wsdl.phpt xmethods.php \
		deserialize/array.phpt deserialize/multiref_1.phpt \
		deserialize/multiref_2.phpt deserialize/multiref_3.phpt \
		deserialize/multiref_4.phpt deserialize/null.phpt \
		deserialize/string.phpt deserialize/struct_1.phpt \
		deserialize/struct_2.phpt deserialize/struct_3.phpt \
		deserialize/struct_4.phpt \
		serialize/string_1.phpt serialize/string_2.phpt \
		serialize/string_doc.phpt serialize/string_doc_literal_1.phpt \
		serialize/string_literal_1.phpt \
		serialize/struct_1.phpt serialize/struct_2.phpt \
		serialize/struct_3.phpt \
		serialize/struct_doc_literal_1.phpt \
		serialize/struct_literal_1.phpt

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
