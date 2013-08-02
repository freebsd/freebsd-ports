# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-Symbolic
PORTVERSION=	0.612
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SMUELLER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Symbolic calculations

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	Math::Symbolic.3 \
	Math::Symbolic::AuxFunctions.3 \
	Math::Symbolic::Base.3 \
	Math::Symbolic::Compiler.3 \
	Math::Symbolic::Constant.3 \
	Math::Symbolic::Custom.3 \
	Math::Symbolic::Custom::Base.3 \
	Math::Symbolic::Custom::DefaultDumpers.3 \
	Math::Symbolic::Custom::DefaultMods.3 \
	Math::Symbolic::Custom::DefaultTests.3 \
	Math::Symbolic::Derivative.3 \
	Math::Symbolic::ExportConstants.3 \
	Math::Symbolic::MiscAlgebra.3 \
	Math::Symbolic::MiscCalculus.3 \
	Math::Symbolic::Operator.3 \
	Math::Symbolic::Parser.3 \
	Math::Symbolic::Parser::Precompiled.3 \
	Math::Symbolic::Variable.3 \
	Math::Symbolic::VectorCalculus.3

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
