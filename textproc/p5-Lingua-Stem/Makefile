# New ports collection makefile for:	Lingua::Stem
# Date created:				29 Dec 2003
# Whom:					Thorsten Greiner <thorsten.greiner@web.de>
#
# $FreeBSD$
#

PORTNAME=		Lingua-Stem
PORTVERSION=		0.61
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=		p5-

MAINTAINER=		thorsten.greiner@web.de
COMMENT=		Provides word stemming algorithms localized by language

PERL_CONFIGURE=		yes

MAN3=			Lingua::Stem.3 Lingua::Stem::AutoLoader.3 \
			Lingua::Stem::En.3 Lingua::Stem::Pt.3 \
			Lingua::Stem::EnBroken.3 Lingua::Stem::Gl.3 \
			Lingua::Stem::No.3 Lingua::Stem::De.3 \
			Lingua::Stem::Sv.3 Lingua::Stem::Da.3
MAN3PREFIX=		${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
