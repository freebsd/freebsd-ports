# New ports collection makefile for:	Lingua-Stem-Ru
# Date created:				Jul 26 2004
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=		Lingua-Stem-Ru
PORTVERSION=		0.01
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=		p5-

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Porter's stemming algorithm for Russian (KOI8-R only)

PERL_CONFIGURE=		yes

MAN3=			Lingua::Stem::Ru.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
