# New ports collection makefile for:	p5-Net-SSH-Perl
# Date created:				15 March 2002
# Whom:	      				Jesper Skriver <jesper@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-SSH-Perl
PORTVERSION=	1.23
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	jesper@FreeBSD.org

PERL_BASE=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
BUILD_DEPENDS=	${PERL_BASE}/Crypt/DSA.pm:${PORTSDIR}/security/p5-Crypt-DSA \
		${PERL_BASE}/Crypt/DH.pm:${PORTSDIR}/security/p5-Crypt-DH \
		${PERL_BASE}/${PERL_ARCH}/Math/Pari.pm:${PORTSDIR}/math/p5-Math-Pari \
		${PERL_BASE}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${PERL_BASE}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${PERL_BASE}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${PERL_BASE}/Digest/HMAC_SHA1.pm:${PORTSDIR}/security/p5-Digest-HMAC \
		${PERL_BASE}/Digest/HMAC_MD5.pm:${PORTSDIR}/security/p5-Digest-HMAC \
		${PERL_BASE}/Convert/PEM.pm:${PORTSDIR}/converters/p5-Convert-PEM \
		${PERL_BASE}/Digest/BubbleBabble.pm:${PORTSDIR}/security/p5-Digest-BubbleBabble \
		${PERL_BASE}/Crypt/RSA.pm:${PORTSDIR}/security/p5-Crypt-RSA \
		${PERL_BASE}/${PERL_ARCH}/IO/Socket.pm:${PORTSDIR}/devel/p5-IO \
		${PERL_BASE}/${PERL_ARCH}/String/CRC32.pm:${PORTSDIR}/devel/p5-String-CRC32 \
		${PERL_BASE}/${PERL_ARCH}/Math/GMP.pm:${PORTSDIR}/math/p5-Math-GMP \
		${PERL_BASE}/${PERL_ARCH}/Crypt/IDEA.pm:${PORTSDIR}/security/p5-Crypt-IDEA
RUN_DEPENDS=	${BUILD_DEPENDS}
FETCH_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Net::SSH::Perl::Constants.3 \
		Net::SSH::Perl::Util.3 \
		Net::SSH::Perl::ChannelMgr.3 \
		Net::SSH::Perl::SSH1.3 \
		Net::SSH::Perl::Auth::Rhosts.3 \
		Net::SSH::Perl::Cipher::DES.3 \
		Net::SSH::Perl::Auth::RSA.3 \
		Net::SSH::Perl::Kex.3 \
		Net::SSH::Perl::Key::RSA1.3 \
		Net::SSH::Perl::Comp.3 \
		Net::SSH::Perl::Key::DSA.3 \
		Net::SSH::Perl.3 \
		Net::SSH::Perl::Mac.3 \
		Net::SSH::Perl::Auth.3 \
		Net::SSH::Perl::Cipher::CBC.3 \
		Net::SSH::Perl::Cipher::RC4.3 \
		Net::SSH::Perl::Kex::DH1.3 \
		Net::SSH::Perl::Buffer.3 \
		Net::SSH::Perl::Cipher.3 \
		Net::SSH::Perl::Cipher::IDEA.3 \
		Net::SSH::Perl::Auth::KeyboardInt.3 \
		Net::SSH::Perl::Key::RSA.3 \
		Net::SSH::Perl::SSH2.3 \
		Net::SSH::Perl::Cipher::Blowfish.3 \
		Net::SSH::Perl::Auth::Rhosts_RSA.3 \
		Net::SSH::Perl::Auth::PublicKey.3 \
		Net::SSH::Perl::Key.3 \
		Net::SSH::Perl::Agent.3 \
		Net::SSH::Perl::Comp::Zlib.3 \
		Net::SSH::Perl::Auth::Password.3 \
		Net::SSH::Perl::Cipher::CFB.3 \
		Net::SSH::Perl::Packet.3 \
		Net::SSH::Perl::AuthMgr.3 \
		Net::SSH::Perl::Cipher::DES3.3 \
		Net::SSH::Perl::Channel.3

.include <bsd.port.mk>
