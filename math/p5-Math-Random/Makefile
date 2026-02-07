PORTNAME=	Math-Random
PORTVERSION=	0.75
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Random number generators
WWW=		https://metacpan.org/release/Math-Random

USES=		perl5 shebangfix
USE_PERL5=	configure

SHEBANG_FILES=	example.pl

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/Random/Random.so

.include <bsd.port.mk>
