# New ports collection makefile for:	HTTP::Session
# Date created:		22 Jan 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Session
PORTVERSION=	0.32
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of yet another session manager

RUN_DEPENDS=	\
	p5-Class-Accessor>=0.31:${PORTSDIR}/devel/p5-Class-Accessor \
	p5-CGI-Simple>=1.103:${PORTSDIR}/www/p5-CGI-Simple \
	p5-Digest-SHA1>=2.11:${PORTSDIR}/security/p5-Digest-SHA1 \
	p5-libwww>=5.818:${PORTSDIR}/www/p5-libwww \
	p5-UNIVERSAL-require>=0.05:${PORTSDIR}/devel/p5-UNIVERSAL-require \
	p5-URI>=1.38:${PORTSDIR}/net/p5-URI

PERL_CONFIGURE=	yes

MAN3=		HTTP::Session.3 \
		HTTP::Session::State::Cookie.3 \
		HTTP::Session::State::GUID.3 \
		HTTP::Session::State::MobileAgentID.3 \
		HTTP::Session::State::MobileAttributeID.3 \
		HTTP::Session::State::Null.3 \
		HTTP::Session::State::Test.3 \
		HTTP::Session::State::URI.3 \
		HTTP::Session::Store::CHI.3 \
		HTTP::Session::Store::DBM.3 \
		HTTP::Session::Store::File.3 \
		HTTP::Session::Store::Memcached.3 \
		HTTP::Session::Store::Null.3 \
		HTTP::Session::Store::OnMemory.3 \
		HTTP::Session::Store::Test.3

.include <bsd.port.mk>
