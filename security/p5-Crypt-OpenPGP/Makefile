# Created by: Michael Haro <mharo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Crypt-OpenPGP
PORTVERSION=	1.06
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Pure-Perl OpenPGP-compatible PGP implementation

RUN_DEPENDS= \
		p5-Crypt-Blowfish>=0:${PORTSDIR}/security/p5-Crypt-Blowfish \
		p5-Crypt-CAST5_PP>=0:${PORTSDIR}/security/p5-Crypt-CAST5_PP \
		p5-Crypt-DES_EDE3>=0:${PORTSDIR}/security/p5-Crypt-DES_EDE3 \
		p5-Crypt-DSA>=0:${PORTSDIR}/security/p5-Crypt-DSA \
		p5-Crypt-IDEA>=0:${PORTSDIR}/security/p5-Crypt-IDEA \
		p5-Crypt-RIPEMD160>=0:${PORTSDIR}/security/p5-Crypt-RIPEMD160 \
		p5-Crypt-RSA>=0:${PORTSDIR}/security/p5-Crypt-RSA \
		p5-Crypt-Rijndael>=0:${PORTSDIR}/security/p5-Crypt-Rijndael \
		p5-Crypt-Twofish>=0:${PORTSDIR}/security/p5-Crypt-Twofish \
		p5-Data-Buffer>=0:${PORTSDIR}/misc/p5-Data-Buffer \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-File-HomeDir>=0:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-URI>=0:${PORTSDIR}/net/p5-URI

USES=		perl5
USE_PERL5=	configure

MAN3=		Crypt::OpenPGP::ErrorHandler.3 Crypt::OpenPGP::Key.3 \
		Crypt::OpenPGP::CFB.3 Crypt::OpenPGP::SKSessionKey.3 \
		Crypt::OpenPGP::UserID.3 Crypt::OpenPGP::SessionKey.3 \
		Crypt::OpenPGP::Words.3 Crypt::OpenPGP::PacketFactory.3 \
		Crypt::OpenPGP::S2k.3 Crypt::OpenPGP.3 \
		Crypt::OpenPGP::Signature.3 \
		Crypt::OpenPGP::KeyBlock.3 Crypt::OpenPGP::MDC.3 \
		Crypt::OpenPGP::Compressed.3 Crypt::OpenPGP::Armour.3 \
		Crypt::OpenPGP::KeyRing.3 Crypt::OpenPGP::Plaintext.3 \
		Crypt::OpenPGP::Buffer.3 Crypt::OpenPGP::Cipher.3 \
		Crypt::OpenPGP::OnePassSig.3 Crypt::OpenPGP::Constants.3 \
		Crypt::OpenPGP::Util.3 Crypt::OpenPGP::Digest.3 \
		Crypt::OpenPGP::Ciphertext.3 Crypt::OpenPGP::Marker.3 \
		Crypt::OpenPGP::Trust.3 Crypt::OpenPGP::Certificate.3 \
		Crypt::OpenPGP::Message.3 Crypt::OpenPGP::KeyServer.3

NO_STAGE=	yes
post-patch:
	@${RM} -f ${WRKSRC}/lib/Crypt/OpenPGP/Ciphertext.pm.orig

.include <bsd.port.mk>
