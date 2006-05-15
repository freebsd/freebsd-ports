# New ports collection makefile for:	Math-Symbolic
# Date created:				15 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Symbolic
PORTVERSION=	0.502
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Symbolic calculations

BUILD_DEPENDS=	${SITE_PERL}/Memoize.pm:${PORTSDIR}/devel/p5-Memoize \
		${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent \
		${SITE_PERL}/${PERL_ARCH}/Data/Dumper.pm:${PORTSDIR}/devel/p5-Data-Dumper
RUN_DEPENDS=	${BUILD_DEPENDS}

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

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl 5.6 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
