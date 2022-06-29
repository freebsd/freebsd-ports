# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	Math-BigInt-Lite
PORTVERSION=	0.25
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	What Math::BigInts are before they become big

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Math-BigRat>=0.2616:math/p5-Math-BigRat

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 503600
BUILD_DEPENDS+=	p5-Math-BigInt>=1.999819:math/p5-Math-BigInt
RUN_DEPENDS+=	p5-Math-BigInt>=1.999819:math/p5-Math-BigInt
.endif

.include <bsd.port.post.mk>
