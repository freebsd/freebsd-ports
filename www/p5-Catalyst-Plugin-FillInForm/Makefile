# Created by: Travis Campbell <hcoyote@ghostar.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-FillInForm
PORTVERSION=	0.12
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Automatically fill in forms in Catalyst using HTML::FillInForms

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-HTML-FillInForm>=0:${PORTSDIR}/www/p5-HTML-FillInForm \
		p5-Catalyst-Action-RenderView>=0:${PORTSDIR}/www/p5-Catalyst-Action-RenderView
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
