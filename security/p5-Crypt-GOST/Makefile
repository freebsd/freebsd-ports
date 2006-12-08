# New ports collection Makefile for:	p5-Crypt-GOST
# Date created:				20 Dec 2006
# Whom:	      				Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Crypt-GOST
PORTVERSION=	1.00
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Perl extension for GOST Encryption Algorithm

PERL_CONFIGURE=	yes

MAN3=		Crypt::GOST.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
IGNORE= requires Perl 5.6. Intall lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
