# New ports collection makefile for:	Lingua::Ident
# Date created:				31 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=		Lingua-Ident
PORTVERSION=		1.4
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/MPIOTR
PKGNAMEPREFIX=		p5-

MAINTAINER=		svenasse@polaris.ca
COMMENT=	Statistical language identification

PERL_CONFIGURE=		yes

MAN1=			trainlid.1
MAN3=			Lingua::Ident.3
MAN3PREFIX=		${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 500800
BROKEN=			"Does not compile with perl >=5.8"
.endif

.include <bsd.port.post.mk>
