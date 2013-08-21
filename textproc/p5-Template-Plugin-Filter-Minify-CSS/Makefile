# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Template-Plugin-Filter-Minify-CSS
PORTVERSION=	0.94
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CSS::Minifier filter for Template Toolkit

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CSS-Minifier>=0:${PORTSDIR}/textproc/p5-CSS-Minifier \
		p5-Module-Signature>=0:${PORTSDIR}/security/p5-Module-Signature \
		p5-Template-Toolkit>=2:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS=	p5-CSS-Minifier>=0:${PORTSDIR}/textproc/p5-CSS-Minifier \
		p5-Template-Toolkit>=2:${PORTSDIR}/www/p5-Template-Toolkit

USE_PERL5=	configure
USES=		perl5

MAN3=		Template::Plugin::Filter::Minify::CSS.3

.include <bsd.port.mk>
