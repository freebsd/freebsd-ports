# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Perlanet
PORTVERSION=	0.56
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAVECROSS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Program for creating programs that aggregate web feeds

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CHI>=0:devel/p5-CHI \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-HTML-Tidy>=0:textproc/p5-HTML-Tidy \
		p5-HTML-Scrubber>=0:www/p5-HTML-Scrubber \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-ConfigFromFile>=0:devel/p5-MooseX-ConfigFromFile \
		p5-MooseX-Traits>=0:devel/p5-MooseX-Traits \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-URI>=0:net/p5-URI \
		p5-XML-Feed>=0.22:textproc/p5-XML-Feed \
		p5-YAML>=0:textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
