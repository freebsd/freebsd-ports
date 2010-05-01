# New ports collection makefile for:	Dancer
# Date created:		16 Apr 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Dancer
PORTVERSION=	1.176
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/X/XS/XSAWYERX
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for minimal-effort oriented web application framework

RUN_DEPENDS=	\
	p5-HTTP-Body>0:${PORTSDIR}/www/p5-HTTP-Body \
	p5-HTTP-Server-Simple-PSGI>=0.11:${PORTSDIR}/www/p5-HTTP-Server-Simple-PSGI \
	p5-MIME-Types>0:${PORTSDIR}/mail/p5-MIME-Types \
	p5-URI>0:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	dancer.1
MAN3=	Dancer.3 \
	Dancer::Config.3 \
	Dancer::Cookbook.3 \
	Dancer::Cookie.3 \
	Dancer::Deployment.3 \
	Dancer::Engine.3 \
	Dancer::Error.3 \
	Dancer::FileUtils.3 \
	Dancer::HTTP.3 \
	Dancer::Logger.3 \
	Dancer::ModuleLoader.3 \
	Dancer::Plugin.3 \
	Dancer::Request.3 \
	Dancer::Request::Upload.3 \
	Dancer::Route::Cache.3 \
	Dancer::Serializer.3 \
	Dancer::Serializer::JSON.3 \
	Dancer::Serializer::Mutable.3 \
	Dancer::Serializer::YAML.3 \
	Dancer::Session.3 \
	Dancer::Session::Abstract.3 \
	Dancer::Session::Simple.3 \
	Dancer::Session::YAML.3 \
	Dancer::Template.3 \
	Dancer::Template::Abstract.3 \
	Dancer::Template::Simple.3 \
	Dancer::Template::TemplateToolkit.3

.include <bsd.port.mk>
