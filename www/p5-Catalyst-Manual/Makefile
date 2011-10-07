# Ports collection makefile for:	www/p5-Catalyst-Manual
# Date created:				Janyary 5, 2007
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Manual
PORTVERSION=	5.9002
PORTEPOCH=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The Catalyst developer\'s manual

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Manual.3 \
		Catalyst::Manual::About.3 \
		Catalyst::Manual::Actions.3 \
		Catalyst::Manual::CatalystAndMoose.3 \
		Catalyst::Manual::Components.3 \
		Catalyst::Manual::Cookbook.3 \
		Catalyst::Manual::Deployment.3 \
		Catalyst::Manual::Deployment::Apache::FastCGI.3 \
		Catalyst::Manual::Deployment::Apache::mod_perl.3 \
		Catalyst::Manual::Deployment::DevelopmentServer.3 \
		Catalyst::Manual::Deployment::FastCGI.3 \
		Catalyst::Manual::Deployment::IIS::FastCGI.3 \
		Catalyst::Manual::Deployment::SharedHosting.3 \
		Catalyst::Manual::Deployment::lighttpd::FastCGI.3 \
		Catalyst::Manual::Deployment::nginx::FastCGI.3 \
		Catalyst::Manual::DevelopmentProcess.3 \
		Catalyst::Manual::ExtendingCatalyst.3 \
		Catalyst::Manual::Internals.3 \
		Catalyst::Manual::Intro.3 \
		Catalyst::Manual::Plugins.3 \
		Catalyst::Manual::Tutorial.3 \
		Catalyst::Manual::Tutorial::01_Intro.3 \
		Catalyst::Manual::Tutorial::02_CatalystBasics.3 \
		Catalyst::Manual::Tutorial::03_MoreCatalystBasics.3 \
		Catalyst::Manual::Tutorial::04_BasicCRUD.3 \
		Catalyst::Manual::Tutorial::05_Authentication.3 \
		Catalyst::Manual::Tutorial::06_Authorization.3 \
		Catalyst::Manual::Tutorial::07_Debugging.3 \
		Catalyst::Manual::Tutorial::08_Testing.3 \
		Catalyst::Manual::Tutorial::09_AdvancedCRUD.3 \
		Catalyst::Manual::Tutorial::09_AdvancedCRUD::09_FormBuilder.3 \
		Catalyst::Manual::Tutorial::09_AdvancedCRUD::09_FormFu.3 \
		Catalyst::Manual::Tutorial::09_AdvancedCRUD::09_FormHandler.3 \
		Catalyst::Manual::Tutorial::10_Appendices.3 \
		Catalyst::Manual::WritingPlugins.3

post-extract:
	@${RM} ${WRKSRC}/lib/Catalyst/Manual/Tutorial/.gitignore

.include <bsd.port.mk>
