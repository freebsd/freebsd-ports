# Created by: Jesper Skriver <jesper@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-SSH-Perl
PORTVERSION=	1.36
CATEGORIES=		net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module implements both the SSH1 and SSH2 protocols

BUILD_DEPENDS=	p5-String-CRC32>=0:${PORTSDIR}/devel/p5-String-CRC32 \
		p5-Math-GMP>=0:${PORTSDIR}/math/p5-Math-GMP \
		p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-Crypt-DSA>=0:${PORTSDIR}/security/p5-Crypt-DSA \
		p5-Crypt-DH>=0:${PORTSDIR}/security/p5-Crypt-DH \
		p5-Math-Pari>=0:${PORTSDIR}/math/p5-Math-Pari \
		p5-Convert-PEM>=0:${PORTSDIR}/converters/p5-Convert-PEM \
		p5-Crypt-IDEA>=0:${PORTSDIR}/security/p5-Crypt-IDEA \
		p5-Digest-BubbleBabble>=0:${PORTSDIR}/security/p5-Digest-BubbleBabble \
		p5-Crypt-RSA>=0:${PORTSDIR}/security/p5-Crypt-RSA
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	Net::SSH::Perl.3 \
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
	Net::SSH::Perl::Handle.3 \
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
	Net::SSH::Perl::Subsystem::Client.3 \
	Net::SSH::Perl::Subsystem::Server.3 \
	Net::SSH::Perl::Util.3

CONFIGURE_ENV+=	PERL_MM_USE_DEFAULT="1"
USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	GMP
OPTIONS_DEFAULT=	GMP
GMP_DESC=	Use the optimized Math::BigInt::GMP backend

GMP_BUILD_DEPEND=	p5-Math-BigInt-GMP>=0:${PORTSDIR}/math/p5-Math-BigInt-GMP
GMP_RUN_DEPEND=		${GMP_BUILD_DEPEND}

.include <bsd.port.mk>
