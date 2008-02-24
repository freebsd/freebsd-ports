# New ports collection makefile for:	p5-Math-Random-MT-Auto
# Date created:		2006-07-21
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Random-MT-Auto
PORTVERSION=	6.11
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Auto-seeded Mersenne Twister PRNGs

RUN_DEPENDS=	${SITE_PERL}/Object/InsideOut.pm:${PORTSDIR}/devel/p5-Object-InsideOut \
		p5-Exception-Class>=1.22:${PORTSDIR}/devel/p5-Exception-Class

PERL_CONFIGURE=	5.8.0+	# Inherited from p5-Object-InsideOut

MAN3=		Math::Random::MT::Auto.3 Math::Random::MT::Auto::Range.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500808
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.18:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
