# New ports collection makefile for:	p5-Math-RPN
# Date created:		1 June 2010
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-RPN
PORTVERSION=	1.09
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Reverse polish math expression evaluation

RUN_DEPENDS=	${SITE_PERL}/Test/Warn.pm:${PORTSDIR}/devel/p5-Test-Warn \
		p5-ExtUtils-MakeMaker>=6.52:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Math::RPN.3

.include <bsd.port.mk>
