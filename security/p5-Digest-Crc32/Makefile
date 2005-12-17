# Ports collection Makefile for:	p5-Digest-Crc32
# Date created:				17 Dec 2005
# Whom:					Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Digest-Crc32
PORTVERSION=	0.01
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-

MAINTAINER=	gkovesdan@t-hosting.hu
COMMENT=	Perl extension for calculating 32-bit CRC cheksums

PERL_CONFIGURE= yes

MAN3=	Digest::Crc32.3

WRKSRC=	${WRKDIR}/${PORTNAME}-001

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
IGNORE=	requires Perl 5.6. Intall lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
