# New ports collection makefile for:	Math-Currency
# Date created:				Wed Jan  3 10:58:59 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Math-Currency
PORTVERSION=	0.11
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${SITE_PERL}/Math/FixedPrecision.pm:${PORTSDIR}/math/p5-Math-FixedPrecision
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500007
IGNORE=		"Needs Perl 5.6.0 for Math::BigFloat"
.endif

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Math::Currency.3

.include <bsd.port.post.mk>
