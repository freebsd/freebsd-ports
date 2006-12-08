# Ports collection Makefile for:	p5-Digest-Perl-MD4
# Date created:				21 Dec, 2005
# Whom:					Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Digest-Perl-MD4
PORTVERSION=	1.4
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Perl extension for MD4 hash algorithm in pure Perl

PERL_CONFIGURE=	yes

MAN3=	Digest::Perl::Digest-MD4.3 \
	Digest::Perl::MD4.3

WRKSRC=	${WRKDIR}/MD4

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	${PERL} -pi -e '$$_ = "" if m{warnings}' ${WRKSRC}/MD4.pm
.endif

.include <bsd.port.post.mk>
