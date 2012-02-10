# New ports collection makefile for:	p5-OAI-Harvester
# Date created:		2003-11-13
# Whom:			Paul Dlug <paul@aps.org>
#
# $FreeBSD$
#

PORTNAME=	OAI-Harvester
PORTVERSION=	1.15
PORTEPOCH=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:THB
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A module to harvest using the OAI protocol

BUILD_DEPENDS=	p5-libwww>=2.0:${PORTSDIR}/www/p5-libwww \
		p5-URI>=1.3:${PORTSDIR}/net/p5-URI \
		p5-XML-SAX>=0.12:${PORTSDIR}/textproc/p5-XML-SAX
RUN_DEPENDS=	p5-libwww>=2.0:${PORTSDIR}/www/p5-libwww \
		p5-URI>=1.3:${PORTSDIR}/net/p5-URI \
		p5-XML-SAX>=0.12:${PORTSDIR}/textproc/p5-XML-SAX

PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		oai-listrecords.1 oai-listsets.1
MAN3=		Net::OAI::Base.3 Net::OAI::Error.3 Net::OAI::GetRecord.3 \
		Net::OAI::Harvester.3 Net::OAI::Identify.3 \
		Net::OAI::ListIdentifiers.3 Net::OAI::ListMetadataFormats.3 \
		Net::OAI::ListRecords.3 Net::OAI::ListSets.3 \
		Net::OAI::Record.3 Net::OAI::Record::Header.3 \
		Net::OAI::Record::OAI_DC.3 Net::OAI::ResumptionToken.3

.include <bsd.port.mk>
