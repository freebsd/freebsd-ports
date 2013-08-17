# Created by: Kurt Jaeger <fbsd-ports@opsec.eu>
# $FreeBSD$
#

PORTNAME=	Math-Int128
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	Manipulate 128 bits integers in Perl

LICENSE=	ART10

BUILD_DEPENDS=  p5-Math-Int64>=0.28:${PORTSDIR}/math/p5-Math-Int64
RUN_DEPENDS=    p5-Math-Int64>=0.28:${PORTSDIR}/math/p5-Math-Int64

USES=		perl5
USE_PERL5=	configure

USE_GCC=	yes

MAN3=		Math::Int128.3 \
		Math::Int128::die_on_overflow.3

.include <bsd.port.mk>
