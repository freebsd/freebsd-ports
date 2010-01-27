# New ports collection makefile for:	CAD-Calc
# Date created:				21 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CAD-Calc
PORTVERSION=	0.27
PORTREVISION=	1
CATEGORIES=	math graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic cad-related geometry calculations

BUILD_DEPENDS=	${SITE_PERL}/Math/Vec.pm:${PORTSDIR}/math/p5-Math-Vec \
		${SITE_PERL}/Math/Round/Var.pm:${PORTSDIR}/math/p5-Math-Round-Var \
		${SITE_PERL}/Math/Geometry/Planar/Offset.pm:${PORTSDIR}/math/p5-Math-Geometry-Planar-Offset
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	CAD::Calc.3

PERL_MODBUILD=	yes

.include <bsd.port.mk>
