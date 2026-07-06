PORTNAME=	CryptX
PORTVERSION=	0.090
CATEGORIES=	security perl5
MASTER_SITES=	CPAN/Crypt
MASTER_SITE_SUBDIR=	CPAN:MIK
PKGNAMEPREFIX=	p5-

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Crypto toolkit
WWW=		https://metacpan.org/dist/CryptX

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-JSON>=0:converters/p5-JSON \
		p5-Math-BigInt>=2.005003:math/p5-Math-BigInt

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/CryptX/CryptX.so

.include <bsd.port.mk>
