# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-Symbolic-Custom-Pattern
PORTVERSION=	2.01
PORTREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pattern matching on Math::Symbolic trees

BUILD_DEPENDS=	p5-Math-Symbolic>=0.510:math/p5-Math-Symbolic \
		p5-Clone>=0:devel/p5-Clone
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1.0:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.0:devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
