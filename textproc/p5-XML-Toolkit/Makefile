# New ports collection makefile for:	p5-XML-Toolkit
# Date created:		2011-05-30
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Toolkit
PORTVERSION=	0.15
CATEGORIES=	textproc
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PERIGRIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A suit of XML tools with Antlers

BUILD_DEPENDS=	p5-Bread-Board>=0:${PORTSDIR}/devel/p5-Bread-Board \
		p5-Devel-PackagePath>=0.01:${PORTSDIR}/devel/p5-Devel-PackagePath \
		p5-Moose>=0.92:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Aliases>=0:${PORTSDIR}/devel/p5-MooseX-Aliases \
		p5-MooseX-App-Cmd>=0:${PORTSDIR}/devel/p5-MooseX-App-Cmd \
		p5-MooseX-Getopt>=0:${PORTSDIR}/devel/p5-MooseX-Getopt \
		p5-MooseX-MetaDescription>=0:${PORTSDIR}/devel/p5-MooseX-MetaDescription \
		p5-MooseX-NonMoose>=0:${PORTSDIR}/devel/p5-MooseX-NonMoose \
		p5-MooseX-Types-Path-Class>=0:${PORTSDIR}/devel/p5-MooseX-Types-Path-Class \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-XML-SAX>=0.96:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-XML-SAX-Writer>=0:${PORTSDIR}/textproc/p5-XML-SAX-Writer \
		p5-aliased>=0:${PORTSDIR}/devel/p5-aliased \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
#		p5-XML-SAX-Base>=0:${PORTSDIR}/textproc/p5-XML-SAX-Base

TEST_DEPENDS=	p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-XML>=0:${PORTSDIR}/devel/p5-Test-XML

USE_PERL5=	configure
USES=		perl5

MAN3=		XML::Filter::Moose.3 \
		XML::Generator::Moose.3 \
		XML::Toolkit.3 \
		XML::Toolkit::App.3 \
		XML::Toolkit::Builder.3 \
		XML::Toolkit::Builder::ClassRegistry.3 \
		XML::Toolkit::Builder::ClassTemplate.3 \
		XML::Toolkit::Builder::Filter.3 \
		XML::Toolkit::Cmd::Command::generate.3 \
		XML::Toolkit::Cmd::Command::validate.3 \
		XML::Toolkit::Generator.3 \
		XML::Toolkit::Generator::Default.3 \
		XML::Toolkit::Generator::Interface.3 \
		XML::Toolkit::Loader.3 \
		XML::Toolkit::Loader::Filter.3 \
		XML::Toolkit::MetaDescription.3 \
		XML::Toolkit::MetaDescription::Attribute.3 \
		XML::Toolkit::MetaDescription::Trait.3 \
		XML::Toolkit::Trait::NoXML.3

.include <bsd.port.mk>
