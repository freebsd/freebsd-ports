# New ports collection Makefile for:	p5-Crypt-Salt
# Date created:				20 Dec 2006
# Whom:	      				Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Crypt-Salt
PORTVERSION=	0.01
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Perl extension to generate a salt to be fed into crypt

PERL_CONFIGURE=	yes

MAN3=		Crypt::Salt.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
IGNORE= requires Perl 5.6. Intall lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
