# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SRU
PORTVERSION=	1.00
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BRICAS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Search and Retrieval by URL

BUILD_DEPENDS=	p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-CGI-Application>=0:${PORTSDIR}/www/p5-CGI-Application \
		p5-CQL-Parser>=0:${PORTSDIR}/textproc/p5-CQL-Parser
RUN_DEPENDS=	p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-CGI-Application>=0:${PORTSDIR}/www/p5-CGI-Application \
		p5-CQL-Parser>=0:${PORTSDIR}/textproc/p5-CQL-Parser
TEST_DEPENDS=	p5-Test-Exception>=0.2:${PORTSDIR}/devel/p5-Test-Exception

MAN3=	Catalyst::Controller::SRU.3 \
	SRU.3 \
	SRU::Request.3 \
	SRU::Request::Explain.3 \
	SRU::Request::Scan.3 \
	SRU::Request::SearchRetrieve.3 \
	SRU::Response.3 \
	SRU::Response::Diagnostic.3 \
	SRU::Response::Explain.3 \
	SRU::Response::Record.3 \
	SRU::Response::Scan.3 \
	SRU::Response::SearchRetrieve.3 \
	SRU::Response::Term.3 \
	SRU::Server.3 \
	SRU::Utils.3 \
	SRU::Utils::XML.3 \
	SRU::Utils::XMLTest.3

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
