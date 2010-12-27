# New ports collection makefile for:	p5-XML-Compile-SOAP
# Date created:		2008-01-07
# Whom:			Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	XML-Compile-SOAP
PORTVERSION=	2.21
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MA/MARKOV
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Base-class for SOAP implementations

RUN_DEPENDS=	p5-XML-Compile>=1.20:${PORTSDIR}/textproc/p5-XML-Compile \
		p5-XML-Compile-Cache>=0.98:${PORTSDIR}/textproc/p5-XML-Compile-Cache \
		p5-Log-Report>=0.90:${PORTSDIR}/devel/p5-Log-Report \
		p5-libwww>=5.816:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		XML::Compile::SOAP.3 \
		XML::Compile::SOAP10.3 \
		XML::Compile::SOAP10::Operation.3 \
		XML::Compile::SOAP11.3 XML::Compile::SOAP11::Client.3 \
		XML::Compile::SOAP11::Encoding.3 \
		XML::Compile::SOAP11::Operation.3 \
		XML::Compile::SOAP11::Server.3 \
		XML::Compile::SOAP::Client.3 \
		XML::Compile::SOAP::Extension.3 \
		XML::Compile::SOAP::FAQ.3 \
		XML::Compile::SOAP::Operation.3 \
		XML::Compile::SOAP::Server.3 \
		XML::Compile::SOAP::Trace.3 \
		XML::Compile::SOAP::Util.3 XML::Compile::Transport.3 \
		XML::Compile::Transport::SOAPHTTP.3 XML::Compile::WSDL11.3 \
		XML::Compile::XOP.3 XML::Compile::XOP::Include.3

.include <bsd.port.mk>
