PORTNAME=	PDL-Graphics-PLplot
PORTVERSION=	0.84
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Object-oriented interface from perl/PDL to the PLPLOT plotting library
WWW=		https://metacpan.org/dist/PDL-Graphics-PLplot

BUILD_DEPENDS=	p5-Devel-CheckLib>=0:devel/p5-Devel-CheckLib \
		${RUN_DEPENDS}
LIB_DEPENDS=	libplplot.so:math/plplot
RUN_DEPENDS=	p5-PDL>=2.083:math/p5-PDL

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Graphics/PLplot/PLplot.so

.include <bsd.port.mk>
