# $FreeBSD$

PORTNAME=	Digest-GOST
PORTVERSION=	0.06
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Perl interface to the GOST R 34.11-94 digest algorithm

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

NOT_FOR_ARCHS=		aarch64 armv6 armv7 mips64
NOT_FOR_ARCHS_REASON=	fails to build: Cannot detect CPU architechture

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${SITE_ARCH}/auto/Digest/GOST/GOST.so

.include <bsd.port.mk>
