# New ports collection makefile for:	Math-Combinatorics
# Date created:				27 May 2005
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Math-Combinatorics
PORTVERSION=	0.09
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Perform combinations and permutations on lists

MAN3=		Math::Combinatorics.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires Perl 5.6 or greater.  Please install lang/perl58 and try again
.endif

.include <bsd.port.post.mk>
