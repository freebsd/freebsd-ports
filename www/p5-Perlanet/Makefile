# New ports collection makefile for:	p5-Perlanet
# Date created:		2010-12-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Perlanet
PORTVERSION=	0.53
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DA/DAVECROSS
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	A program for creating programs that aggregate web feeds

RUN_DEPENDS=	p5-CHI>=0:${PORTSDIR}/devel/p5-CHI \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-HTML-Tidy>=0:${PORTSDIR}/textproc/p5-HTML-Tidy \
		p5-HTML-Scrubber>=0:${PORTSDIR}/www/p5-HTML-Scrubber \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-ConfigFromFile>=0:${PORTSDIR}/devel/p5-MooseX-ConfigFromFile \
		p5-MooseX-Traits>=0:${PORTSDIR}/devel/p5-MooseX-Traits \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-TryCatch>=0:${PORTSDIR}/lang/p5-TryCatch \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-Feed>=0:${PORTSDIR}/textproc/p5-XML-Feed \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML

PERL_MODBUILD=	yes

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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 508000
RUN_DEPENDS+=	p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
