# New ports collection makefile for:	p5-Crypt-RSA
# Date created:				Tue Sep 11 10:31:23 PDT 2001
# Whom:	      				Michael Haro <mharo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-RSA
PORTVERSION=	1.50
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	mharo@FreeBSD.org
COMMENT=	RSA public-key cryptosystem

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/${PERL_ARCH}/Crypt/Blowfish.pm:${PORTSDIR}/security/p5-Crypt-Blowfish \
		${SITE_PERL}/Crypt/Random.pm:${PORTSDIR}/security/p5-Crypt-Random \
		${SITE_PERL}/Crypt/Primes.pm:${PORTSDIR}/security/p5-Crypt-Primes \
		${SITE_PERL}/Crypt/CBC.pm:${PORTSDIR}/security/p5-Crypt-CBC \
		${SITE_PERL}/Convert/ASCII/Armor.pm:${PORTSDIR}/converters/p5-Convert-ASCII-Armour \
		${SITE_PERL}/Data/Buffer.pm:${PORTSDIR}/misc/p5-Data-Buffer \
		${SITE_PERL}/Sort/Versions.pm:${PORTSDIR}/devel/p5-Sort-Versions \
		${SITE_PERL}/Class/Loader.pm:${PORTSDIR}/devel/p5-Class-Loader \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD2.pm:${PORTSDIR}/security/p5-Digest-MD2 \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Tie/EncryptedHash.pm:${PORTSDIR}/security/p5-Tie-EncryptedHash \
		${SITE_PERL}/MD5.pm:${PORTSDIR}/security/p5-MD5
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Crypt::RSA::Key.3 Crypt::RSA::SS::PSS.3 \
		Crypt::RSA::Primitives.3 Crypt::RSA::ES::OAEP.3 \
		Crypt::RSA.3 Crypt::RSA::SS::PKCS1v15.3 \
		Crypt::RSA::DataFormat.3 Crypt::RSA::Key::Private.3 \
		Crypt::RSA::ES::PKCS1v15.3 Crypt::RSA::Debug.3 \
		Crypt::RSA::Key::Public.3 Crypt::RSA::Errorhandler.3

.include <bsd.port.mk>
