# New ports collection makefile for:	Lingua::Stemmer::It
# Date created:				31 Dec 2003
# Whom:					Thorsten Greiner <thorsten.greiner@web.de>
#
# $FreeBSD$
#

PORTNAME=		Lingua-Stem-It
PORTVERSION=		0.01
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=		p5-

MAINTAINER=		thorsten.greiner@web.de
COMMENT=		Stemmer for Italian

PERL_CONFIGURE=		yes

MAN3=			Lingua::Stem::It.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
