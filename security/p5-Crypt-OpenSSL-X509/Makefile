PORTNAME=	Crypt-OpenSSL-X509
PORTVERSION=	1.914
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for OpenSSL X509 API

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-OpenSSL-Guess>=0:security/p5-Crypt-OpenSSL-Guess \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Convert-ASN1>=0.33:converters/p5-Convert-ASN1
TEST_DEPENDS=	p5-Test-Pod>=1.00:devel/p5-Test-Pod

USES=		perl5 ssl
USE_PERL5=	configure

MAKE_ARGS=	PASTHRU_INC=-I${OPENSSLINC}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Crypt/OpenSSL/X509/X509.so

.include <bsd.port.mk>
