# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-BigInt-Lite
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	What Math::BigInts are before they become big

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502508
BUILD_DEPENDS+=	p5-Math-BigInt>=1.999801:math/p5-Math-BigInt
RUN_DEPENDS+=	p5-Math-BigInt>=1.999801:math/p5-Math-BigInt
.endif

.include <bsd.port.post.mk>
