# New ports collection makefile for:	p5-Math-Polynomial-Solve
# Date created:		2006-10-23
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Polynomial-Solve
PORTVERSION=	2.10
CATEGORIES=	math
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Find the roots of polynomial equations

PERL_CONFIGURE=	yes

MAN3=		Math::Polynomial::Solve.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires Perl 5.6.0 or newer. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
