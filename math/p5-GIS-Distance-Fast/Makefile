# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	GIS-Distance-Fast
PORTVERSION=	0.07
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BLUEFEET
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	C implementation of GIS::Distance formulas

BUILD_DEPENDS=	p5-GIS-Distance>=0.07:${PORTSDIR}/math/p5-GIS-Distance
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	GIS::Distance::Fast.3 \
	GIS::Distance::Formula::Cosine::Fast.3 \
	GIS::Distance::Formula::Haversine::Fast.3 \
	GIS::Distance::Formula::Vincenty::Fast.3

.include <bsd.port.mk>
