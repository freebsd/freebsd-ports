# New ports collection makefile for:	Math-FixedPrecision
# Date created:				Wed Jan  3 11:03:30 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Math-FixedPrecision
PORTVERSION=	0.21
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module that provides decimal math without floating point errors

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BROKEN=		"Needs Perl 5.6.0 for Math::BigFloat"
.endif

PERL_CONFIGURE=	yes

MAN3=		Math::FixedPrecision.3

.include <bsd.port.post.mk>
