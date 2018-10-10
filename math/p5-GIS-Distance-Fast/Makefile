# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	GIS-Distance-Fast
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BLUEFEET
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	C implementation of GIS::Distance formulas

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Measure>=0:devel/p5-Class-Measure \
		p5-GIS-Distance>=0.09:math/p5-GIS-Distance \
		p5-Moo>=1:devel/p5-Moo \
		p5-namespace-clean>=0:devel/p5-namespace-clean \
		p5-strictures>=1:devel/p5-strictures

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
