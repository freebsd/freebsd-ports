# New ports collection makefile for:	p5-Tie-EncryptedHash
# Date created:				Tue Sep 11 10:31:23 PDT 2001
# Whom:	      				Michael Haro <mharo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tie-EncryptedHash
PORTVERSION=	1.21
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tie
PKGNAMEPREFIX=	p5-

MAINTAINER=	mharo@FreeBSD.org
COMMENT=	Hashes (and objects based on hashes) with encrypting fields

PERLBASE=	${SITE_PERL}

BUILD_DEPENDS=	${PERLBASE}/Crypt/CBC.pm:${PORTSDIR}/security/p5-Crypt-CBC \
		${PERLBASE}/${PERL_ARCH}/Crypt/DES.pm:${PORTSDIR}/security/p5-Crypt-DES \
		${PERLBASE}/${PERL_ARCH}/Crypt/Blowfish.pm:${PORTSDIR}/security/p5-Crypt-Blowfish \
		${PERLBASE}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5

PERL_CONFIGURE=	yes

MAN3=		Tie::EncryptedHash.3

.include <bsd.port.mk>
