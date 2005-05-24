# New ports collection makefile for:	textproc/p5-Lingua-Stem-Snowball
# Date created:				14 October 2004
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Lingua-Stem-Snowball
PORTVERSION=	0.92
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Lingua::Stem::Snowball - Perl interface to Snowball stemmers

PERL_CONFIGURE=	yes

MAN3=	Lingua::Stem::Snowball.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	"This port requires perl 5.6 or newer"
.endif

.include <bsd.port.post.mk>
