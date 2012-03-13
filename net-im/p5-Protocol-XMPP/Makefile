# New ports collection makefile for:	p5-Protocol-XMPP
# Date created:		2011-03-07
# Whom:			<ports@c0decafe.net>
#
# $FreeBSD$
#

PORTNAME=	Protocol-XMPP
PORTVERSION=	0.005
PORTREVISION=	1
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TEAM
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@c0decafe.net
COMMENT=	Protocol-level support for XMPP interaction

RUN_DEPENDS=	p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL \
		p5-XML-LibXML-SAX-ChunkParser>=0.00003:${PORTSDIR}/textproc/p5-XML-LibXML-SAX-ChunkParser

PERL_CONFIGURE=	yes

MAN3=		Protocol::XMPP.3 \
		Protocol::XMPP::Base.3 \
		Protocol::XMPP::Contact.3 \
		Protocol::XMPP::Element::Active.3 \
		Protocol::XMPP::Element::Auth.3 \
		Protocol::XMPP::Element::Bind.3 \
		Protocol::XMPP::Element::Body.3 \
		Protocol::XMPP::Element::Challenge.3 \
		Protocol::XMPP::Element::Feature.3 \
		Protocol::XMPP::Element::Features.3 \
		Protocol::XMPP::Element::HTML.3 \
		Protocol::XMPP::Element::IQ.3 \
		Protocol::XMPP::Element::JID.3 \
		Protocol::XMPP::Element::Mechanism.3 \
		Protocol::XMPP::Element::Mechanisms.3 \
		Protocol::XMPP::Element::Message.3 \
		Protocol::XMPP::Element::Nick.3 \
		Protocol::XMPP::Element::Presence.3 \
		Protocol::XMPP::Element::Proceed.3 \
		Protocol::XMPP::Element::Register.3 \
		Protocol::XMPP::Element::Response.3 \
		Protocol::XMPP::Element::Session.3 \
		Protocol::XMPP::Element::StartTLS.3 \
		Protocol::XMPP::Element::Subject.3 \
		Protocol::XMPP::Element::Success.3 \
		Protocol::XMPP::ElementBase.3 \
		Protocol::XMPP::Handler.3 \
		Protocol::XMPP::IQ::Roster.3 \
		Protocol::XMPP::Message.3 \
		Protocol::XMPP::Stream.3 \
		Protocol::XMPP::TextElement.3 \
		Protocol::XMPP::User.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
RUN_DEPENDS+=	p5-Module-Load>=0:${PORTSDIR}/devel/p5-Module-Load \
		p5-parent>=0:${PORTSDIR}/devel/p5-parent
.endif

.include <bsd.port.post.mk>
