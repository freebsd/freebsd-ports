# New ports collection makefile for:	Math::LinearCombination
# Date created:		5 Nov 2001
# Whom:			Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-LinearCombination
PORTVERSION=	0.03
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Sum of variables with a numerical coefficient

BUILD_DEPENDS=	${SITE_PERL}/fields.pm:${PORTSDIR}/devel/p5-Class-Fields \
		${SITE_PERL}/Math/SimpleVariable.pm:${PORTSDIR}/math/p5-Math-SimpleVariable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Math::LinearCombination.3

pre-patch:
	@${FIND} ${WRKSRC} -name "*.pm" | ${XARGS} ${PERL} -pi -e \
		's!^require 5.005_62;!!; s!^use warnings;!!; s!^our\s+!my !;'

.include <bsd.port.mk>
