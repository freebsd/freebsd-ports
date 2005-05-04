# New ports collection makefile for:	p5-Net-SSH-Perl
# Date created:				15 March 2002
# Whom:	      				Jesper Skriver <jesper@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-SSH-Perl
PORTVERSION=	1.27
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	jesper@FreeBSD.org
COMMENT=	Perl5 module implements both the SSH1 and SSH2 protocols

MANUAL_PACKAGE_BUILD=infinite loop prompting for input
PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		"This port needs Perl 5.6.0 or greater, please upgrade your Perl!"
.endif

BUILD_DEPENDS=	${SITE_PERL}/Crypt/DSA.pm:${PORTSDIR}/security/p5-Crypt-DSA \
		${SITE_PERL}/Crypt/DH.pm:${PORTSDIR}/security/p5-Crypt-DH \
		${SITE_PERL}/${PERL_ARCH}/Math/Pari.pm:${PORTSDIR}/math/p5-Math-Pari \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/Digest/HMAC_SHA1.pm:${PORTSDIR}/security/p5-Digest-HMAC \
		${SITE_PERL}/Digest/HMAC_MD5.pm:${PORTSDIR}/security/p5-Digest-HMAC \
		${SITE_PERL}/Convert/PEM.pm:${PORTSDIR}/converters/p5-Convert-PEM \
		${SITE_PERL}/Digest/BubbleBabble.pm:${PORTSDIR}/security/p5-Digest-BubbleBabble \
		${SITE_PERL}/Crypt/RSA.pm:${PORTSDIR}/security/p5-Crypt-RSA \
		${SITE_PERL}/${PERL_ARCH}/String/CRC32.pm:${PORTSDIR}/devel/p5-String-CRC32 \
		${SITE_PERL}/${PERL_ARCH}/Math/GMP.pm:${PORTSDIR}/math/p5-Math-GMP \
		${SITE_PERL}/${PERL_ARCH}/Crypt/IDEA.pm:${PORTSDIR}/security/p5-Crypt-IDEA

.if ${PERL_LEVEL} <= 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/IO/Socket.pm:${PORTSDIR}/devel/p5-IO
.endif

RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		Net::SSH::Perl.3 \
		Net::SSH::Perl::Agent.3 \
		Net::SSH::Perl::Auth.3 \
		Net::SSH::Perl::Auth::KeyboardInt.3 \
		Net::SSH::Perl::Auth::Password.3 \
		Net::SSH::Perl::Auth::PublicKey.3 \
		Net::SSH::Perl::Auth::RSA.3 \
		Net::SSH::Perl::Auth::Rhosts.3 \
		Net::SSH::Perl::Auth::Rhosts_RSA.3 \
		Net::SSH::Perl::AuthMgr.3 \
		Net::SSH::Perl::Buffer.3 \
		Net::SSH::Perl::Channel.3 \
		Net::SSH::Perl::ChannelMgr.3 \
		Net::SSH::Perl::Cipher.3 \
		Net::SSH::Perl::Cipher::Blowfish.3 \
		Net::SSH::Perl::Cipher::CBC.3 \
		Net::SSH::Perl::Cipher::CFB.3 \
		Net::SSH::Perl::Cipher::DES.3 \
		Net::SSH::Perl::Cipher::DES3.3 \
		Net::SSH::Perl::Cipher::IDEA.3 \
		Net::SSH::Perl::Cipher::RC4.3 \
		Net::SSH::Perl::Comp.3 \
		Net::SSH::Perl::Comp::Zlib.3 \
		Net::SSH::Perl::Config.3 \
		Net::SSH::Perl::Constants.3 \
		Net::SSH::Perl::Kex.3 \
		Net::SSH::Perl::Kex::DH1.3 \
		Net::SSH::Perl::Key.3 \
		Net::SSH::Perl::Key::DSA.3 \
		Net::SSH::Perl::Key::RSA.3 \
		Net::SSH::Perl::Key::RSA1.3 \
		Net::SSH::Perl::Mac.3 \
		Net::SSH::Perl::Packet.3 \
		Net::SSH::Perl::SSH1.3 \
		Net::SSH::Perl::SSH2.3 \
		Net::SSH::Perl::Util.3 \

.include <bsd.port.post.mk>
