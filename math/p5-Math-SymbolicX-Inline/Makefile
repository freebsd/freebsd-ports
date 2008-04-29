# New ports collection makefile for:	Math-SymbolicX-Inline
# Date created:				15 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-SymbolicX-Inline
PORTVERSION=	1.11
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Inlined Math::Symbolic functions

BUILD_DEPENDS=	${SITE_PERL}/Math/Symbolic.pm:${PORTSDIR}/math/p5-Math-Symbolic \
		${SITE_PERL}/Math/Symbolic/Custom/Contains.pm:${PORTSDIR}/math/p5-Math-Symbolic-Custom-Contains
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Math::SymbolicX::Inline.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
