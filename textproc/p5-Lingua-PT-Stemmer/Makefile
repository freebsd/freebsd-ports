# New ports collection makefile for:	Lingua::PT::Stemmer
# Date created:				31 Dec 2003
# Whom:					Thorsten Greiner <thorsten.greiner@web.de>
#
# $FreeBSD$
#

PORTNAME=	Lingua-PT-Stemmer
PORTVERSION=	0.01
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=	p5-

MAINTAINER=	thorsten.greiner@web.de
COMMENT=	Stemmers for Portuguese and Galician

PERL_CONFIGURE=	yes

MAN3=	Lingua::GL::Stemmer.3 Lingua::PT::Stemmer.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=	p5-Lingua-PT-Stemmer requires perl 5.6.1.  Instal lang/perl5 and then try again
.endif

.include <bsd.port.post.mk>
