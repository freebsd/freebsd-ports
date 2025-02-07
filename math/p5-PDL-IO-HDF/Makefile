PORTNAME=	PDL-IO-HDF
PORTVERSION=	2.003
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PDL interface to the HDF4 library
WWW=		https://metacpan.org/dist/PDL-IO-HDF

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0.4020:devel/p5-ExtUtils-Depends \
		${RUN_DEPENDS}
LIB_DEPENDS=	libdf.so:science/hdf
RUN_DEPENDS=	p5-PDL>=2.094:math/p5-PDL

USES=		localbase perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/IO/HDF/SD/SD.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/IO/HDF/VS/VS.so

.include <bsd.port.mk>
