PORTNAME=	PDL-IO-GD
PORTVERSION=	2.103
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Interface to the GD image library
WWW=		https://metacpan.org/dist/PDL-IO-GD

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libgd.so:graphics/gd
RUN_DEPENDS=	p5-PDL>=2.094:math/p5-PDL

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/IO/GD/GD.so

.include <bsd.port.mk>
