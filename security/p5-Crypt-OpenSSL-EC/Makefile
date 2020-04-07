# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Crypt-OpenSSL-EC
PORTVERSION=	1.32
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIKEM
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for OpenSSL EC (Elliptic Curves) library

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-OpenSSL-Bignum>=0.04:security/p5-Crypt-OpenSSL-Bignum

USES=		perl5 ssl
USE_PERL5=	configure

MAKE_ENV=	OPENSSL_PREFIX=${OPENSSLBASE}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Crypt/OpenSSL/EC/EC.so

.include <bsd.port.mk>
