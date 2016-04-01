# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MaxMind-DB-Reader
PORTVERSION=	1.000009
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MAXMIND
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read MaxMind DB files

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Data-IEEE754>=0:devel/p5-Data-IEEE754 \
		p5-Data-Printer>=0:devel/p5-Data-Printer \
		p5-Data-Validate-IP>=0.16:net-mgmt/p5-Data-Validate-IP \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-List-AllUtils>=0:devel/p5-List-AllUtils \
		p5-MaxMind-DB-Common>=0.040000:net/p5-MaxMind-DB-Common \
		p5-Module-Implementation>=0:devel/p5-Module-Implementation \
		p5-Moo>=1.003000:devel/p5-Moo \
		p5-MooX-StrictConstructor>=0:devel/p5-MooX-StrictConstructor \
		p5-Role-Tiny>=0:devel/p5-Role-Tiny \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Path-Class>=0.27:devel/p5-Path-Class \
		p5-Test-Bits>=0:devel/p5-Test-Bits \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Number-Delta>=0:devel/p5-Test-Number-Delta \
		p5-Test-Requires>=0:devel/p5-Test-Requires

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502300
TEST_DEPENDS+=	p5-Scalar-List-Utils>=1.42:lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
