# Created by: brix@FreeBSD.org
# $FreeBSD$

PORTNAME=	Authen-Passphrase
PORTVERSION=	0.008
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for handling hashed passwords/passphrases as objects

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Authen-DecHpwd>=0:security/p5-Authen-DecHpwd \
		p5-Crypt-Blowfish>=0:security/p5-Crypt-Blowfish \
		p5-Crypt-DES>=0:security/p5-Crypt-DES \
		p5-Crypt-Eksblowfish>=0:security/p5-Crypt-Eksblowfish \
		p5-Crypt-MySQL>=0:security/p5-Crypt-MySQL \
		p5-Crypt-PasswdMD5>=0:security/p5-Crypt-PasswdMD5 \
		p5-Crypt-UnixCrypt_XS>=0:security/p5-Crypt-UnixCrypt_XS \
		p5-Data-Entropy>=0:security/p5-Data-Entropy \
		p5-Digest-MD4>=0:security/p5-Digest-MD4 \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Params-Classify>=0:devel/p5-Params-Classify
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	yes

.include <bsd.port.mk>
