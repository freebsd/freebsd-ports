# New ports collection makefile for:	p5-Net-Jabber
# Date created:				28 Augest 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-Jabber
PORTVERSION=	1.29
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-
DIST_SUBDIR=    jabber

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Net::Jabber provide a Perl Developer access to the Jabber protocol

BUILD_DEPENDS=	${SITE_PERL}/XML/Stream.pm:${PORTSDIR}/textproc/p5-XML-Stream \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/${PERL_ARCH}/Unicode/String.pm:${PORTSDIR}/converters/p5-Unicode-String \
		${SITE_PERL}/Time/Timezone.pm:${PORTSDIR}/devel/p5-Time-modules
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Jabber.3 Net::Jabber::Client.3 Net::Jabber::Component.3 \
		Net::Jabber::Data.3 Net::Jabber::Debug.3 \
		Net::Jabber::Dialback.3 Net::Jabber::Dialback::Result.3 \
		Net::Jabber::Dialback::Verify.3 Net::Jabber::IQ.3 \
		Net::Jabber::JID.3 Net::Jabber::Key.3 Net::Jabber::Log.3 \
		Net::Jabber::Message.3 Net::Jabber::Namespaces.3 \
		Net::Jabber::Presence.3 Net::Jabber::Protocol.3 \
		Net::Jabber::Query.3 Net::Jabber::Server.3 Net::Jabber::X.3 \
		Net::Jabber::XDB.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=         Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
