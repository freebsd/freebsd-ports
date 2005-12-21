# New ports collection Makefile for:	p5-Crypt-SaltedHash
# Date created:				20 Dec 2006
# Whom:	      				Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Crypt-SaltedHash
PORTVERSION=	0.03
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	gkovesdan@t-hosting.hu
COMMENT=	Perl extension to work with salted hashes

BUILD_DEPENDS=	${SITE_PERL}/Digest.pm:${PORTSDIR}/security/p5-Digest \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64

PERL_CONFIGURE=	yes

MAN3=		Crypt::SaltedHash.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
IGNORE= requires Perl 5.6. Intall lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
