# New ports collection makefile for:	p5-Crypt-Primes
# Date created:				Tue Sep 11 10:31:23 PDT 2001
# Whom:	      				Michael Haro <mharo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-Primes
PORTVERSION=	0.50
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	mharo@FreeBSD.org
COMMENT=	Provable Prime Number Generator suitable for Cryptographic Applications

PERLBASE=	${SITE_PERL}

BUILD_DEPENDS=	${PERLBASE}/Crypt/Random.pm:${PORTSDIR}/security/p5-Crypt-Random \
		${PERLBASE}/${PERL_ARCH}/Math/Pari.pm:${PORTSDIR}/math/p5-Math-Pari

PERL_CONFIGURE=	yes

MAN1=		largeprimes.1
MAN3=		Crypt::Primes.3

.include <bsd.port.mk>
