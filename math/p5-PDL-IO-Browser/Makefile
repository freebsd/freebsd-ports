PORTNAME=	PDL-IO-Browser
PORTVERSION=	0.001
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	2D data browser for PDL
WWW=		https://metacpan.org/dist/PDL-IO-Browser

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Devel-CheckLib>=0:devel/p5-Devel-CheckLib \
		p5-File-Which>=0:sysutils/p5-File-Which \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-PDL>=0:math/p5-PDL

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/IO/Browser/Browser.so

.include <bsd.port.mk>
