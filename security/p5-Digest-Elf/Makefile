# Ports collection Makefile for:	p5-Digest-Elf
# Date created:				17 Dec 2005
# Whom:					Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Digest-Elf
PORTVERSION=	1.4
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-

MAINTAINER=	gkovesdan@t-hosting.hu
COMMENT=	Perl extension for ElfHash hash algorithm

PERL_CONFIGURE= yes

MAN3=	Digest::Elf.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
IGNORE=	requires Perl 5.6. Intall lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
