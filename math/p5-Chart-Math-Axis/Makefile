# New ports collection makefile for:	Chart-Math-Axis
# Date created:	   18 May 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Chart-Math-Axis
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	math graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Chart
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Implements an algorithm to find good values for chart axis

BUILD_DEPENDS=	${SITE_PERL}/Math/BigInt.pm:${PORTSDIR}/math/p5-Math-BigInt \
		${SITE_PERL}/Math/BigFloat.pm:${PORTSDIR}/math/p5-Math-BigInt \
		${SITE_PERL}/${PERL_ARCH}/Clone.pm:${PORTSDIR}/devel/p5-Clone
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Chart::Math::Axis.3

.include <bsd.port.mk>
