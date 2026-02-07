PORTNAME=	Algorithm-Combinatorics
PORTVERSION=	0.27
PORTREVISION=	3
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
#MASTER_SITE_SUBDIR=	CPAN:FXN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Efficient generation of combinatorial sequences
WWW=		https://metacpan.org/release/Algorithm-Combinatorics

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Algorithm/Combinatorics/Combinatorics.so

.include <bsd.port.mk>
