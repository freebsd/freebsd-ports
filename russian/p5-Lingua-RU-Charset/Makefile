# New ports collection makefile for:	p5-Lingua-RU-Charset
# Date created:				December 28th 2000
# Whom:	      				Alex Kapranoff <kapr@crosswinds.net>
#
# $FreeBSD$
#

PORTNAME=	Lingua-RU-Charset
PORTVERSION=	0.02
CATEGORIES=	russian perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=	p5-

MAINTAINER=	kapr@crosswinds.net

USE_PERL5=	YES

MAN3=		Lingua::RU::Charset.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
