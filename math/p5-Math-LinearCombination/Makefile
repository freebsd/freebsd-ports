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

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/fields.pm:${PORTSDIR}/devel/p5-Class-Fields \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Math/SimpleVariable.pm:${PORTSDIR}/math/p5-Math-SimpleVariable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Math::LinearCombination.3

pre-patch:
	@${FIND} ${WRKSRC} -name "*.pm" | xargs ${PERL} -pi -e \
		's!^require 5.005_62;!!; s!^use warnings;!!; s!^our\s+!my !;'

.include <bsd.port.mk>
