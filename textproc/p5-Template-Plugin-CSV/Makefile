# Created by: Geoffroy Desvernay <dgeo@centrale-marseille.fr>
# $FreeBSD$

PORTNAME=	Template-Plugin-CSV
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GUGOD
PKGNAMEPREFIX=	p5-

MAINTAINER=	dgeo@centrale-marseille.fr
COMMENT=	Simple TT2 plugin for generating CSV

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Template-Toolkit>0:www/p5-Template-Toolkit \
		p5-Text-CSV>=0:textproc/p5-Text-CSV

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
