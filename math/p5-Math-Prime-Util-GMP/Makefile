PORTNAME=	Math-Prime-Util-GMP
PORTVERSION=	0.53
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DANAJ
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utilities related to prime numbers and factoring, using GMP
WWW=		https://metacpan.org/release/Math-Prime-Util-GMP

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		localbase perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/Prime/Util/GMP/GMP.so

.include <bsd.port.mk>
