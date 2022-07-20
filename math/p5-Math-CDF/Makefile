PORTNAME=	Math-CDF
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate probabilities and quantiles

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/CDF/CDF.so

.include <bsd.port.mk>
