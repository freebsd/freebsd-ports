# New ports collection makefile for:	p5-GIS-Distance
# Date created:		2006-10-23
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	GIS-Distance
PORTVERSION=	0.03
PORTEPOCH=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/B/BL/BLUEFEET
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Calculate geographic distances

RUN_DEPENDS=	${SITE_PERL}/Class/Data/Accessor.pm:${PORTSDIR}/devel/p5-Class-Data-Accessor \
		${SITE_PERL}/Class/Measure.pm:${PORTSDIR}/devel/p5-Class-Measure \
		${SITE_PERL}/Moose.pm:${PORTSDIR}/devel/p5-Moose

PERL_CONFIGURE=	yes

MAN3=		GIS::Distance.3 \
		GIS::Distance::Formula.3 \
		GIS::Distance::Formula::Cosine.3 \
		GIS::Distance::Formula::GeoEllipsoid.3 \
		GIS::Distance::Formula::GreatCircle.3 \
		GIS::Distance::Formula::Haversine.3 \
		GIS::Distance::Formula::MathTrig.3 \
		GIS::Distance::Formula::Polar.3 \
		GIS::Distance::Formula::Vincenty.3

.include <bsd.port.mk>
