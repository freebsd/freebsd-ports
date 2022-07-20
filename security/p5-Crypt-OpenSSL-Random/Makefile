PORTNAME=	Crypt-OpenSSL-Random
PORTVERSION=	0.15
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RURBAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to the OpenSSL pseudo-random number generator

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Crypt-OpenSSL-Guess>=0.11:security/p5-Crypt-OpenSSL-Guess

USES=		perl5 ssl
USE_PERL5=	configure

MAKE_ARGS=	PASTHRU_INC=-I${OPENSSLINC}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Crypt/OpenSSL/Random/Random.so

.include <bsd.port.mk>
