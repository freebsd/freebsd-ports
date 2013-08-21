# Created by: vanilla@
# $FreeBSD$

PORTNAME=	CryptX
PORTVERSION=	0.012
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Crypto toolkit

USES=		perl5
USE_PERL5=	modbuild

MAN3=		Crypt::AuthEnc::CCM.3 \
		Crypt::AuthEnc::EAX.3 \
		Crypt::AuthEnc::GCM.3 \
		Crypt::AuthEnc::OCB.3 \
		Crypt::Cipher.3 \
		Crypt::Cipher::AES.3 \
		Crypt::Cipher::Anubis.3 \
		Crypt::Cipher::Blowfish.3 \
		Crypt::Cipher::CAST5.3 \
		Crypt::Cipher::Camellia.3 \
		Crypt::Cipher::DES.3 \
		Crypt::Cipher::DES_EDE.3 \
		Crypt::Cipher::KASUMI.3 \
		Crypt::Cipher::Khazad.3 \
		Crypt::Cipher::MULTI2.3 \
		Crypt::Cipher::Noekeon.3 \
		Crypt::Cipher::RC2.3 \
		Crypt::Cipher::RC5.3 \
		Crypt::Cipher::RC6.3 \
		Crypt::Cipher::SAFERP.3 \
		Crypt::Cipher::SAFER_K128.3 \
		Crypt::Cipher::SAFER_K64.3 \
		Crypt::Cipher::SAFER_SK128.3 \
		Crypt::Cipher::SAFER_SK64.3 \
		Crypt::Cipher::SEED.3 \
		Crypt::Cipher::Skipjack.3 \
		Crypt::Cipher::Twofish.3 \
		Crypt::Cipher::XTEA.3 \
		Crypt::Digest.3 \
		Crypt::Digest::CHAES.3 \
		Crypt::Digest::MD2.3 \
		Crypt::Digest::MD4.3 \
		Crypt::Digest::MD5.3 \
		Crypt::Digest::RIPEMD128.3 \
		Crypt::Digest::RIPEMD160.3 \
		Crypt::Digest::RIPEMD256.3 \
		Crypt::Digest::RIPEMD320.3 \
		Crypt::Digest::SHA1.3 \
		Crypt::Digest::SHA224.3 \
		Crypt::Digest::SHA256.3 \
		Crypt::Digest::SHA384.3 \
		Crypt::Digest::SHA512.3 \
		Crypt::Digest::Tiger192.3 \
		Crypt::Digest::Whirlpool.3 \
		Crypt::KeyDerivation.3 \
		Crypt::Mac::F9.3 \
		Crypt::Mac::HMAC.3 \
		Crypt::Mac::OMAC.3 \
		Crypt::Mac::PMAC.3 \
		Crypt::Mac::Pelican.3 \
		Crypt::Mac::XCBC.3 \
		Crypt::Mode::CBC.3 \
		Crypt::Mode::CFB.3 \
		Crypt::Mode::CTR.3 \
		Crypt::Mode::ECB.3 \
		Crypt::Mode::OFB.3 \
		Crypt::PK::DH.3 \
		Crypt::PK::DSA.3 \
		Crypt::PK::ECC.3 \
		Crypt::PK::RSA.3 \
		Crypt::PRNG.3 \
		Crypt::PRNG::Fortuna.3 \
		Crypt::PRNG::RC4.3 \
		Crypt::PRNG::Sober128.3 \
		Crypt::PRNG::Yarrow.3 \
		CryptX.3

regression-test: build
	@cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${PERL5} ${PL_BUILD} ${MAKE_ARGS} test

.include <bsd.port.mk>
