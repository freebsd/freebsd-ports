# Created by: Anes Muhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	FCGI-Engine
PORTVERSION=	0.21
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Flexible engine for running FCGI-based applications

BUILD_DEPENDS=	p5-CGI-Simple>=0:${PORTSDIR}/www/p5-CGI-Simple \
		p5-Config-Any>=0:${PORTSDIR}/devel/p5-Config-Any \
		p5-Declare-Constraints-Simple>=0:${PORTSDIR}/devel/p5-Declare-Constraints-Simple \
		p5-FCGI>=0:${PORTSDIR}/www/p5-FCGI \
		p5-Moose>=0.93:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Daemonize>=0.09:${PORTSDIR}/devel/p5-MooseX-Daemonize \
		p5-MooseX-Getopt>=0.26:${PORTSDIR}/devel/p5-MooseX-Getopt \
		p5-MooseX-Types-Path-Class>=0:${PORTSDIR}/devel/p5-MooseX-Types-Path-Class
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-WWW-Mechanize>=0:${PORTSDIR}/devel/p5-Test-WWW-Mechanize

USES=		perl5
USE_PERL5=	configure

MAN3=		FCGI::Engine.3 \
		FCGI::Engine::Core.3 \
		FCGI::Engine::Manager.3 \
		FCGI::Engine::Manager::Server.3 \
		FCGI::Engine::Manager::Server::FreeBSD6.3 \
		FCGI::Engine::Manager::Server::Plackup.3 \
		FCGI::Engine::PSGI.3 \
		FCGI::Engine::ProcManager.3 \
		FCGI::Engine::ProcManager::Constrained.3 \
		FCGI::Engine::Types.3 \
		Plack::Handler::FCGI::Engine.3 \
		Plack::Handler::FCGI::Engine::ProcManager.3 \
		Plack::Server::FCGI::Engine.3 \
		Plack::Server::FCGI::Engine::ProcManager.3

.include <bsd.port.mk>
