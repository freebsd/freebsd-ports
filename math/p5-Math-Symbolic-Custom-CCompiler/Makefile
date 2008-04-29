# New ports collection makefile for:	Math-Symbolic-Custom-CCompiler
# Date created:				15 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Symbolic-Custom-CCompiler
PORTVERSION=	1.02
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compile Math::Symbolic trees to C

BUILD_DEPENDS=	p5-Math-Symbolic>=0.509:${PORTSDIR}/math/p5-Math-Symbolic \
		p5-Inline>=0.44:${PORTSDIR}/devel/p5-Inline
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Math::Symbolic::Custom::CCompiler.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
