# Ports collection Makefile for:	p5-Digest-SHA-PurePerl
# Date created:				21 Dec, 2005
# Whom:					Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Digest-SHA-PurePerl
PORTVERSION=	5.44
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Perl extension for SHA-1/224/256/384/512 in pure Perl

PERL_CONFIGURE=	yes

MAN1=		shasum.1
MAN3=		Digest::SHA::PurePerl.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
.endif

.if ${PERL_LEVEL} < 500803
RUN_DEPENDS+=	${SITE_PERL}/Digest/base.pm:${PORTSDIR}/security/p5-Digest
.endif

.include <bsd.port.post.mk>
