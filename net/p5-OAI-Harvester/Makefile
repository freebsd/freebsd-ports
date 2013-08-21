# Created by: Paul Dlug <paul@aps.org>
# $FreeBSD$

PORTNAME=	OAI-Harvester
PORTVERSION=	1.15
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:THB
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl module to harvest using the OAI protocol

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-URI>=1.30:${PORTSDIR}/net/p5-URI \
		p5-XML-SAX>=0.12:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-XML-SAX-Base>=1.04:${PORTSDIR}/textproc/p5-XML-SAX-Base \
		p5-libwww>=2.0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

MAN1=		oai-listrecords.1 oai-listsets.1
MAN3=		Net::OAI::Base.3 Net::OAI::Error.3 Net::OAI::GetRecord.3 \
		Net::OAI::Harvester.3 Net::OAI::Identify.3 \
		Net::OAI::ListIdentifiers.3 Net::OAI::ListMetadataFormats.3 \
		Net::OAI::ListRecords.3 Net::OAI::ListSets.3 \
		Net::OAI::Record.3 Net::OAI::Record::Header.3 \
		Net::OAI::Record::OAI_DC.3 Net::OAI::ResumptionToken.3

.include <bsd.port.mk>
