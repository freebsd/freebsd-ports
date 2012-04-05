# New ports collection makefile for:	p5-Geo-Distance
# Date created:				10 July 2004
# Whom:	      				Rod Taylor <ports@rbt.ca>
#
# $FreeBSD$
#

PORTNAME=	Geo-Distance
PORTVERSION=	0.19
CATEGORIES=	math perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Calculate Distances and Closest Locations

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Fatal>=0.007:${PORTSDIR}/devel/p5-Test-Fatal

PERL_CONFIGURE=	yes

MAN3=		Geo::Distance.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501200
TEST_DEPENDS+=	p5-Test-Simple>=0.94:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
