# New ports collection makefile for:	Lingua::Stem::Snowball::No
# Date created:				29 Dec 2003
# Whom:					Thorsten Greiner <thorsten.greiner@web.de>
#
# $FreeBSD$
#

PORTNAME=		Lingua-Stem-Snowball-No
PORTVERSION=		1.0
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/A/AS/ASKSH
PKGNAMEPREFIX=		p5-
DISTNAME=		Snowball-Norwegian-${PORTVERSION}

MAINTAINER=		thorsten.greiner@web.de
COMMENT=		A stemmer for Norwegian

PERL_CONFIGURE=		yes

MAN3=			Lingua::Stem::Snowball::No.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
