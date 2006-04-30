# ex:ts=8
# Ports collection makefile for:	p5-Catalyst
# Date created:			Apr 7, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Catalyst
PORTVERSION=	5.682
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/M/MR/MRAMBERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@balker.dk
COMMENT=	The Elegant MVC Web Application Framework

BUILD_DEPENDS=	p5-UNIVERSAL-require>=0.10:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-Data-Visitor>=0.02:${PORTSDIR}/devel/p5-Data-Visitor \
		p5-CGI.pm>=3.06:${PORTSDIR}/www/p5-CGI.pm \
		p5-File-Modified>=0:${PORTSDIR}/devel/p5-File-Modified \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTTP-Body>=0.5:${PORTSDIR}/www/p5-HTTP-Body \
		p5-libwww>=5.805:${PORTSDIR}/www/p5-libwww \
		p5-HTTP-Request-AsCGI>=0.5:${PORTSDIR}/www/p5-HTTP-Request-AsCGI \
		p5-MIME-Types>=0:${PORTSDIR}/mail/p5-MIME-Types \
		p5-Module-Pluggable-Fast>=0.16:${PORTSDIR}/devel/p5-Module-Pluggable-Fast \
		p5-NEXT>=0:${PORTSDIR}/devel/p5-NEXT \
		p5-Path-Class>=0.09:${PORTSDIR}/devel/p5-Path-Class \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Text-SimpleTable>=0.03:${PORTSDIR}/textproc/p5-Text-SimpleTable \
		p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject \
		p5-Test-NoWarnings>=0.082:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes \
		p5-Tree-Simple>=1.15:${PORTSDIR}/devel/p5-Tree-Simple \
		p5-Tree-Simple-VisitorFactory>=0:${PORTSDIR}/devel/p5-Tree-Simple-VisitorFactory \
		p5-URI>=1.35:${PORTSDIR}/net/p5-URI \
		p5-File-Copy-Recursive>=0:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		p5-Module-Install>=0.54:${PORTSDIR}/devel/p5-Module-Install \
		p5-YAML>=0.55:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	catalyst.pl.1
MAN3=	Catalyst.3 \
	Catalyst::Action.3 \
	Catalyst::ActionContainer.3 \
	Catalyst::AttrContainer.3 \
	Catalyst::Base.3 \
	Catalyst::Build.3 \
	Catalyst::Component.3 \
	Catalyst::Controller.3 \
	Catalyst::DispatchType.3 \
	Catalyst::DispatchType::Default.3 \
	Catalyst::DispatchType::Index.3 \
	Catalyst::DispatchType::Path.3 \
	Catalyst::DispatchType::Regex.3 \
	Catalyst::Dispatcher.3 \
	Catalyst::Engine.3 \
	Catalyst::Engine::CGI.3 \
	Catalyst::Engine::FastCGI.3 \
	Catalyst::Engine::HTTP.3 \
	Catalyst::Engine::HTTP::Restarter.3 \
	Catalyst::Engine::HTTP::Restarter::Watcher.3 \
	Catalyst::Exception.3 \
	Catalyst::Helper.3 \
	Catalyst::Log.3 \
	Catalyst::Manual.3 \
	Catalyst::Manual::About.3 \
	Catalyst::Manual::Cookbook.3 \
	Catalyst::Manual::FAQ.3 \
	Catalyst::Manual::Internals.3 \
	Catalyst::Manual::Intro.3 \
	Catalyst::Manual::Plugins.3 \
	Catalyst::Manual::Tutorial.3 \
	Catalyst::Manual::WritingPlugins.3 \
	Catalyst::Model.3 \
	Catalyst::Plugin::ConfigLoader.3 \
	Catalyst::Plugin::ConfigLoader::YAML.3 \
	Catalyst::Plugin::Static::Simple.3 \
	Catalyst::Request.3 \
	Catalyst::Request::Upload.3 \
	Catalyst::Response.3 \
	Catalyst::Test.3 \
	Catalyst::Utils.3 \
	Catalyst::View.3 \
	Module::Install::Catalyst.3

post-install:
	@${CAT} pkg-message

post-extract:
	@${PERL} -i.bak -ne 'print unless m,^feature, .. m,;$$,' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500801
IGNORE=	requires at least Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
