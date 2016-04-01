# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-Symbolic-Custom-CCompiler
PORTVERSION=	1.04
PORTREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Compile Math::Symbolic trees to C

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Math-Symbolic>=0.509:math/p5-Math-Symbolic \
		p5-Inline>=0.44:devel/p5-Inline \
		p5-Inline-C>=0.44:devel/p5-Inline-C
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
