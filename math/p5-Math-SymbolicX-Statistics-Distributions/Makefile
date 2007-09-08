# New ports collection makefile for:	Math-SymbolicX-Statistics-Distributions
# Date created:				15 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-SymbolicX-Statistics-Distributions
PORTVERSION=	1.02
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Statistical distributions

BUILD_DEPENDS=	${SITE_PERL}/Math/Symbolic.pm:${PORTSDIR}/math/p5-Math-Symbolic \
		${SITE_PERL}/Math/SymbolicX/ParserExtensionFactory.pm:${PORTSDIR}/math/p5-Math-SymbolicX-ParserExtensionFactory
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Math::SymbolicX::Statistics::Distributions.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
