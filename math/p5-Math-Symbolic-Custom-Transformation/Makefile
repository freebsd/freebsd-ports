# New ports collection makefile for:	Math-Symbolic-Custom-Transformation
# Date created:				15 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Symbolic-Custom-Transformation
PORTVERSION=	2.00
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Transform Math::Symbolic trees

BUILD_DEPENDS=	p5-Math-Symbolic>=0.163:${PORTSDIR}/math/p5-Math-Symbolic \
		p5-Math-Symbolic-Custom-Pattern>=1.21:${PORTSDIR}/math/p5-Math-Symbolic-Custom-Pattern
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Math::Symbolic::Custom::Transformation.3 \
	Math::Symbolic::Custom::Transformation::Group.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
