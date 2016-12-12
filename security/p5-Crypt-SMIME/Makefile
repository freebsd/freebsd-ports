# $FreeBSD$

PORTNAME=	Crypt-SMIME
PORTVERSION=	0.19
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	S/MIME message signing, verification, encryption and decryption

LICENSE=	ART10

BUILD_DEPENDS=	p5-ExtUtils-CChecker>=0:devel/p5-ExtUtils-CChecker \
		p5-ExtUtils-PkgConfig>=0:devel/p5-ExtUtils-PkgConfig
TEST_DEPENDS=	p5-Taint-Util>=0:devel/p5-Taint-Util \
		p5-Test-Dependencies>=0:devel/p5-Test-Dependencies \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Pod>=1.14:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.04:devel/p5-Test-Pod-Coverage \
		p5-Test-Taint>=0:devel/p5-Test-Taint

CONFIGURE_ENV=	LIBCRYPTO_CFLAGS="-I${OPENSSLINC}" LIBCRYPTO_LIBS="-L${OPENSSLLIB} -lcrypto"
USE_PERL5=	configure
USES=		perl5 ssl

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Crypt/SMIME/SMIME.so

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000015 && ${SSL_DEFAULT:Mbase}
IGNORE=	Need a more recent version of OpenSSL.
.endif

.include <bsd.port.post.mk>
