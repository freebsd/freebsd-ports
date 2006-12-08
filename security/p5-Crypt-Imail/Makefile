# New ports collection Makefile for:	p5-Crypt-Imail
# Date created:				20 Dec 2006
# Whom:	      				Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Crypt-Imail
PORTVERSION=	0.01
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Perl extension to encrypt and decrypt Imail passwords

PERL_CONFIGURE=	yes

MAN3=		Crypt::Imail.3

WRKSRC=		${WRKDIR}/Imail

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
IGNORE= requires Perl 5.6. Intall lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
