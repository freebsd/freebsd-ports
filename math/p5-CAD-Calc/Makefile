# New ports collection makefile for:	CAD-Calc
# Date created:				21 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CAD-Calc
PORTVERSION=	0.25
CATEGORIES=	math graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CAD
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Generic cad-related geometry calculations

BUILD_DEPENDS=	${SITE_PERL}/Math/Vec.pm:${PORTSDIR}/math/p5-Math-Vec \
		${SITE_PERL}/Math/Round/Var.pm:${PORTSDIR}/math/p5-Math-Round-Var \
		${SITE_PERL}/Math/BigFloat.pm:${PORTSDIR}/math/p5-Math-BigInt
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	CAD::Calc.3

PERL_MODBUILD=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl 5.6.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
