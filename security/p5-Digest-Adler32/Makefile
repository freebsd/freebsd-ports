# Ports collection Makefile for:	p5-Digest-Adler32
# Date created:				17 Dec 2005
# Whom:					Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Digest-Adler32
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Perl extension for Adler32 hash algorithm

BUILD_DEPENDS=	${SITE_PERL}/Digest.pm:${PORTSDIR}/security/p5-Digest
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Digest::Adler32.3

.include <bsd.port.mk>
