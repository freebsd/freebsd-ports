# New ports collection makefile for:	p5-Math-Random-MT-Auto
# Date created:		2006-07-21
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Random-MT-Auto
PORTVERSION=	5.02
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Auto-seeded Mersenne Twister PRNGs

RUN_DEPENDS=	${SITE_PERL}/Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class \
		${SITE_PERL}/Object/InsideOut.pm:${PORTSDIR}/devel/p5-Object-InsideOut

PERL_CONFIGURE=	yes

MAN3=		Math::Random::MT::Auto.3 Math::Random::MT::Auto::Range.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800	# Inherited from p5-Object-InsideOut
IGNORE=		requires perl 5.8 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
