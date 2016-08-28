# Created by: Danny Warren <danny@dannywarren.com>
# $FreeBSD$

PORTNAME=	CatalystX-AppBuilder
PORTVERSION=	0.00011
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	danny@dannywarren.com
COMMENT=	Programatically build your Catalyst app

LICENSE=	ART10

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.8:www/p5-Catalyst-Runtime \
		p5-Moose>=0:devel/p5-Moose \
		p5-namespace-clean>=0:devel/p5-namespace-clean
BUILD_DEPENDS=	p5-Test-Simple>=0:devel/p5-Test-Simple \
		p5-Module-Build-Tiny>=0.035:devel/p5-Module-Build-Tiny

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
