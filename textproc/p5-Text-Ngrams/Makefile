# New ports collection makefile for:	p5-Text-Ngrams
# Date created:				Dec 27 2003
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Text-Ngrams
PORTVERSION=	1.7
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl5 modules for Flexible Ngram analysis

PERL_CONFIGURE=	yes

MAN1=		ngrams.pl.1
MAN3=		Text::Ngrams.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
