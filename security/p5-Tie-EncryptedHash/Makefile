# New ports collection makefile for:	p5-Tie-EncryptedHash
# Date created:				Tue Sep 11 10:31:23 PDT 2001
# Whom:	      				Michael Haro <mharo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tie-EncryptedHash
PORTVERSION=	1.1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tie
PKGNAMEPREFIX=	p5-

MAINTAINER=	mharo@FreeBSD.org

PERLBASE=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

BUILD_DEPENDS=	${PERLBASE}/Crypt/CBC.pm:${PORTSDIR}/security/p5-Crypt-CBC \
		${PERLBASE}/${PERL_ARCH}/Crypt/DES.pm:${PORTSDIR}/security/p5-Crypt-DES \
		${PERLBASE}/${PERL_ARCH}/Crypt/Blowfish.pm:${PORTSDIR}/security/p5-Crypt-Blowfish

RESTRICTED=	"Crypto; export-controlled"

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Tie::EncryptedHash.3

.include <bsd.port.mk>
