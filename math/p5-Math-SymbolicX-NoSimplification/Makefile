# New ports collection makefile for:	Math-SymbolicX-NoSimplification
# Date created:				15 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-SymbolicX-NoSimplification
PORTVERSION=	0.01
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Turn off Math::Symbolic simplification

BUILD_DEPENDS=	${SITE_PERL}/Math/Symbolic.pm:${PORTSDIR}/math/p5-Math-Symbolic
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Math::SymbolicX::NoSimplification.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl 5.6 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
