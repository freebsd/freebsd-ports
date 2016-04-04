# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Template-Plugin-Filter-Minify-CSS-XS
PORTVERSION=	0.96
PORTREVISION=	1
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CSS::Minifier::XS filter for Template Toolkit

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CSS-Minifier-XS>=0:textproc/p5-CSS-Minifier-XS \
		p5-Template-Toolkit>=2:www/p5-Template-Toolkit
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
