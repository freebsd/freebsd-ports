# Ports collection Makefile for:	p5-Digest-DMAC
# Date created:				17 Dec 2005
# Whom:					Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Digest-DMAC
PORTVERSION=	1.1.4
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-

MAINTAINER=	gkovesdan@t-hosting.hu
COMMENT=	Perl5 interface to DMAC Double Message-Digest Algorithms

BUILD_DEPENDS=	${SITE_PERL}/Crypt/CBC.pm:${PORTSDIR}/security/p5-Crypt-CBC \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64

PERL_CONFIGURE= yes

MAN3=	Digest::DMAC.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
IGNORE=	requires Perl 5.6. Intall lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
