# Created by: Michael Haro <mharo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Crypt-RSA
PORTVERSION=	1.99
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	RSA public-key cryptosystem

RUN_DEPENDS=	p5-Class-Loader>=2.00:${PORTSDIR}/devel/p5-Class-Loader \
		p5-Convert-ASCII-Armour>=0:${PORTSDIR}/converters/p5-Convert-ASCII-Armour \
		p5-Crypt-CBC>=0:${PORTSDIR}/security/p5-Crypt-CBC \
		p5-Crypt-Primes>=0.38:${PORTSDIR}/security/p5-Crypt-Primes \
		p5-Crypt-Random>=0.34:${PORTSDIR}/security/p5-Crypt-Random \
		p5-Data-Buffer>=0:${PORTSDIR}/misc/p5-Data-Buffer \
		p5-Digest-MD2>=0:${PORTSDIR}/security/p5-Digest-MD2 \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Math-Pari>=2.001804:${PORTSDIR}/math/p5-Math-Pari \
		p5-Sort-Versions>=0:${PORTSDIR}/devel/p5-Sort-Versions \
		p5-Crypt-Blowfish>=0:${PORTSDIR}/security/p5-Crypt-Blowfish \
		p5-Tie-EncryptedHash>=0:${PORTSDIR}/security/p5-Tie-EncryptedHash

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
