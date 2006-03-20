# New ports collection makefile for:	textproc/p5-Lingua-StopWords
# Date created:				13 October 2004
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Lingua-StopWords
PORTVERSION=	0.05
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Stop words for several languages

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=	requires perl 5.6.1 or newer
.endif

MAN3=	Lingua::StopWords.3

.include <bsd.port.post.mk>
