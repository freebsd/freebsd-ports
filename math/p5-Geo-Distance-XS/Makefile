# New ports collection makefile for:	math/p5-Geo-Distance-XS
# Date created:				30 September 2009
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Geo-Distance-XS
PORTVERSION=	0.11
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Calculate Distances and Closest Locations faster

BUILD_DEPENDS=	p5-Geo-Distance>=0.16:${PORTSDIR}/math/p5-Geo-Distance
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0.94:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=	Geo::Distance::XS.3

.include <bsd.port.mk>
