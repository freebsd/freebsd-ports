# New ports collection makefile for:	p5-Auth-YubikeyDecrypter
# Date created:				Jul  2, 2010
# Whom:					Kurt Jaeger <fbsd-ports@opsec.eu>
#
# $FreeBSD$

PORTNAME=	Auth-YubikeyDecrypter
PORTVERSION=	0.07
CATEGORIES=	perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MA/MASSYN
PKGNAMEPREFIX=	p5-
DISTNAME=	Auth-Yubikey_Decrypter-${PORTVERSION}

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	Decrypting the output from the yubikey token

RUN_DEPENDS=	p5-Crypt-Rijndael>=1:${PORTSDIR}/security/p5-Crypt-Rijndael

LICENSE=	GPLv2
PERL_CONFIGURE=		yes

MAN3=		Auth::Yubikey_Decrypter.3

.include <bsd.port.mk>
