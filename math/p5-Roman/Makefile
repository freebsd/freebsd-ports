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
COMMENT=	Perl module to convert between Arabic and Roman numerals

NO_BUILD=	yes
PLIST_FILES=	%%SITE_PERL%%/Roman.pm
USE_PERL5_RUN=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 500800
BROKEN=		"Does not install"
.endif

do-install:
	${CP} ${WRKSRC}/Roman.pm ${SITE_PERL}

.include <bsd.port.post.mk>
