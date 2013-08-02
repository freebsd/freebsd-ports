# Created by: Dominic Mitchell <dom@happygiraffe.net>
# $FreeBSD$

PORTNAME=	RPC-XML
PORTVERSION=	0.77
PORTREVISION=	1
CATEGORIES=	net www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	XML-RPC client and server library for Perl

BUILD_DEPENDS=	p5-XML-Parser>=2.31:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-libwww>=5.834:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	p5-XML-Parser>=2.31:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-libwww>=5.834:${PORTSDIR}/www/p5-libwww

USE_GMAKE=	yes
USES=		perl5
USE_PERL5=	configure

MAN1=		make_method.1
MAN3=		Apache::RPC::Server.3 \
		Apache::RPC::Status.3 \
		RPC::XML.3 \
		RPC::XML::Client.3 \
		RPC::XML::Parser.3 \
		RPC::XML::Parser::XMLLibXML.3 \
		RPC::XML::Parser::XMLParser.3 \
		RPC::XML::ParserFactory.3 \
		RPC::XML::Procedure.3 \
		RPC::XML::Server.3

.include <bsd.port.mk>
