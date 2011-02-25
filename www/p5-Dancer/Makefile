# New ports collection makefile for:	Dancer
# Date created:		16 Apr 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Dancer
PORTVERSION=	1.3011
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/S/SU/SUKRIA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for minimal-effort oriented web application framework

RUN_DEPENDS=	\
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-HTTP-Body>=1.07:${PORTSDIR}/www/p5-HTTP-Body \
	p5-HTTP-Server-Simple-PSGI>=0.11:${PORTSDIR}/www/p5-HTTP-Server-Simple-PSGI \
	p5-MIME-Types>0:${PORTSDIR}/mail/p5-MIME-Types \
	p5-URI>0:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}

OPTIONS=	YAML "Enable YAML implementation in Perl" On

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

.include <bsd.port.options.mk>

.if defined(WITH_YAML)
RUN_DEPENDS+=	p5-YAML>=0.71:${PORTSDIR}/textproc/p5-YAML
.endif

PERL_CONFIGURE=	yes

MAN1=	dancer.1
MAN3=	Dancer.3 \
	Dancer::Config.3 \
	Dancer::Cookbook.3 \
	Dancer::Cookie.3 \
	Dancer::Cookies.3 \
	Dancer::Deployment.3 \
	Dancer::Development.3 \
	Dancer::Development::Integration.3 \
	Dancer::Engine.3 \
	Dancer::Error.3 \
	Dancer::FileUtils.3 \
	Dancer::HTTP.3 \
	Dancer::Handler::Debug.3 \
	Dancer::Introduction.3 \
	Dancer::Logger.3 \
	Dancer::Logger::Abstract.3 \
	Dancer::Logger::Console.3 \
	Dancer::Logger::File.3 \
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
