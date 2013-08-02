# New ports collection makefile for:	Math-Geometry-Planar
# Date created:				21 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Geometry-Planar
PORTVERSION=	1.18
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTFILES=	Math-Geometry-Planar-1.18-withoutworldwriteables.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of planar geometry functions

BUILD_DEPENDS=	p5-Math-Geometry-Planar-GPC>=0:${PORTSDIR}/math/p5-Math-Geometry-Planar-GPC \
		p5-Math-Geometry-Planar-Offset>=0:${PORTSDIR}/math/p5-Math-Geometry-Planar-Offset
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	Math::Geometry::Planar.3

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
