# Created by: nork@cityfujisawa.ne.jp
# $FreeBSD$

PORTNAME=	Crypt-OpenSSL-Random
PORTVERSION=	0.06
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RURBAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to the OpenSSL pseudo-random number generator

USES=		perl5
USE_PERL5=	configure
USE_OPENSSL=	yes
MAKE_ARGS+=	PASTHRU_INC=-I${OPENSSLINC}

.include <bsd.port.mk>
