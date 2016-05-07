# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-Toolkit
PORTVERSION=	0.15
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PERIGRIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Suit of XML tools with Antlers

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Bread-Board>=0:devel/p5-Bread-Board \
		p5-Devel-PackagePath>=0.01:devel/p5-Devel-PackagePath \
		p5-Moose>=0.92:devel/p5-Moose \
		p5-MooseX-Aliases>=0:devel/p5-MooseX-Aliases \
		p5-MooseX-App-Cmd>=0:devel/p5-MooseX-App-Cmd \
		p5-MooseX-Getopt>=0:devel/p5-MooseX-Getopt \
		p5-MooseX-MetaDescription>=0:devel/p5-MooseX-MetaDescription \
		p5-MooseX-NonMoose>=0:devel/p5-MooseX-NonMoose \
		p5-MooseX-Types-Path-Class>=0:devel/p5-MooseX-Types-Path-Class \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-XML-SAX>=0.96:textproc/p5-XML-SAX \
		p5-XML-SAX-Base>=0:textproc/p5-XML-SAX-Base \
		p5-XML-SAX-Writer>=0:textproc/p5-XML-SAX-Writer \
		p5-aliased>=0:devel/p5-aliased \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-XML>=0:devel/p5-Test-XML

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
