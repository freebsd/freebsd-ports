# New ports collection makefile for:	p5-Crypt-RSA
# Date created:				Tue Sep 11 10:31:23 PDT 2001
# Whom:	      				Michael Haro <mharo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-RSA
PORTVERSION=	1.48
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	mharo@FreeBSD.org

PERLBASE=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

BUILD_DEPENDS=	${PERLBASE}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${PERLBASE}/${PERL_ARCH}/Crypt/Blowfish.pm:${PORTSDIR}/security/p5-Crypt-Blowfish \
		${PERLBASE}/Crypt/Random.pm:${PORTSDIR}/security/p5-Crypt-Random \
		${PERLBASE}/Crypt/Primes.pm:${PORTSDIR}/security/p5-Crypt-Primes \
		${PERLBASE}/Crypt/CBC.pm:${PORTSDIR}/security/p5-Crypt-CBC \
		${PERLBASE}/Convert/ASCII/Armor.pm:${PORTSDIR}/converters/p5-Convert-ASCII-Armour \
		${PERLBASE}/Data/Buffer.pm:${PORTSDIR}/misc/p5-Data-Buffer \
		${PERLBASE}/Sort/Versions.pm:${PORTSDIR}/devel/p5-Sort-Versions \
		${PERLBASE}/Class/Loader.pm:${PORTSDIR}/devel/p5-Class-Loader \
		${PERLBASE}/${PERL_ARCH}/Digest/MD2.pm:${PORTSDIR}/security/p5-Digest-MD2 \
		${PERLBASE}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${PERLBASE}/Tie/EncryptedHash.pm:${PORTSDIR}/security/p5-Tie-EncryptedHash \
		${PERLBASE}/MD5.pm:${PORTSDIR}/security/p5-MD5

RESTRICTED=	"Crypto; export-controlled"

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Crypt::RSA::Key.3 Crypt::RSA::SS::PSS.3 \
		Crypt::RSA::Primitives.3 Crypt::RSA::ES::OAEP.3 \
		Crypt::RSA.3 Crypt::RSA::SS::PKCS1v15.3 \
		Crypt::RSA::DataFormat.3 Crypt::RSA::Key::Private.3 \
		Crypt::RSA::ES::PKCS1v15.3 Crypt::RSA::Debug.3 \
		Crypt::RSA::Key::Public.3 Crypt::RSA::Errorhandler.3

.include <bsd.port.mk>
