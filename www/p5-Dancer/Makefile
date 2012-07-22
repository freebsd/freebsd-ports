# New ports collection makefile for:	Dancer
# Date created:		16 Apr 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Dancer
PORTVERSION=	1.3097
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:XSAWYERX
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for minimal-effort oriented web application framework

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-HTTP-Body>=1.07:${PORTSDIR}/www/p5-HTTP-Body \
	p5-HTTP-Server-Simple-PSGI>=0.11:${PORTSDIR}/www/p5-HTTP-Server-Simple-PSGI \
	p5-MIME-Types>0:${PORTSDIR}/mail/p5-MIME-Types \
	p5-URI>=1.59:${PORTSDIR}/net/p5-URI \
	p5-Try-Tiny>=0.09:${PORTSDIR}/lang/p5-Try-Tiny
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Clone>0:${PORTSDIR}/devel/p5-Clone \
	p5-Test-TCP>0:${PORTSDIR}/devel/p5-Test-TCP \
	p5-JSON>0:${PORTSDIR}/converters/p5-JSON \
	p5-YAML>0:${PORTSDIR}/textproc/p5-YAML \
	p5-Plack>0:${PORTSDIR}/www/p5-Plack \
	p5-XML-Simple>0:${PORTSDIR}/textproc/p5-XML-Simple \
	p5-HTTP-Parser-XS>0:${PORTSDIR}/www/p5-HTTP-Parser-XS \
	p5-Template-Toolkit>0:${PORTSDIR}/www/p5-Template-Toolkit \
	p5-Test-Output>0:${PORTSDIR}/devel/p5-Test-Output

OPTIONS_DEFINE=	YAML

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MYAML}
RUN_DEPENDS+=	p5-YAML>=0.71:${PORTSDIR}/textproc/p5-YAML
.endif

PERL_CONFIGURE=	yes

MAN1=	dancer.1
MAN3=	Dancer.3 \
	Dancer::Config.3 \
	Dancer::Config::Object.3 \
	Dancer::Cookbook.3 \
	Dancer::Cookie.3 \
	Dancer::Cookies.3 \
	Dancer::Deployment.3 \
	Dancer::Deprecation.3 \
	Dancer::Development.3 \
	Dancer::Development::Integration.3 \
	Dancer::Engine.3 \
	Dancer::Error.3 \
	Dancer::Exception.3 \
	Dancer::Exception::Base.3 \
	Dancer::FileUtils.3 \
	Dancer::HTTP.3 \
	Dancer::Handler::Debug.3 \
	Dancer::Handler::PSGI.3 \
	Dancer::Hook.3 \
	Dancer::Hook::Properties.3 \
	Dancer::Introduction.3 \
	Dancer::Logger.3 \
	Dancer::Logger::Abstract.3 \
	Dancer::Logger::Capture.3 \
	Dancer::Logger::Capture::Trap.3 \
	Dancer::Logger::Console.3 \
	Dancer::Logger::Diag.3 \
	Dancer::Logger::File.3 \
	Dancer::Logger::Note.3 \
	Dancer::Logger::Null.3 \
	Dancer::MIME.3 \
	Dancer::ModuleLoader.3 \
	Dancer::Object.3 \
	Dancer::Object::Singleton.3 \
	Dancer::Plugin.3 \
	Dancer::Plugin::Ajax.3 \
	Dancer::Plugins.3 \
	Dancer::Request.3 \
	Dancer::Request::Upload.3 \
	Dancer::Response.3 \
	Dancer::Route::Cache.3 \
	Dancer::Serializer.3 \
	Dancer::Serializer::JSON.3 \
	Dancer::Serializer::Mutable.3 \
	Dancer::Serializer::XML.3 \
	Dancer::Serializer::YAML.3 \
	Dancer::Session.3 \
	Dancer::Session::Abstract.3 \
	Dancer::Session::Simple.3 \
	Dancer::Session::YAML.3 \
	Dancer::Template.3 \
	Dancer::Template::Abstract.3 \
	Dancer::Template::Simple.3 \
	Dancer::Template::TemplateToolkit.3 \
	Dancer::Test.3 \
	Dancer::Timer.3 \
	Dancer::Tutorial.3

.include <bsd.port.mk>
