# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CAD-Calc
PORTVERSION=	0.27
PORTREVISION=	1
CATEGORIES=	math graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic cad-related geometry calculations

BUILD_DEPENDS=	p5-Math-Vec>=0:${PORTSDIR}/math/p5-Math-Vec \
		p5-Math-Round-Var>=0:${PORTSDIR}/math/p5-Math-Round-Var \
		p5-Math-Geometry-Planar-Offset>=0:${PORTSDIR}/math/p5-Math-Geometry-Planar-Offset
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
