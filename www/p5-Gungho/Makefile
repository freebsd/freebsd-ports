# New ports collection makefile for:	p5-Gungho
# Date created:		2006-07-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Gungho
PORTVERSION=	0.08.013
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DM/DMAKI
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	gslin@gslin.org
COMMENT=	Event Based High Performance Web Crawler Framework

RUN_DEPENDS=	${SITE_PERL}/Best.pm:${PORTSDIR}/devel/p5-Best \
    		${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor \
    		${SITE_PERL}/Class/C3.pm:${PORTSDIR}/devel/p5-Class-C3 \
    		${SITE_PERL}/Class/Inspector.pm:${PORTSDIR}/devel/p5-Class-Inspector \
    		${SITE_PERL}/Config/Any.pm:${PORTSDIR}/devel/p5-Config-Any \
    		${SITE_PERL}/Data/Dump.pm:${PORTSDIR}/devel/p5-Data-Dump \
    		${SITE_PERL}/Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class \
    		${SITE_PERL}/Path/Class.pm:${PORTSDIR}/devel/p5-Path-Class \
    		${SITE_PERL}/Regexp/Common.pm:${PORTSDIR}/textproc/p5-Regexp-Common \
		${SITE_PERL}/Log/Dispatch.pm:${PORTSDIR}/devel/p5-Log-Dispatch \
		${SITE_PERL}/UNIVERSAL/isa.pm:${PORTSDIR}/devel/p5-UNIVERSAL-isa \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Gungho.3 Gungho::Base.3 Gungho::Component.3 \
		Gungho::Component::Authentication.3 \
		Gungho::Component::Authentication::Basic.3 \
		Gungho::Component::Cache.3 \
		Gungho::Component::RobotRules.3 \
		Gungho::Component::RobotRules::Rule.3 \
		Gungho::Component::RobotRules::Storage.3 \
		Gungho::Component::RobotRules::Storage::Cache.3 \
		Gungho::Component::RobotRules::Storage::DB_File.3 \
		Gungho::Component::Throttle.3 \
		Gungho::Component::Throttle::Domain.3 \
		Gungho::Component::Throttle::Simple.3 \
		Gungho::Component::Throttle::Throttler.3 \
		Gungho::Engine.3 Gungho::Engine::Danga::Socket.3 \
		Gungho::Engine::IO::Async.3 Gungho::Engine::POE.3 \
		Gungho::Exception.3 Gungho::Handler.3 \
		Gungho::Handler::FileWriter::Simple.3 \
		Gungho::Handler::Null.3 \
		Gungho::Inline.3 Gungho::Log.3 \
		Gungho::Log::Dispatch.3 \
		Gungho::Log::Simple.3 \
		Gungho::Plugin.3 Gungho::Plugin::RequestLog.3 \
		Gungho::Plugin::RequestTimer.3 \
		Gungho::Provider.3 \
		Gungho::Provider::File::Simple.3 \
		Gungho::Provider::Simple.3 \
		Gungho::Provider::YAML.3 \
		Gungho::Request.3 Gungho::Request::http.3

post-install:
		${INSTALL_SCRIPT} ${WRKSRC}/script/gungho ${PREFIX}/bin/gungho

.include <bsd.port.mk>
