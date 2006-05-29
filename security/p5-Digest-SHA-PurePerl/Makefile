# Ports collection Makefile for:	p5-Digest-SHA-PurePerl
# Date created:				21 Dec, 2005
# Whom:					Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Digest-SHA-PurePerl
PORTVERSION=	5.37
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-

MAINTAINER=	gkovesdan@t-hosting.hu
COMMENT=	Perl extension for SHA-1/224/256/384/512 in pure Perl

PERL_CONFIGURE=	yes

MAN1=	shasum.1
MAN3=	Digest::SHA::PurePerl.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
IGNORE=	requires Perl 5.6. Intall lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
