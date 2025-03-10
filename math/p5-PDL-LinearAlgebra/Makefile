PORTNAME=	PDL-LinearAlgebra
PORTVERSION=	0.433
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Linear Algebra utils for PDL
WWW=		https://metacpan.org/dist/PDL-LinearAlgebra

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/Artistic_2

BUILD_DEPENDS=	p5-Devel-CheckLib>=0:devel/p5-Devel-CheckLib \
		p5-ExtUtils-F77>=1.26:lang/p5-ExtUtils-F77 \
		p5-PkgConfig>=0:devel/p5-PkgConfig \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-PDL>=2.096:math/p5-PDL

USES=		blaslapack perl5
USE_PERL5=	configure

MAKE_JOBS_UNSAFE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/LinearAlgebra/Complex/Complex.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/LinearAlgebra/Real/Real.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/LinearAlgebra/Trans/Trans.so

.include <bsd.port.mk>
