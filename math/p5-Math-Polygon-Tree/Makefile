# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-Polygon-Tree
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LIOSHA
PKGNAMEPREFIX=	p5-

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Class for fast check if point is inside polygon

BUILD_DEPENDS=	p5-Test-Simple>=0:devel/p5-Test-Simple \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Math-Geometry-Planar-GPC-PolygonXS>=0:math/p5-Math-Geometry-Planar-GPC-PolygonXS
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS:=	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
