# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Math-BigRat
PORTVERSION=	0.2613
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Arbitrary big rational numbers

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502503
BUILD_DEPENDS+=	p5-Math-BigInt>=1.999718:math/p5-Math-BigInt
RUN_DEPENDS+=	p5-Math-BigInt>=1.999718:math/p5-Math-BigInt
.endif

.include <bsd.port.post.mk>
