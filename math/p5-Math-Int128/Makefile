# Created by: Kurt Jaeger <fbsd-ports@opsec.eu>
# $FreeBSD$

PORTNAME=	Math-Int128
PORTVERSION=	0.22
PORTREVISION=	6
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Manipulate 128 bits integers in Perl

LICENSE=	ART10

NOT_FOR_ARCHS=	armv6 i386

BUILD_DEPENDS=	p5-Math-Int64>=0.51:math/p5-Math-Int64
RUN_DEPENDS=	p5-Math-Int64>=0.51:math/p5-Math-Int64

USES=		compiler:c11 perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/Int128/Int128.so

.include <bsd.port.mk>
