# New ports collection makefile for:	HTTP::Engine
# Date created:		20 Jan 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Engine
PORTVERSION=	0.1.8
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for HTTP Server Engine Drivers

RUN_DEPENDS=	\
	p5-Any-Moose>=0.08:${PORTSDIR}/devel/p5-Any-Moose \
	p5-Mouse>=0.21:${PORTSDIR}/devel/p5-Moose \
	p5-MouseX-Types>=0.01:${PORTSDIR}/devel/p5-MouseX-Types \
	p5-Class-Method-Modifiers>=0:${PORTSDIR}/devel/p5-Class-Method-Modifiers \
	p5-CGI-Simple>=1.103:${PORTSDIR}/www/p5-CGI-Simple \
	p5-HTTP-Body>=1.05:${PORTSDIR}/www/p5-HTTP-Body \
	p5-HTTP-Headers-Fast>=0.09:${PORTSDIR}/www/p5-HTTP-Headers-Fast \
	p5-URI>=1.36:${PORTSDIR}/net/p5-URI \
	p5-HTTP-Server-Simple>=0.35:${PORTSDIR}/www/p5-HTTP-Server-Simple
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTTP::Engine.3 \
		HTTP::Engine::Cookbook.3 \
		HTTP::Engine::Interface::CGI.3 \
		HTTP::Engine::Interface::FCGI.3 \
		HTTP::Engine::Interface::ModPerl.3 \
		HTTP::Engine::Interface::POE.3 \
		HTTP::Engine::Interface::ServerSimple.3 \
		HTTP::Engine::Interface::Standalone.3 \
		HTTP::Engine::Interface::Test.3 \
		HTTP::Engine::MinimalCGI.3 \
		HTTP::Engine::Request.3 \
		HTTP::Engine::Request::Upload.3 \
		HTTP::Engine::Response.3 \
		HTTP::Engine::Role::Interface.3 \
		HTTP::Engine::Test::Request.3 \
		HTTP::Engine::Types::Core.3

.include <bsd.port.mk>
