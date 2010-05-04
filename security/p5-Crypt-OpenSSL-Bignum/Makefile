# New ports collection makefile for:    p5-Crypt-OpenSSL-Bignum
# Date created:				Sep. 4, 2003
# Whom:					erwin@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Crypt-OpenSSL-Bignum
PORTVERSION=	0.04
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	OpenSSL's multiprecision integer arithmetic

PERL_CONFIGURE=	yes
USE_OPENSSL=	yes
MAKE_ARGS+=	PASTHRU_INC=-I${OPENSSLINC}

MAN3=		Crypt::OpenSSL::Bignum::CTX.3 Crypt::OpenSSL::Bignum.3

.include <bsd.port.mk>
