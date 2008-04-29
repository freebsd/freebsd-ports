# New ports collection makefile for:	Math-Geometry-Planar-Offset
# Date created:				21 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Geometry-Planar-Offset
PORTVERSION=	1.05
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Calculate offset polygons

BUILD_DEPENDS=	${SITE_PERL}/Test/YAML.pm:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Math::Geometry::Planar::Offset.3

PERL_MODBUILD=	yes

.include <bsd.port.mk>
