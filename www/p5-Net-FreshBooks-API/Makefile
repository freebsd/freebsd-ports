# New ports collection makefile for:	p5-Net-FreshBooks-API
# Date created:		2010-01-03
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-FreshBooks-API
PORTVERSION=	0.23
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy OO access to the FreshBooks.com API

RUN_DEPENDS=	p5-B-Hooks-EndOfScope>=0.09:${PORTSDIR}/devel/p5-B-Hooks-EndOfScope \
		p5-Clone>=0:${PORTSDIR}/devel/p5-Clone \
		p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-Lingua-EN-Inflect>=0:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Net-OAuth-Simple>=0:${PORTSDIR}/net/p5-Net-OAuth-Simple \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean

PERL_MODBUILD=	yes

MAN3=		Net::FreshBooks::API.3 \
		Net::FreshBooks::API::Base.3 \
		Net::FreshBooks::API::Client.3 \
		Net::FreshBooks::API::Client::Contact.3 \
		Net::FreshBooks::API::Estimate.3 \
		Net::FreshBooks::API::Gateway.3 \
		Net::FreshBooks::API::Invoice.3 \
		Net::FreshBooks::API::InvoiceLine.3 \
		Net::FreshBooks::API::Iterator.3 \
		Net::FreshBooks::API::Language.3 \
		Net::FreshBooks::API::Links.3 \
		Net::FreshBooks::API::OAuth.3 \
		Net::FreshBooks::API::Payment.3 \
		Net::FreshBooks::API::Recurring.3 \
		Net::FreshBooks::API::Recurring::AutoBill.3 \
		Net::FreshBooks::API::Recurring::AutoBill::Card.3 \
		Net::FreshBooks::API::Recurring::AutoBill::Card::Expiration.3 \
		Net::FreshBooks::API::Role::CRUD.3 \
		Net::FreshBooks::API::Role::Common.3 \
		Net::FreshBooks::API::Role::Iterator.3 \
		Net::FreshBooks::API::Role::LineItem.3 \
		Net::FreshBooks::API::Role::SendBy.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS+=	p5-Module-Build>=0.3601:${PORTSDIR}/devel/p5-Module-Build
.endif

.if ${PERL_LEVEL} < 501400
RUN_DEPENDS+=	p5-parent>=0.224:${PORTSDIR}/devel/p5-parent
TEST_DEPENDS+=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
