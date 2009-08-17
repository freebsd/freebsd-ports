# New ports collection makefile for:	p5-AnyEvent-XMPP
# Date created:		15 Aug, 2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	AnyEvent-XMPP
PORTVERSION=	0.51
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	An implementation of the XMPP Protocol

BUILD_DEPENDS=	p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-Net-LibIDN>=0:${PORTSDIR}/dns/p5-Net-LibIDN \
		p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer \
		p5-Object-Event>=0.7:${PORTSDIR}/devel/p5-Object-Event
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	AnyEvent::XMPP.3 \
	AnyEvent::XMPP::Connection.3 \
	AnyEvent::XMPP::Error::MUC.3 \
	AnyEvent::XMPP::Error.3 \
	AnyEvent::XMPP::Ext::Disco.3 \
	AnyEvent::XMPP::IM::Connection.3 \
	AnyEvent::XMPP::Util.3 \
	AnyEvent::XMPP::Ext::VCard.3 \
	AnyEvent::XMPP::IM::Account.3 \
	AnyEvent::XMPP::Namespaces.3 \
	AnyEvent::XMPP::IM::Roster.3 \
	AnyEvent::XMPP::Ext::MUC.3 \
	AnyEvent::XMPP::TestClient.3 \
	AnyEvent::XMPP::Ext::DataForm.3 \
	AnyEvent::XMPP::Node.3 \
	AnyEvent::XMPP::Ext::Disco::Items.3 \
	AnyEvent::XMPP::Ext::MUC::RoomInfo.3 \
	AnyEvent::XMPP::Ext::MUC::User.3 \
	AnyEvent::XMPP::Error::Presence.3 \
	AnyEvent::XMPP::Ext::MUC::Message.3 \
	AnyEvent::XMPP::Ext.3 \
	AnyEvent::XMPP::Ext::Pubsub.3 \
	AnyEvent::XMPP::SimpleConnection.3 \
	AnyEvent::XMPP::IM::Delayed.3 \
	AnyEvent::XMPP::Error::Stanza.3 \
	AnyEvent::XMPP::Ext::Disco::Info.3 \
	AnyEvent::XMPP::Writer.3 \
	AnyEvent::XMPP::IM::Contact.3 \
	AnyEvent::XMPP::IM::Message.3 \
	AnyEvent::XMPP::Ext::RegisterForm.3 \
	AnyEvent::XMPP::Ext::Registration.3 \
	AnyEvent::XMPP::Error::Message.3 \
	AnyEvent::XMPP::Error::Stream.3 \
	AnyEvent::XMPP::Error::Register.3 \
	AnyEvent::XMPP::Parser.3 \
	AnyEvent::XMPP::Error::IQAuth.3 \
	AnyEvent::XMPP::Error::Exception.3 \
	AnyEvent::XMPP::Extendable.3 \
	AnyEvent::XMPP::Ext::Version.3 \
	AnyEvent::XMPP::Error::SASL.3 \
	AnyEvent::XMPP::Ext::OOB.3 \
	AnyEvent::XMPP::Error::Parser.3 \
	AnyEvent::XMPP::Component.3 \
	AnyEvent::XMPP::Ext::Ping.3 \
	AnyEvent::XMPP::Error::IQ.3 \
	AnyEvent::XMPP::IM::Presence.3 \
	AnyEvent::XMPP::Ext::MUC::Room.3 \
	AnyEvent::XMPP::Client.3

.include <bsd.port.mk>
