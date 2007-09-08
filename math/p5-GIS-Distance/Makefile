# New ports collection makefile for:	p5-GIS-Distance
# Date created:		2006-10-23
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	GIS-Distance
PORTVERSION=	0.01001
CATEGORIES=	math
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/B/BL/BLUEFEET
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Calculate geographic distances

RUN_DEPENDS=	${SITE_PERL}/Class/Data/Accessor.pm:${PORTSDIR}/devel/p5-Class-Data-Accessor \
		${SITE_PERL}/Class/Measure.pm:${PORTSDIR}/devel/p5-Class-Measure

PERL_CONFIGURE=	yes

MAN3=		GIS::Distance.3 GIS::Distance::Cosine.3 \
		GIS::Distance::GeoEllipsoid.3 GIS::Distance::GreatCircle.3 \
		GIS::Distance::Haversine.3 GIS::Distance::MathTrig.3 \
		GIS::Distance::Polar.3 GIS::Distance::Vincenty.3

.include <bsd.port.mk>
