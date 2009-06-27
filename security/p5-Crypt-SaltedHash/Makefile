# New ports collection Makefile for:	p5-Crypt-SaltedHash
# Date created:				20 Dec 2006
# Whom:	      				Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Crypt-SaltedHash
PORTVERSION=	0.05
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl extension to work with salted hashes

RUN_DEPENDS=	${SITE_PERL}/Digest.pm:${PORTSDIR}/security/p5-Digest
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5

PERL_MODBUILD=	yes

MAN3=		Crypt::SaltedHash.3

.include <bsd.port.mk>
