# Created by: Kurt Jaeger <fbsd-ports@opsec.eu>
# $FreeBSD$

PORTNAME=	Math-Int128
PORTVERSION=	0.22
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Manipulate 128 bits integers in Perl

LICENSE=	ART10

BUILD_DEPENDS=	p5-Math-Int64>=0.51:math/p5-Math-Int64
RUN_DEPENDS=	p5-Math-Int64>=0.51:math/p5-Math-Int64

USES=		perl5
USE_PERL5=	configure

NOT_FOR_ARCHS=	i386 armv6

.include <bsd.port.pre.mk>

# need clang 3.2+ or GCC 4.4+
.if exists(/usr/bin/clang)
CC=	/usr/bin/clang
.else
USE_GCC=	yes
.endif

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/Int128/Int128.so

.include <bsd.port.post.mk>
