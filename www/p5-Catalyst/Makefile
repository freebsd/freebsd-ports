# ex:ts=8
# Ports collection makefile for:	p5-Catalyst
# Date created:			Apr 7, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Catalyst
PORTVERSION=	5.30
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/M/MR/MRAMBERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@balker.dk
COMMENT=	The Elegant MVC Web Application Framework

BUILD_DEPENDS=	${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-exports \
		${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/HTTP/Daemon.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/Module/Pluggable/Fast.pm:${PORTSDIR}/devel/p5-Module-Pluggable-Fast \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/Text/ASCIITable.pm:${PORTSDIR}/textproc/p5-Text-ASCIITable \
		${SITE_PERL}/Tree/Simple.pm:${PORTSDIR}/devel/p5-Tree-Simple \
		${SITE_PERL}/Tree/Simple/Visitor/FindByPath.pm:${PORTSDIR}/devel/p5-Tree-Simple-VisitorFactory \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Path/Class.pm:${PORTSDIR}/devel/p5-Path-Class
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN1=	catalyst.pl.1
MAN3=	Catalyst.3 \
	Catalyst::Base.3 \
	Catalyst::Build.3 \
	Catalyst::Dispatcher.3 \
	Catalyst::Engine.3 \
	Catalyst::Engine::Apache.3 \
	Catalyst::Engine::Apache::Base.3 \
	Catalyst::Engine::Apache::MP13.3 \
	Catalyst::Engine::Apache::MP13::Apreq.3 \
	Catalyst::Engine::Apache::MP13::Base.3 \
	Catalyst::Engine::Apache::MP19.3 \
	Catalyst::Engine::Apache::MP19::Apreq.3 \
	Catalyst::Engine::Apache::MP19::Base.3 \
	Catalyst::Engine::Apache::MP20.3 \
	Catalyst::Engine::Apache::MP20::Apreq.3 \
	Catalyst::Engine::Apache::MP20::Base.3 \
	Catalyst::Engine::CGI.3 \
	Catalyst::Engine::CGI::APR.3 \
	Catalyst::Engine::CGI::Base.3 \
	Catalyst::Engine::FastCGI.3 \
	Catalyst::Engine::FastCGI::APR.3 \
	Catalyst::Engine::FastCGI::Base.3 \
	Catalyst::Engine::HTTP.3 \
	Catalyst::Engine::HTTP::Base.3 \
	Catalyst::Engine::HTTP::Daemon.3 \
	Catalyst::Engine::SpeedyCGI.3 \
	Catalyst::Engine::SpeedyCGI::Base.3 \
	Catalyst::Engine::Test.3 \
	Catalyst::Exception.3 \
	Catalyst::Helper.3 \
	Catalyst::Log.3 \
	Catalyst::Manual.3 \
	Catalyst::Manual::Cookbook.3 \
	Catalyst::Manual::FAQ.3 \
	Catalyst::Manual::Internals.3 \
	Catalyst::Manual::Intro.3 \
	Catalyst::Manual::Plugins.3 \
	Catalyst::Manual::SuccessStories.3 \
	Catalyst::Manual::Troubleshooting.3 \
	Catalyst::Manual::Tutorial.3 \
	Catalyst::Request.3 \
	Catalyst::Request::Upload.3 \
	Catalyst::Response.3 \
	Catalyst::Setup.3 \
	Catalyst::Test.3 \
	Catalyst::Utils.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500801
IGNORE=	requires at least Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
