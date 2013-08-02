# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Perlanet
PORTVERSION=	0.56
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAVECROSS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Program for creating programs that aggregate web feeds

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CHI>=0:${PORTSDIR}/devel/p5-CHI \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-HTML-Tidy>=0:${PORTSDIR}/textproc/p5-HTML-Tidy \
		p5-HTML-Scrubber>=0:${PORTSDIR}/www/p5-HTML-Scrubber \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-ConfigFromFile>=0:${PORTSDIR}/devel/p5-MooseX-ConfigFromFile \
		p5-MooseX-Traits>=0:${PORTSDIR}/devel/p5-MooseX-Traits \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-Feed>=0.22:${PORTSDIR}/textproc/p5-XML-Feed \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN1=		perlanet.1
MAN3=		Perlanet.3 \
		Perlanet::Entry.3 \
		Perlanet::Feed.3 \
		Perlanet::Simple.3 \
		Perlanet::Trait::Cache.3 \
		Perlanet::Trait::FeedFile.3 \
		Perlanet::Trait::OPML.3 \
		Perlanet::Trait::Scrubber.3 \
		Perlanet::Trait::TemplateToolkit.3 \
		Perlanet::Trait::Tidy.3 \
		Perlanet::Trait::YAMLConfig.3

.include <bsd.port.mk>
