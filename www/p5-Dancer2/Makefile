# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Dancer2
PORTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Lightweight yet powerful web application framework

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Capture-Tiny>=0.12:${PORTSDIR}/devel/p5-Capture-Tiny \
	p5-Crypt-URandom>0:${PORTSDIR}/security/p5-Crypt-URandom \
	p5-Config-Any>=0:${PORTSDIR}/devel/p5-Config-Any \
	p5-Digest-SHA>=0:${PORTSDIR}/security/p5-Digest-SHA \
	p5-Hash-Merge-Simple>=0:${PORTSDIR}/devel/p5-Hash-Merge-Simple \
	p5-HTTP-Body>=0:${PORTSDIR}/www/p5-HTTP-Body \
	p5-HTTP-Date>=0:${PORTSDIR}/www/p5-HTTP-Date \
	p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
	p5-HTTP-Server-Simple-PSGI>=0:${PORTSDIR}/www/p5-HTTP-Server-Simple-PSGI \
	p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
	p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64 \
	p5-MIME-Types>=0:${PORTSDIR}/mail/p5-MIME-Types \
	p5-Moo>=0.09014:${PORTSDIR}/devel/p5-Moo \
	p5-MooX-Types-MooseLike-Numeric>=0:${PORTSDIR}/devel/p5-MooX-Types-MooseLike-Numeric \
	p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
	p5-Plack>=0:${PORTSDIR}/www/p5-Plack \
	p5-Template-Tiny>=0:${PORTSDIR}/textproc/p5-Template-Tiny \
	p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
	p5-URI-Escape-XS>=0:${PORTSDIR}/www/p5-URI-Escape-XS \
	p5-YAML>=0.71:${PORTSDIR}/textproc/p5-YAML \
	p5-YAML-LibYAML>=0:${PORTSDIR}/textproc/p5-YAML-LibYAML \
	p5-libwww>=0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-MockTime>=0:${PORTSDIR}/devel/p5-Test-MockTime \
	p5-Test-Fatal>0:${PORTSDIR}/devel/p5-Test-Fatal \
	p5-Test-TCP>0:${PORTSDIR}/devel/p5-Test-TCP \

USES=		perl5
USE_PERL5=	configure

MAN1=	dancer2.1
MAN3=	Dancer2.3 \
	Dancer2::Config.3 \
	Dancer2::Cookbook.3 \
	Dancer2::Core.3 \
	Dancer2::Core::App.3 \
	Dancer2::Core::Context.3 \
	Dancer2::Core::Cookie.3 \
	Dancer2::Core::DSL.3 \
	Dancer2::Core::Dispatcher.3 \
	Dancer2::Core::Error.3 \
	Dancer2::Core::Factory.3 \
	Dancer2::Core::HTTP.3 \
	Dancer2::Core::Hook.3 \
	Dancer2::Core::MIME.3 \
	Dancer2::Core::Request.3 \
	Dancer2::Core::Request::Upload.3 \
	Dancer2::Core::Response.3 \
	Dancer2::Core::Role::Config.3 \
	Dancer2::Core::Role::DSL.3 \
	Dancer2::Core::Role::Engine.3 \
	Dancer2::Core::Role::Handler.3 \
	Dancer2::Core::Role::Headers.3 \
	Dancer2::Core::Role::Hookable.3 \
	Dancer2::Core::Role::Logger.3 \
	Dancer2::Core::Role::Serializer.3 \
	Dancer2::Core::Role::Server.3 \
	Dancer2::Core::Role::SessionFactory.3 \
	Dancer2::Core::Role::SessionFactory::File.3 \
	Dancer2::Core::Role::StandardResponses.3 \
	Dancer2::Core::Role::Template.3 \
	Dancer2::Core::Route.3 \
	Dancer2::Core::Runner.3 \
	Dancer2::Core::Server::PSGI.3 \
	Dancer2::Core::Server::Standalone.3 \
	Dancer2::Core::Session.3 \
	Dancer2::Core::Time.3 \
	Dancer2::Core::Types.3 \
	Dancer2::FileUtils.3 \
	Dancer2::Handler::AutoPage.3 \
	Dancer2::Handler::File.3 \
	Dancer2::Logger::Capture.3 \
	Dancer2::Logger::Capture::Trap.3 \
	Dancer2::Logger::Console.3 \
	Dancer2::Logger::Diag.3 \
	Dancer2::Logger::File.3 \
	Dancer2::Logger::Note.3 \
	Dancer2::Logger::Null.3 \
	Dancer2::Manual.3 \
	Dancer2::ModuleLoader.3 \
	Dancer2::Plugin.3 \
	Dancer2::Plugin::Ajax.3 \
	Dancer2::Plugins.3 \
	Dancer2::Serializer::Dumper.3 \
	Dancer2::Serializer::JSON.3 \
	Dancer2::Serializer::YAML.3 \
	Dancer2::Session::Simple.3 \
	Dancer2::Session::YAML.3 \
	Dancer2::Template::Implementation::ForkedTiny.3 \
	Dancer2::Template::Simple.3 \
	Dancer2::Template::TemplateToolkit.3 \
	Dancer2::Template::Tiny.3 \
	Dancer2::Test.3 \
	Dancer2::Tutorial.3

.include <bsd.port.mk>
