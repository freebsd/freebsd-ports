# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-XMPP2
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	An implementation of the XMPP Protocol

BUILD_DEPENDS=	p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL \
		p5-BS-Event>=0:${PORTSDIR}/devel/p5-BS-Event \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-LibIDN>=0:${PORTSDIR}/dns/p5-Net-LibIDN \
		p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-Object-Event>=0:${PORTSDIR}/devel/p5-Object-Event \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer
RUN_DEPENDS:=	p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL \
		p5-BS-Event>=0:${PORTSDIR}/devel/p5-BS-Event \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-LibIDN>=0:${PORTSDIR}/dns/p5-Net-LibIDN \
		p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-Object-Event>=0:${PORTSDIR}/devel/p5-Object-Event \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer

USES=		perl5
USE_PERL5=	configure

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

NO_STAGE=	yes
.include <bsd.port.mk>
