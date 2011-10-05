# New ports collection makefile for:	p5-FCGI-Engine
# Date created:		2010-12-03
# Whom:			Anes Muhametov <anes@anes.su>
#
# $FreeBSD$
#

PORTNAME=	FCGI-Engine
PORTVERSION=	0.18
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A flexible engine for running FCGI-based applications

BUILD_DEPENDS=	\
	p5-Moose>=1.21:${PORTSDIR}/devel/p5-Moose \
	p5-MooseX-Daemonize>=0.12:${PORTSDIR}/devel/p5-MooseX-Daemonize \
	p5-MooseX-Getopt>=0.33:${PORTSDIR}/devel/p5-MooseX-Getopt \
	p5-MooseX-Types-Path-Class>=0.05:${PORTSDIR}/devel/p5-MooseX-Types-Path-Class \
	p5-CGI-Simple>=1.112:${PORTSDIR}/www/p5-CGI-Simple \
	p5-Test-WWW-Mechanize>=1.30:${PORTSDIR}/devel/p5-Test-WWW-Mechanize \
	p5-Test-Exception>=0.31:${PORTSDIR}/devel/p5-Test-Exception \
	p5-Declare-Constraints-Simple>=0.03:${PORTSDIR}/devel/p5-Declare-Constraints-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		FCGI::Engine.3 \
		FCGI::Engine::Core.3 \
		FCGI::Engine::Manager.3 \
		FCGI::Engine::Manager::Server.3 \
		FCGI::Engine::Manager::Server::FreeBSD6.3 \
		FCGI::Engine::Manager::Server::Plackup.3 \
		FCGI::Engine::PSGI.3 \
		FCGI::Engine::ProcManager.3 \
		FCGI::Engine::Types.3 \
		Plack::Handler::FCGI::Engine.3 \
		Plack::Handler::FCGI::Engine::ProcManager.3 \
		Plack::Server::FCGI::Engine.3 \
		Plack::Server::FCGI::Engine::ProcManager.3

.include <bsd.port.mk>
