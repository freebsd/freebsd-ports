# New ports collection makefile for:	p5-Net-Jabber
# Date created:				28 Augest 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-Jabber
PORTVERSION=	1.0021
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@cae.ce.ntu.edu.tw

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/Stream.pm:${PORTSDIR}/textproc/p5-XML-Stream \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Unicode/String.pm:${PORTSDIR}/converters/p5-Unicode-String \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Time/Timezone.pm:${PORTSDIR}/devel/p5-Time

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Net::Jabber.3 \
		Net::Jabber::Client.3 \
		Net::Jabber::Component.3 \
		Net::Jabber::Data.3 \
		Net::Jabber::Data::Auth.3 \
		Net::Jabber::Debug.3 \
		Net::Jabber::Dialback.3 \
		Net::Jabber::Dialback::Result.3 \
		Net::Jabber::Dialback::Verify.3 \
		Net::Jabber::IQ.3 \
		Net::Jabber::JID.3 \
		Net::Jabber::Key.3 \
		Net::Jabber::Log.3 \
		Net::Jabber::Message.3 \
		Net::Jabber::Presence.3 \
		Net::Jabber::Protocol.3 \
		Net::Jabber::Query.3 \
		Net::Jabber::Query::Agent.3 \
		Net::Jabber::Query::Agents.3 \
		Net::Jabber::Query::Auth.3 \
		Net::Jabber::Query::AutoUpdate.3 \
		Net::Jabber::Query::AutoUpdate::Release.3 \
		Net::Jabber::Query::Filter.3 \
		Net::Jabber::Query::Filter::Rule.3 \
		Net::Jabber::Query::Fneg.3 \
		Net::Jabber::Query::Oob.3 \
		Net::Jabber::Query::Register.3 \
		Net::Jabber::Query::Roster.3 \
		Net::Jabber::Query::Roster::Item.3 \
		Net::Jabber::Query::Search.3 \
		Net::Jabber::Query::Search::Item.3 \
		Net::Jabber::Query::Time.3 \
		Net::Jabber::Query::Version.3 \
		Net::Jabber::Server.3 \
		Net::Jabber::X.3 \
		Net::Jabber::X::AutoUpdate.3 \
		Net::Jabber::X::Delay.3 \
		Net::Jabber::X::Encrypted.3 \
		Net::Jabber::X::Form.3 \
		Net::Jabber::X::Form::Field.3 \
		Net::Jabber::X::Form::Field::Option.3 \
		Net::Jabber::X::GC.3 \
		Net::Jabber::X::Ident.3 \
		Net::Jabber::X::Oob.3 \
		Net::Jabber::X::ReplyPres.3 \
		Net::Jabber::X::Roster.3 \
		Net::Jabber::X::Roster::Item.3 \
		Net::Jabber::X::SXPM.3 \
		Net::Jabber::X::SXPM::Map.3 \
		Net::Jabber::X::Signed.3 \
		Net::Jabber::XDB.3

.include <bsd.port.mk>
