# New ports collection makefile for:	Locale::SubCountry
# Date created:				30 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Locale-SubCountry
PORTVERSION=	1.37
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Locale
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert state, province, county etc. names to/from code

PERL_CONFIGURE=	yes

MAN3=	Locale::SubCountry.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500804
IGNORE=		requires perl 5.8.4 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
