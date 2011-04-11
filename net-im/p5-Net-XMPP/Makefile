# New ports collection makefile for:	p5-Net-XMPP
# Date created:				2004-12-3
# Whom:	      				Lars Eggert <lars.eggert@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	Net-XMPP
PORTVERSION=	1.02.02
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAPATRICK
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-1.02_02

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Net::XMPP provides Perl Developer access to the XMPP protocol

BUILD_DEPENDS+=	p5-XML-Stream>=1.23.04:${PORTSDIR}/textproc/p5-XML-Stream \
		p5-Digest-SHA1>=1.02:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Authen-SASL>=2.12:${PORTSDIR}/security/p5-Authen-SASL \
		p5-YAML-Tiny>=1.41:${PORTSDIR}/textproc/p5-YAML-Tiny
RUN_DEPENDS+=	p5-XML-Stream>=1.23.04:${PORTSDIR}/textproc/p5-XML-Stream \
		p5-Digest-SHA1>=1.02:${PORTSDIR}/security/p5-Digest-SHA1
TEST_DEPENDS=	p5-Test-More>=0.92:${PORTSDIR}/devel/p5-Test-More

USE_PERL5=	5.8.0+	# Require due to XML::Stream
PERL_MODBUILD=	yes

MAN3=		Net::XMPP.3 Net::XMPP::Client.3 Net::XMPP::Connection.3 \
		Net::XMPP::Debug.3 Net::XMPP::IQ.3 Net::XMPP::JID.3 \
		Net::XMPP::Message.3 Net::XMPP::Namespaces.3 \
		Net::XMPP::Presence.3 Net::XMPP::PrivacyLists.3 \
		Net::XMPP::Protocol.3 Net::XMPP::Roster.3 \
		Net::XMPP::Stanza.3

.include <bsd.port.mk>
