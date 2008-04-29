# New ports collection makefile for:	Math-Symbolic-Custom-Pattern
# Date created:				15 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Symbolic-Custom-Pattern
PORTVERSION=	2.00
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pattern matching on Math::Symbolic trees

BUILD_DEPENDS=	p5-Math-Symbolic>=0.510:${PORTSDIR}/math/p5-Math-Symbolic \
		p5-Test-Pod>=1.0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.0:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		${SITE_PERL}/${PERL_ARCH}/Clone.pm:${PORTSDIR}/devel/p5-Clone
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Math::Symbolic::Custom::Pattern.3 \
	Math::Symbolic::Custom::Pattern::Export.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
