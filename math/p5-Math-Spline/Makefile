# vim:ts=8
# New ports collection makefile for:	p5-Math-Spline
# Date created:				25 November 2004
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	Math-Spline
PORTVERSION=	0.01
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Cubic Spline Interpolation of data

RUN_DEPENDS=	${SITE_PERL}/Math/Derivative.pm:${PORTSDIR}/math/p5-Math-Derivative

PERL_CONFIGURE=	yes

MAN3=		Math::Spline.3

.include <bsd.port.mk>
