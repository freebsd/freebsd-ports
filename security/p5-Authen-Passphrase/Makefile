# Created by: brix@FreeBSD.org
# $FreeBSD$

PORTNAME=	Authen-Passphrase
PORTVERSION=	0.008
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	brix@FreeBSD.org
COMMENT=	Perl module for handling hashed passwords/passphrases as objects

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Authen-DecHpwd>=0:${PORTSDIR}/security/p5-Authen-DecHpwd \
		p5-Crypt-Blowfish>=0:${PORTSDIR}/security/p5-Crypt-Blowfish \
		p5-Crypt-DES>=0:${PORTSDIR}/security/p5-Crypt-DES \
		p5-Crypt-Eksblowfish>=0:${PORTSDIR}/security/p5-Crypt-Eksblowfish \
		p5-Crypt-MySQL>=0:${PORTSDIR}/security/p5-Crypt-MySQL \
		p5-Crypt-PasswdMD5>=0:${PORTSDIR}/security/p5-Crypt-PasswdMD5 \
		p5-Crypt-UnixCrypt_XS>=0:${PORTSDIR}/security/p5-Crypt-UnixCrypt_XS \
		p5-Data-Entropy>=0:${PORTSDIR}/security/p5-Data-Entropy \
		p5-Digest-MD4>=0:${PORTSDIR}/security/p5-Digest-MD4 \
		p5-Module-Runtime>=0:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Params-Classify>=0:${PORTSDIR}/devel/p5-Params-Classify
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=	Authen::Passphrase.3 \
	Authen::Passphrase::AcceptAll.3 \
	Authen::Passphrase::BigCrypt.3 \
	Authen::Passphrase::BlowfishCrypt.3 \
	Authen::Passphrase::Clear.3 \
	Authen::Passphrase::Crypt16.3 \
	Authen::Passphrase::DESCrypt.3 \
	Authen::Passphrase::EggdropBlowfish.3 \
	Authen::Passphrase::LANManager.3 \
	Authen::Passphrase::LANManagerHalf.3 \
	Authen::Passphrase::MD5Crypt.3 \
	Authen::Passphrase::MySQL323.3 \
	Authen::Passphrase::MySQL41.3 \
	Authen::Passphrase::NTHash.3 \
	Authen::Passphrase::NetscapeMail.3 \
	Authen::Passphrase::PHPass.3 \
	Authen::Passphrase::RejectAll.3 \
	Authen::Passphrase::SaltedDigest.3 \
	Authen::Passphrase::VMSPurdy.3

.include <bsd.port.mk>
