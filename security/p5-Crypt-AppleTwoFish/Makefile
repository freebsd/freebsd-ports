# New ports collection Makefile for:	p5-Crypt-AppleTwoFish
# Date created:				18 Dec 2006
# Whom:	      				Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Crypt-AppleTwoFish
PORTVERSION=	0.02
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	gkovesdan@t-hosting.hu
COMMENT=	Perl extension for Apple iTMS internal key descrambling algorithm

PERL_CONFIGURE=	yes

MAN3=		Crypt::AppleTwoFish.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
IGNORE= requires Perl 5.6. Intall lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
