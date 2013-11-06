# Created by: erwin@FreeBSD.org
# $FreeBSD$

PORTNAME=	Crypt-OpenSSL-Bignum
PORTVERSION=	0.04
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	OpenSSL's multiprecision integer arithmetic

USES=		perl5
USE_PERL5=	configure
USE_OPENSSL=	yes
MAKE_ARGS+=	PASTHRU_INC=-I${OPENSSLINC}

.include <bsd.port.mk>
