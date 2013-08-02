# Created by: Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
# $FreeBSD$

PORTNAME=	Net-Jabber
PORTVERSION=	2.0
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DIST_SUBDIR=	jabber

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Net::Jabber provides Perl Developer access to the Jabber protocol

BUILD_DEPENDS=	p5-Net-XMPP>=0:${PORTSDIR}/net-im/p5-Net-XMPP
RUN_DEPENDS=	p5-Net-XMPP>=0:${PORTSDIR}/net-im/p5-Net-XMPP

USES=		perl5
USE_PERL5=	configure

MAN3=		Net::Jabber.3 Net::Jabber::Client.3 Net::Jabber::Component.3 \
		Net::Jabber::Data.3 Net::Jabber::Debug.3 \
		Net::Jabber::Dialback.3 Net::Jabber::Dialback::Result.3 \
		Net::Jabber::Dialback::Verify.3 Net::Jabber::IQ.3 \
		Net::Jabber::JID.3 Net::Jabber::Key.3 Net::Jabber::Log.3 \
		Net::Jabber::Message.3 Net::Jabber::Namespaces.3 \
		Net::Jabber::Presence.3 Net::Jabber::Protocol.3 \
		Net::Jabber::Server.3 Net::Jabber::Stanza.3 \
		Net::Jabber::XDB.3

.include <bsd.port.mk>
