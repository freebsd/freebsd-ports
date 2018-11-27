# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Math-Random-MT-Auto
PORTVERSION=	6.23
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Auto-seeded Mersenne Twister PRNGs

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Exception-Class>=1.32:devel/p5-Exception-Class \
		p5-Object-InsideOut>=3.88:devel/p5-Object-InsideOut
TEST_DEPENDS=	p5-libwww>=0:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/Random/MT/Auto/Auto.so

.include <bsd.port.mk>
