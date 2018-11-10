# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Crypt-OpenSSL-ECDSA
PORTVERSION=	0.08
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for OpenSSL ECDSA

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BROKEN_FreeBSD_12=	unknown type name 'ECDSA_METHOD'; did you mean 'DSA_METHOD'?
BROKEN_FreeBSD_13=	unknown type name 'ECDSA_METHOD'; did you mean 'DSA_METHOD'?
BROKEN_SSL=	openssl111

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-OpenSSL-EC>=0.05:security/p5-Crypt-OpenSSL-EC

USES=		perl5 ssl
USE_PERL5=	configure

CFLAGS+=	-I${OPENSSLINC}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Crypt/OpenSSL/ECDSA/ECDSA.so

.include <bsd.port.mk>
