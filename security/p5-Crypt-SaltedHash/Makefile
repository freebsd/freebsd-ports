# New ports collection Makefile for:	p5-Crypt-SaltedHash
# Date created:				20 Dec 2006
# Whom:	      				Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Crypt-SaltedHash
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Perl extension to work with salted hashes

PERL_MODBUILD=	yes

MAN3=		Crypt::SaltedHash.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
RUN_DEPENDS+=	p5-Digest>=1.16:${PORTSDIR}/security/p5-Digest
BUILD_DEPENDS+=	p5-Digest>=1.16:${PORTSDIR}/security/p5-Digest
.endif

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Digest-MD5>=2.16:${PORTSDIR}/security/p5-Digest-MD5
BUILD_DEPENDS+=	p5-Digest-MD5>=2.16:${PORTSDIR}/security/p5-Digest-MD5
.endif

.include <bsd.port.post.mk>
