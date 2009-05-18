# New ports collection makefile for:	Authen-Passphrase
# Date created:				01 Jun 2008
# Whom:					brix@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Authen-Passphrase
PORTVERSION=	0.006
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	brix@FreeBSD.org
COMMENT=	Perl module for handling hashed passwords/passphrases as objects

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Authen/DecHpwd.pm:${PORTSDIR}/security/p5-Authen-DecHpwd \
		${SITE_PERL}/${PERL_ARCH}/Crypt/Blowfish.pm:${PORTSDIR}/security/p5-Crypt-Blowfish \
		${SITE_PERL}/${PERL_ARCH}/Crypt/DES.pm:${PORTSDIR}/security/p5-Crypt-DES \
		${SITE_PERL}/${PERL_ARCH}/Crypt/Eksblowfish.pm:${PORTSDIR}/security/p5-Crypt-Eksblowfish \
		${SITE_PERL}/${PERL_ARCH}/Crypt/MySQL.pm:${PORTSDIR}/security/p5-Crypt-MySQL \
		${SITE_PERL}/Crypt/PasswdMD5.pm:${PORTSDIR}/security/p5-Crypt-PasswdMD5 \
		${SITE_PERL}/${PERL_ARCH}/Crypt/UnixCrypt_XS.pm:${PORTSDIR}/security/p5-Crypt-UnixCrypt_XS \
		${SITE_PERL}/Data/Entropy/Algorithms.pm:${PORTSDIR}/security/p5-Data-Entropy \
		${SITE_PERL}/Digest.pm:${PORTSDIR}/security/p5-Digest \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD4.pm:${PORTSDIR}/security/p5-Digest-MD4 \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/Module/Runtime.pm:${PORTSDIR}/devel/p5-Module-Runtime \
		${SITE_PERL}/${PERL_ARCH}/Params/Classify.pm:${PORTSDIR}/devel/p5-Params-Classify
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

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
