# New ports collection makefile for:	p5-Math-Random-MT-Auto
# Date created:		2006-07-21
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Random-MT-Auto
PORTVERSION=	6.16
CATEGORIES=	math perl5
MASTER_SITES=	CPAN/../../authors/id/J/JD/JDHEDDEN
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Auto-seeded Mersenne Twister PRNGs

BUILD_DEPENDS=	p5-Object-InsideOut>=2.06:${PORTSDIR}/devel/p5-Object-InsideOut \
		p5-Exception-Class>=1.22:${PORTSDIR}/devel/p5-Exception-Class
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Math::Random::MT::Auto.3 Math::Random::MT::Auto::Range.3

.include <bsd.port.mk>
