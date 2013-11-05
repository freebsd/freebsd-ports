# Created by: ijliao
# $FreeBSD$

PORTNAME=	Task-Math-Symbolic
PORTVERSION=	1.01
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SMUELLER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Math::Symbolic with lots of plugins

RUN_DEPENDS=	p5-Math-Symbolic>=0.163:${PORTSDIR}/math/p5-Math-Symbolic \
		p5-Math-Symbolic-Custom-CCompiler>=0:${PORTSDIR}/math/p5-Math-Symbolic-Custom-CCompiler \
		p5-Math-Symbolic-Custom-Contains>=0:${PORTSDIR}/math/p5-Math-Symbolic-Custom-Contains \
		p5-Math-Symbolic-Custom-ErrorPropagation>=0:${PORTSDIR}/math/p5-Math-Symbolic-Custom-ErrorPropagation \
		p5-Math-Symbolic-Custom-Pattern>=0:${PORTSDIR}/math/p5-Math-Symbolic-Custom-Pattern \
		p5-Math-Symbolic-Custom-Simplification>=0:${PORTSDIR}/math/p5-Math-Symbolic-Custom-Simplification \
		p5-Math-Symbolic-Custom-Transformation>=0:${PORTSDIR}/math/p5-Math-Symbolic-Custom-Transformation \
		p5-Math-SymbolicX-BigNum>=0:${PORTSDIR}/math/p5-Math-SymbolicX-BigNum \
		p5-Math-SymbolicX-Complex>=0:${PORTSDIR}/math/p5-Math-SymbolicX-Complex \
		p5-Math-SymbolicX-Inline>=0:${PORTSDIR}/math/p5-Math-SymbolicX-Inline \
		p5-Math-SymbolicX-NoSimplification>=0:${PORTSDIR}/math/p5-Math-SymbolicX-NoSimplification \
		p5-Math-SymbolicX-ParserExtensionFactory>=0:${PORTSDIR}/math/p5-Math-SymbolicX-ParserExtensionFactory \
		p5-Math-SymbolicX-Statistics-Distributions>=0:${PORTSDIR}/math/p5-Math-SymbolicX-Statistics-Distributions
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
