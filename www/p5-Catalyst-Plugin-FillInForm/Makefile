# Ports collection makefile for:	p5-Catalyst-Plugin-FillInForm
# Date created:			May 6, 2005
# Whom:				Travis Campbell <hcoyote@ghostar.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-FillInForm
PORTVERSION=	0.09
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Automatically fill in forms in Catalyst using HTML::FillInForms

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-HTML-FillInForm>=0:${PORTSDIR}/www/p5-HTML-FillInForm
BUILD_DEPENDS=	${RUN_DEPENDS} \
		p5-Catalyst-Action-RenderView>=0:${PORTSDIR}/www/p5-Catalyst-Action-RenderView

PERL_CONFIGURE=	5.8.0+

MAN3=		Catalyst::Plugin::FillInForm.3

.include <bsd.port.mk>
