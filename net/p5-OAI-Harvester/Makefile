# New ports collection makefile for:	p5-OAI-Harvester
# Date created:		2003-11-13
# Whom:			Paul Dlug <paul@aps.org>
#
# $FreeBSD$
#

PORTNAME=	OAI-Harvester
PORTVERSION=	0.95
PORTEPOCH=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	paul@aps.org
COMMENT=	A module to harvest using the OAI protocol

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::OAI::Base.3 \
		Net::OAI::Error.3 \
		Net::OAI::GetRecord.3 \
		Net::OAI::Harvester.3 \
		Net::OAI::Identify.3 \
		Net::OAI::ListIdentifiers.3 \
		Net::OAI::ListMetadataFormats.3 \
		Net::OAI::ListRecords.3 \
		Net::OAI::ListSets.3 \
		Net::OAI::Record.3 \
		Net::OAI::Record::Header.3 \
		Net::OAI::Record::OAI_DC.3 \
		Net::OAI::ResumptionToken.3

MAN1=		oai-listsets.1 oai-listrecords.1

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		Port requires perl 5.8.x or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
