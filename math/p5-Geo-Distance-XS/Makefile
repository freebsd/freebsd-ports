# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Geo-Distance-XS
PORTVERSION=	0.13
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Calculate Distances and Closest Locations faster

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Geo-Distance>=0.16:math/p5-Geo-Distance

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Geo/Distance/XS/XS.so

.include <bsd.port.mk>
