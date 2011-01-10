# New ports collection makefile for:	p5-Crypt-OpenPGP
# Date created:				Tue Sep 11 02:08:49 PDT 2001
# Whom:	      				Michael Haro <mharo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-OpenPGP
PORTVERSION=	1.06
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Pure-Perl OpenPGP-compatible PGP implementation

RUN_DEPENDS= \
		${SITE_PERL}/${PERL_ARCH}/Crypt/Blowfish.pm:${PORTSDIR}/security/p5-Crypt-Blowfish \
		${SITE_PERL}/Crypt/CAST5_PP.pm:${PORTSDIR}/security/p5-Crypt-CAST5_PP \
		${SITE_PERL}/Crypt/DES_EDE3.pm:${PORTSDIR}/security/p5-Crypt-DES_EDE3 \
		${SITE_PERL}/Crypt/DSA.pm:${PORTSDIR}/security/p5-Crypt-DSA \
		${SITE_PERL}/${PERL_ARCH}/Crypt/IDEA.pm:${PORTSDIR}/security/p5-Crypt-IDEA \
		${SITE_PERL}/${PERL_ARCH}/Crypt/RIPEMD160.pm:${PORTSDIR}/security/p5-Crypt-RIPEMD160 \
		${SITE_PERL}/Crypt/RSA.pm:${PORTSDIR}/security/p5-Crypt-RSA \
		${SITE_PERL}/${PERL_ARCH}/Crypt/Rijndael.pm:${PORTSDIR}/security/p5-Crypt-Rijndael \
		${SITE_PERL}/${PERL_ARCH}/Crypt/Twofish.pm:${PORTSDIR}/security/p5-Crypt-Twofish \
		${SITE_PERL}/Data/Buffer.pm:${PORTSDIR}/misc/p5-Data-Buffer \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/File/HomeDir.pm:${PORTSDIR}/devel/p5-File-HomeDir \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI

PERL_CONFIGURE=	yes

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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

post-patch:
	@${RM} -f ${WRKSRC}/lib/Crypt/OpenPGP/Ciphertext.pm.orig

.include <bsd.port.post.mk>
