PORTNAME=	PDL-Transform-Proj4
PORTVERSION=	2.098
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PDL::Transform interface to the Proj4 projection library
WWW=		https://metacpan.org/dist/PDL-Transform-Proj4

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny \
		${RUN_DEPENDS}
LIB_DEPENDS=	libproj.so:graphics/proj
RUN_DEPENDS=	p5-PDL>=2.096:math/p5-PDL

USES=		localbase perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Transform/Proj4/Proj4.so

.include <bsd.port.mk>
