# Created by: will
# $FreeBSD$

PORTNAME=	Math-Currency
PORTVERSION=	0.52
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for exact currency math with formatting and rounding

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Math-FixedPrecision>=0:math/p5-Math-FixedPrecision
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-More-UTF8>=0:devel/p5-Test-More-UTF8

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
