# New ports collection makefile for:	p5-Math-RandomOrg
# Date created:				29 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-RandomOrg
PORTVERSION=	0.04
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Retrieve random numbers and data from random.org

BUILD_DEPENDS=	${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Math/BigInt.pm:${PORTSDIR}/math/p5-Math-BigInt
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Math::RandomOrg.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
