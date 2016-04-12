# Created by: Michael Haro <mharo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Crypt-Primes
PORTVERSION=	0.50
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provable Prime Number Generator suitable for Cryptographic Applications

BUILD_DEPENDS=	p5-Crypt-Random>=0:security/p5-Crypt-Random \
		p5-Math-Pari>=0:math/p5-Math-Pari
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
