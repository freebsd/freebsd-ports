# New ports collection makefile for:	p5-Roman
# Date created:				16 January 2003
# Whom:	      				Philip Paeps <philip@paeps.cx>
#
# $FreeBSD$
#

PORTNAME=	Roman
PORTVERSION=	1.1
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Roman
PKGNAMEPREFIX=	p5-

MAINTAINER=	philip@paeps.cx

NO_BUILD=	yes

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

do-install:
	${CP} ${WRKSRC}/Roman.pm ${SITE_PERL}

.include <bsd.port.mk>
