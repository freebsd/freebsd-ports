# New ports collection makefile for:	Math-Symbolic-Custom-Simplification
# Date created:				15 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Symbolic-Custom-Simplification
PORTVERSION=	1.01
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	User defined simplification routines

BUILD_DEPENDS=	p5-Math-Symbolic>=0:${PORTSDIR}/math/p5-Math-Symbolic
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	Math::Symbolic::Custom::Simplification.3

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
