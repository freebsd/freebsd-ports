# New ports collection makefile for:	Math-Geometry-Planar
# Date created:				21 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Geometry-Planar
PORTVERSION=	1.16
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	A collection of planar geometry functions

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Math/Geometry/Planar/GPC.pm:${PORTSDIR}/math/p5-Math-Geometry-Planar-GPC \
		${SITE_PERL}/Math/Geometry/Planar/Offset.pm:${PORTSDIR}/math/p5-Math-Geometry-Planar-Offset
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Math::Geometry::Planar.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl 5.6.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
