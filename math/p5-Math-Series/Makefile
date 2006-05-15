# New ports collection makefile for:	Math-Series
# Date created:				15 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Series
PORTVERSION=	1.01
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Perl extension dealing with mathematic series

BUILD_DEPENDS=	${SITE_PERL}/Math/Symbolic.pm:${PORTSDIR}/math/p5-Math-Symbolic \
		${SITE_PERL}/Math/Sequence.pm:${PORTSDIR}/math/p5-Math-Sequence
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Math::Series.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
