# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Gungho
PORTVERSION=	0.09.008
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMAKI
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Event Based High Performance Web Crawler Framework

RUN_DEPENDS=	p5-Best>=0:${PORTSDIR}/devel/p5-Best \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-C3-Componentised>=0:${PORTSDIR}/devel/p5-Class-C3-Componentised \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-Config-Any>=0:${PORTSDIR}/devel/p5-Config-Any \
		p5-Danga-Socket-Callback>=0:${PORTSDIR}/devel/p5-Danga-Socket-Callback \
		p5-Data-Throttler>=0:${PORTSDIR}/devel/p5-Data-Throttler \
		p5-Exception-Class>=0:${PORTSDIR}/devel/p5-Exception-Class \
		p5-HTML-RobotsMETA>=0:${PORTSDIR}/www/p5-HTML-RobotsMETA \
		p5-HTTP-Parser>=0:${PORTSDIR}/www/p5-HTTP-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-IO-Async>=0:${PORTSDIR}/devel/p5-IO-Async \
		p5-Log-Dispatch>=0:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-POE-Component-Client-DNS>=0:${PORTSDIR}/dns/p5-POE-Component-Client-DNS \
		p5-POE-Component-Client-Keepalive>=0:${PORTSDIR}/net/p5-POE-Component-Client-Keepalive \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-WWW-RobotRules-Parser>=0:${PORTSDIR}/www/p5-WWW-RobotRules-Parser \
		p5-Web-Scraper-Config>=0:${PORTSDIR}/www/p5-Web-Scraper-Config \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-Class-C3-XS>=0.02:${PORTSDIR}/devel/p5-Class-C3-XS \
		p5-Class-C3>=0.16:${PORTSDIR}/devel/p5-Class-C3 \
		p5-Danga-Socket>=1.57:${PORTSDIR}/devel/p5-Danga-Socket \
		p5-Data-Throttler-Memcached>=0.0003:${PORTSDIR}/devel/p5-Data-Throttler-Memcached \
		p5-Event-Notify>=0.00004:${PORTSDIR}/devel/p5-Event-Notify \
		p5-POE-Component-Client-HTTP>=0.81:${PORTSDIR}/www/p5-POE-Component-Client-HTTP \
		p5-POE>=0.9999:${PORTSDIR}/devel/p5-POE \
		p5-UNIVERSAL-isa>=0.06:${PORTSDIR}/devel/p5-UNIVERSAL-isa
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

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
