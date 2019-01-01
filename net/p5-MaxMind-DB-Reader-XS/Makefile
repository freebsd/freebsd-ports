# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MaxMind-DB-Reader-XS
PORTVERSION=	1.000007
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MAXMIND
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast XS implementation of MaxMind DB reader

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
RUN_DEPENDS=	p5-Math-Int128>=0:math/p5-Math-Int128 \
		p5-Math-Int64>=0:math/p5-Math-Int64 \
		p5-MaxMind-DB-Common>=0.040001:net/p5-MaxMind-DB-Common \
		p5-MaxMind-DB-Reader>=1.000012:net/p5-MaxMind-DB-Reader \
		p5-Moo>=0:devel/p5-Moo \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
TEST_DEPENDS=	p5-Module-Implementation>=0:devel/p5-Module-Implementation \
		p5-Net-Works>=0.21:net/p5-Net-Works \
		p5-Path-Class>=0.27:devel/p5-Path-Class \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Number-Delta>=0:devel/p5-Test-Number-Delta \
		p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/MaxMind/DB/Reader/XS/XS.so

.include <bsd.port.mk>
