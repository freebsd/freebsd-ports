PORTNAME=	Crypt-OpenSSL-Verify
PORTVERSION=	0.38
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TIMLEGGE
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenSSL Verify certificate verification in XS
WWW=		https://metacpan.org/dist/Crypt-OpenSSL-Verify

LICENSE=	OpenSSL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Crypt-OpenSSL-Guess>=0:security/p5-Crypt-OpenSSL-Guess \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-OpenSSL-X509>=2.0.1:security/p5-Crypt-OpenSSL-X509

USES=		perl5 ssl
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Crypt/OpenSSL/Verify/Verify.so

.include <bsd.port.mk>
