# New ports collection makefile for:	p5-Net-XMPP
# Date created:				2004-12-3
# Whom:	      				Lars Eggert <lars.eggert@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	Net-XMPP
PORTVERSION=	1.0
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	Net::XMPP provides Perl Developer access to the XMPP protocol

BUILD_DEPENDS=	${SITE_PERL}/XML/Stream.pm:${PORTSDIR}/textproc/p5-XML-Stream \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::XMPP.3 Net::XMPP::Client.3 Net::XMPP::Connection.3 \
		Net::XMPP::Debug.3 Net::XMPP::IQ.3 Net::XMPP::JID.3 \
		Net::XMPP::Message.3 Net::XMPP::Namespaces.3 \
		Net::XMPP::Presence.3 Net::XMPP::PrivacyLists.3 \
		Net::XMPP::Protocol.3 Net::XMPP::Roster.3 \
		Net::XMPP::Stanza.3

.include <bsd.port.pre.mk>

# Require perl 5.8.x due to XML::Stream
.if ${PERL_LEVEL} < 500800
IGNORE=		Port requires perl 5.8.x or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
