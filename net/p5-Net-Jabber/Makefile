# New ports collection makefile for:	p5-Net-Jabber
# Date created:				28 Augest 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-Jabber
PORTVERSION=	2.0
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-
DIST_SUBDIR=	jabber

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Net::Jabber provides Perl Developer access to the Jabber protocol

BUILD_DEPENDS=	${SITE_PERL}/Net/XMPP.pm:${PORTSDIR}/net/p5-Net-XMPP
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Jabber.3 Net::Jabber::Client.3 Net::Jabber::Component.3 \
		Net::Jabber::Data.3 Net::Jabber::Debug.3 \
		Net::Jabber::Dialback.3 Net::Jabber::Dialback::Result.3 \
		Net::Jabber::Dialback::Verify.3 Net::Jabber::IQ.3 \
		Net::Jabber::JID.3 Net::Jabber::Key.3 Net::Jabber::Log.3 \
		Net::Jabber::Message.3 Net::Jabber::Namespaces.3 \
		Net::Jabber::Presence.3 Net::Jabber::Protocol.3 \
		Net::Jabber::Server.3 Net::Jabber::Stanza.3 \
		Net::Jabber::XDB.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		Port requires perl 5.8.x or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
