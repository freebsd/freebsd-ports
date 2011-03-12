# New ports collection makefile for:	p5-Math-Polygon-Tree
# Date created:		03 Mar 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Polygon-Tree
PORTVERSION=	0.041
CATEGORIES=	math perl5
MASTER_SITES=	CPAN/../../authors/id/L/LI/LIOSHA
PKGNAMEPREFIX=	p5-

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Class for fast check if point is inside polygon

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/${PERL_ARCH}/List/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/${PERL_ARCH}/List/MoreUtils.pm:${PORTSDIR}/lang/p5-List-MoreUtils \
		${SITE_PERL}/${PERL_ARCH}/Math/Geometry/Planar/GPC/Polygon.pm:${PORTSDIR}/math/p5-Math-Geometry-Planar-GPC-Polygon
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Math::Polygon::Tree.3

.include <bsd.port.mk>
