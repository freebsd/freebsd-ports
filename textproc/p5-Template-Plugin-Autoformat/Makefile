# Created by: Vivek Khera <vivek@khera.org>
# $FreeBSD$

PORTNAME=	Template-Plugin-Autoformat
PORTVERSION=	2.77
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	Template Toolkit interface to Text::Autoformat module

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Template-Toolkit>=2.22:www/p5-Template-Toolkit \
		p5-Text-Autoformat>0:textproc/p5-Text-Autoformat
BUILD_DEPENDS=	p5-Template-Toolkit>=2.22:www/p5-Template-Toolkit \
		p5-Text-Autoformat>0:textproc/p5-Text-Autoformat

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
