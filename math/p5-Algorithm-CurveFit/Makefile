# New ports collection makefile for:	p5-Algorithm-CurveFit
# Date created:		2006-10-20
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Algorithm-CurveFit
PORTVERSION=	1.05
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Algorithm
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Nonlinear Least Squares Fitting

BUILD_DEPENDS=	p5-MatrixReal>=0:${PORTSDIR}/math/p5-MatrixReal \
		p5-Math-Symbolic>=0:${PORTSDIR}/math/p5-Math-Symbolic
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Algorithm::CurveFit.3

.include <bsd.port.mk>
