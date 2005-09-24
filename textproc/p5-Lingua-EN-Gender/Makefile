# New ports collection makefile for:	Lingua::EN::Gender
# Date created:				30 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=		Lingua-EN-Gender
PORTVERSION=		1.0
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/E/EE/EEKIM
PKGNAMEPREFIX=		p5-

MAINTAINER=		perl@FreeBSD.org
COMMENT=	Inflect pronouns for gender

PERL_CONFIGURE=		yes

MAN3=			Lingua::EN::gender.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.1 or above
.endif

.include <bsd.port.post.mk>
