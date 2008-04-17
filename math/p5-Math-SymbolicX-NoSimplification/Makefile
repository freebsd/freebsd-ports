# New ports collection makefile for:	Math-SymbolicX-NoSimplification
# Date created:				15 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-SymbolicX-NoSimplification
PORTVERSION=	1.01
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Turn off Math::Symbolic simplification

BUILD_DEPENDS=	${SITE_PERL}/Math/Symbolic.pm:${PORTSDIR}/math/p5-Math-Symbolic
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Math::SymbolicX::NoSimplification.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
