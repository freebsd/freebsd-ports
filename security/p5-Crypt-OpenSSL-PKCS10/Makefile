PORTNAME=	Crypt-OpenSSL-PKCS10
PORTVERSION=	0.25
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Perl extension for OpenSSL PKCS10 API
WWW=		https://metacpan.org/release/Crypt-OpenSSL-PKCS10

LICENSE=	ART10

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-OpenSSL-RSA>=0:security/p5-Crypt-OpenSSL-RSA \
		p5-Crypt-OpenSSL-Guess>=0:security/p5-Crypt-OpenSSL-Guess

USES=		perl5 ssl
USE_PERL5=	configure
MAKE_ARGS+=	PASTHRU_INC=-I${OPENSSLINC}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
