# New ports collection makefile for:	Text::Similarity
# Date created:				Oct 28 2004
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	Text-Similarity
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl module for measuring the similarity of text documents

PERL_CONFIGURE=	yes

MAN1=		text_compare.pl.1
MAN3=		Text::OverlapFinder.3 \
		Text::Similarity.3 \
		Text::Similarity::Overlaps.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
