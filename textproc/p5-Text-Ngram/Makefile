# New ports collection makefile for:	Text::Ngram
# Date created:				Nov 4 2004
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	Text-Ngram
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl module for n-gram analysis

PERL_CONFIGURE=	yes

MAN3=		Text::Ngram.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
