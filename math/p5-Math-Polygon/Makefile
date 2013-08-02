# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Math-Polygon
PORTVERSION=	1.02
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Class for Maintaining Polygon Data

BUILD_DEPENDS=	p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Math::Polygon.3 \
		Math::Polygon::Calc.3 \
		Math::Polygon::Clip.3 \
		Math::Polygon::Surface.3 \
		Math::Polygon::Transform.3 \
		Math::Polygon::Convex.3

.include <bsd.port.mk>
