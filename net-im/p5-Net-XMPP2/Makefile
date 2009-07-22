# New ports collection makefile for:	p5-Net-XMPP2
# Date created:		2008-04-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-XMPP2
PORTVERSION=	0.14
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	An implementation of the XMPP Protocol

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/${PERL_ARCH}/Net/LibIDN.pm:${PORTSDIR}/dns/p5-Net-LibIDN \
		${SITE_PERL}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser/Expat.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/AnyEvent.pm:${PORTSDIR}/devel/p5-AnyEvent \
		${SITE_PERL}/Authen/SASL.pm:${PORTSDIR}/security/p5-Authen-SASL \
		${SITE_PERL}/BS/Event.pm:${PORTSDIR}/devel/p5-BS-Event \
		${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/XML/Writer.pm:${PORTSDIR}/textproc/p5-XML-Writer

PERL_CONFIGURE=	yes

MAN3=		Net::XMPP2.3 \
		Net::XMPP2::Client.3 \
		Net::XMPP2::Component.3 \
		Net::XMPP2::Connection.3 \
		Net::XMPP2::Error.3 \
		Net::XMPP2::Error::Exception.3 \
		Net::XMPP2::Error::IQ.3 \
		Net::XMPP2::Error::IQAuth.3 \
		Net::XMPP2::Error::MUC.3 \
		Net::XMPP2::Error::Message.3 \
		Net::XMPP2::Error::Parser.3 \
		Net::XMPP2::Error::Presence.3 \
		Net::XMPP2::Error::Register.3 \
		Net::XMPP2::Error::SASL.3 \
		Net::XMPP2::Error::Stanza.3 \
		Net::XMPP2::Error::Stream.3 \
		Net::XMPP2::Ext.3 \
		Net::XMPP2::Ext::DataForm.3 \
		Net::XMPP2::Ext::Disco.3 \
		Net::XMPP2::Ext::Disco::Info.3 \
		Net::XMPP2::Ext::Disco::Items.3 \
		Net::XMPP2::Ext::MUC.3 \
		Net::XMPP2::Ext::MUC::Message.3 \
		Net::XMPP2::Ext::MUC::Room.3 \
		Net::XMPP2::Ext::MUC::RoomInfo.3 \
		Net::XMPP2::Ext::MUC::User.3 \
		Net::XMPP2::Ext::OOB.3 \
		Net::XMPP2::Ext::Ping.3 \
		Net::XMPP2::Ext::Pubsub.3 \
		Net::XMPP2::Ext::RegisterForm.3 \
		Net::XMPP2::Ext::Registration.3 \
		Net::XMPP2::Ext::VCard.3 \
		Net::XMPP2::Ext::Version.3 \
		Net::XMPP2::Extendable.3 \
		Net::XMPP2::IM::Account.3 \
		Net::XMPP2::IM::Connection.3 \
		Net::XMPP2::IM::Contact.3 \
		Net::XMPP2::IM::Delayed.3 \
		Net::XMPP2::IM::Message.3 \
		Net::XMPP2::IM::Presence.3 \
		Net::XMPP2::IM::Roster.3 \
		Net::XMPP2::Namespaces.3 \
		Net::XMPP2::Node.3 \
		Net::XMPP2::Parser.3 \
		Net::XMPP2::SimpleConnection.3 \
		Net::XMPP2::TestClient.3 \
		Net::XMPP2::Util.3 \
		Net::XMPP2::Writer.3

.include <bsd.port.mk>
