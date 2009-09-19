# New ports collection makefile for:	p5-Net-XMPP
# Date created:				2004-12-3
# Whom:	      				Lars Eggert <lars.eggert@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	Net-XMPP
PORTVERSION=	1.02
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Net::XMPP provides Perl Developer access to the XMPP protocol

BUILD_DEPENDS+=	p5-XML-Stream>=1.22:${PORTSDIR}/textproc/p5-XML-Stream \
		p5-Digest-SHA1>=1.02:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS+=	p5-XML-Stream>=1.22:${PORTSDIR}/textproc/p5-XML-Stream \
		p5-Digest-SHA1>=1.02:${PORTSDIR}/security/p5-Digest-SHA1

USE_PERL5=	5.8.0+	# Require perl 5.8.x due to XML::Stream
PERL_MODBUILD=	yes

MAN3=		Net::XMPP.3 Net::XMPP::Client.3 Net::XMPP::Connection.3 \
		Net::XMPP::Debug.3 Net::XMPP::IQ.3 Net::XMPP::JID.3 \
		Net::XMPP::Message.3 Net::XMPP::Namespaces.3 \
		Net::XMPP::Presence.3 Net::XMPP::PrivacyLists.3 \
		Net::XMPP::Protocol.3 Net::XMPP::Roster.3 \
		Net::XMPP::Stanza.3

.include <bsd.port.mk>
