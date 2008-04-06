# New ports collection makefile for:	p5-Gungho
# Date created:		2006-07-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Gungho
PORTVERSION=	0.09.007
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DM/DMAKI
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Event Based High Performance Web Crawler Framework

RUN_DEPENDS=	${SITE_PERL}/Best.pm:${PORTSDIR}/devel/p5-Best \
		${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/Class/C3/Componentised.pm:${PORTSDIR}/devel/p5-Class-C3-Componentised \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/Class/Inspector.pm:${PORTSDIR}/devel/p5-Class-Inspector \
		${SITE_PERL}/Config/Any.pm:${PORTSDIR}/devel/p5-Config-Any \
		${SITE_PERL}/Danga/Socket/Callback.pm:${PORTSDIR}/devel/p5-Danga-Socket-Callback \
		${SITE_PERL}/Data/Throttler.pm:${PORTSDIR}/devel/p5-Data-Throttler \
		${SITE_PERL}/Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class \
		${SITE_PERL}/HTML/RobotsMETA.pm:${PORTSDIR}/www/p5-HTML-RobotsMETA \
		${SITE_PERL}/HTTP/Parser.pm:${PORTSDIR}/www/p5-HTTP-Parser \
		${SITE_PERL}/HTTP/Status.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/IO/Async/Buffer.pm:${PORTSDIR}/devel/p5-IO-Async \
		${SITE_PERL}/Log/Dispatch.pm:${PORTSDIR}/devel/p5-Log-Dispatch \
		${SITE_PERL}/POE/Component/Client/DNS.pm:${PORTSDIR}/dns/p5-POE-Component-Client-DNS \
		${SITE_PERL}/POE/Component/Client/Keepalive.pm:${PORTSDIR}/net/p5-POE-Component-Client-Keepalive \
		${SITE_PERL}/Path/Class.pm:${PORTSDIR}/devel/p5-Path-Class \
		${SITE_PERL}/Regexp/Common.pm:${PORTSDIR}/textproc/p5-Regexp-Common \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/WWW/RobotRules/Parser.pm:${PORTSDIR}/www/p5-WWW-RobotRules-Parser \
		${SITE_PERL}/Web/Scraper/Config.pm:${PORTSDIR}/www/p5-Web-Scraper-Config \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML \
		p5-Class-C3-XS>=0.02:${PORTSDIR}/devel/p5-Class-C3-XS \
		p5-Class-C3>=0.16:${PORTSDIR}/devel/p5-Class-C3 \
		p5-Danga-Socket>=1.57:${PORTSDIR}/devel/p5-Danga-Socket \
		p5-Data-Throttler-Memcached>=0.0003:${PORTSDIR}/devel/p5-Data-Throttler-Memcached \
		p5-Event-Notify>=0.00004:${PORTSDIR}/devel/p5-Event-Notify \
		p5-POE-Component-Client-HTTP>=0.81:${PORTSDIR}/www/p5-POE-Component-Client-HTTP \
		p5-POE>=0.9999:${PORTSDIR}/devel/p5-POE \
		p5-UNIVERSAL-isa>=0.06:${PORTSDIR}/devel/p5-UNIVERSAL-isa
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		gungho.1
MAN3=		Gungho.3 \
		Gungho::Base.3 \
		Gungho::Base::Class.3 \
		Gungho::Component.3 \
		Gungho::Component::Authentication.3 \
		Gungho::Component::Authentication::Basic.3 \
		Gungho::Component::BlockPrivateIP.3 \
		Gungho::Component::Cache.3 \
		Gungho::Component::Core.3 \
		Gungho::Component::RobotRules.3 \
		Gungho::Component::RobotRules::Rule.3 \
		Gungho::Component::RobotRules::Storage.3 \
		Gungho::Component::RobotRules::Storage::Cache.3 \
		Gungho::Component::RobotRules::Storage::DB_File.3 \
		Gungho::Component::RobotsMETA.3 \
		Gungho::Component::Scraper.3 \
		Gungho::Component::Setup.3 \
		Gungho::Component::Throttle.3 \
		Gungho::Component::Throttle::Domain.3 \
		Gungho::Component::Throttle::Provider.3 \
		Gungho::Component::Throttle::Simple.3 \
		Gungho::Component::Throttle::Throttler.3 \
		Gungho::Engine.3 \
		Gungho::Engine::Danga::Socket.3 \
		Gungho::Engine::IO::Async.3 \
		Gungho::Engine::POE.3 \
		Gungho::Exception.3 \
		Gungho::Handler.3 \
		Gungho::Handler::FileWriter::Simple.3 \
		Gungho::Handler::Inline.3 \
		Gungho::Handler::Null.3 \
		Gungho::Inline.3 \
		Gungho::Log.3 \
		Gungho::Log::Dispatch.3 \
		Gungho::Log::Simple.3 \
		Gungho::Manual::FAQ.3 \
		Gungho::Manual::TODO.3 \
		Gungho::Plugin.3 \
		Gungho::Plugin::Apoptosis.3 \
		Gungho::Plugin::RequestLog.3 \
		Gungho::Plugin::RequestTimer.3 \
		Gungho::Plugin::Statistics.3 \
		Gungho::Plugin::Statistics::Format::XML.3 \
		Gungho::Plugin::Statistics::Storage::SQLite.3 \
		Gungho::Provider.3 \
		Gungho::Provider::File::Simple.3 \
		Gungho::Provider::Inline.3 \
		Gungho::Provider::Simple.3 \
		Gungho::Provider::YAML.3 \
		Gungho::Request.3 \
		Gungho::Request::http.3 \
		Gungho::Response.3 \
		Gungho::Util.3

post-install:
		${INSTALL_SCRIPT} ${WRKSRC}/script/gungho ${PREFIX}/bin/gungho

.include <bsd.port.mk>
