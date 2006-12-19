# New ports collection makefile for:	p5-Algorithm-CurveFit
# Date created:		2006-10-20
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Algorithm-CurveFit
PORTVERSION=	1.03
CATEGORIES=	math
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Algorithm
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Nonlinear Least Squares Fitting

RUN_DEPENDS=	${SITE_PERL}/Math/MatrixReal.pm:${PORTSDIR}/math/p5-MatrixReal \
		${SITE_PERL}/Math/Symbolic.pm:${PORTSDIR}/math/p5-Math-Symbolic

PERL_CONFIGURE=	yes

MAN3=		Algorithm::CurveFit.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600	# inherited from math/p5-Math-Symbolic
IGNORE=		requires 5.6.0 or newer. Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
