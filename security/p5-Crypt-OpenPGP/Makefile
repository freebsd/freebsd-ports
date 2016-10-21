# Created by: Michael Haro <mharo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Crypt-OpenPGP
PORTVERSION=	1.06
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Pure-Perl OpenPGP-compatible PGP implementation

RUN_DEPENDS= \
		p5-Crypt-Blowfish>=0:security/p5-Crypt-Blowfish \
		p5-Crypt-CAST5_PP>=0:security/p5-Crypt-CAST5_PP \
		p5-Crypt-DES_EDE3>=0:security/p5-Crypt-DES_EDE3 \
		p5-Crypt-DSA>=0:security/p5-Crypt-DSA \
		p5-Crypt-IDEA>=0:security/p5-Crypt-IDEA \
		p5-Crypt-RIPEMD160>=0:security/p5-Crypt-RIPEMD160 \
		p5-Crypt-RSA>=0:security/p5-Crypt-RSA \
		p5-Crypt-Rijndael>=0:security/p5-Crypt-Rijndael \
		p5-Crypt-Twofish>=0:security/p5-Crypt-Twofish \
		p5-Data-Buffer>=0:misc/p5-Data-Buffer \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-libwww>=0:www/p5-libwww \
		p5-URI>=0:net/p5-URI

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${RM} ${WRKSRC}/lib/Crypt/OpenPGP/Ciphertext.pm.orig

.include <bsd.port.mk>
