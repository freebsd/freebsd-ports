PORTNAME=	Math-GMP
PORTVERSION=	2.25
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module that provides an interface to the GMP library
WWW=		https://metacpan.org/release/Math-GMP

LICENSE=	LGPL20+

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		localbase perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/GMP/GMP.so

.include <bsd.port.mk>
