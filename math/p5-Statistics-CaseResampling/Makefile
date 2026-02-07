PORTNAME=	Statistics-CaseResampling
PORTVERSION=	0.17
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Efficient resampling and calculation of medians with confidence intervals
WWW=		https://metacpan.org/release/Statistics-CaseResampling

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Statistics/CaseResampling/CaseResampling.so

.include <bsd.port.mk>
