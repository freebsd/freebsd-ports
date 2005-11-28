# ex:ts=8
# Ports collection makefile for:	Perl::Critic
# Date created:			Nov 26, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Perl-Critic
PORTVERSION=	0.13
CATEGORIES=	textproc devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Perl
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Critique Perl source for style and standards

BUILD_DEPENDS=	${SITE_PERL}/Config/Tiny.pm:${PORTSDIR}/devel/p5-Config-Tiny \
		${SITE_PERL}/${PERL_ARCH}/List/MoreUtils.pm:${PORTSDIR}/lang/p5-List-MoreUtils \
		${SITE_PERL}/PPI.pm:${PORTSDIR}/textproc/p5-PPI \
		${SITE_PERL}/String/Format.pm:${PORTSDIR}/textproc/p5-String-Format \
		${SITE_PERL}/Perl/Tidy.pm:${PORTSDIR}/devel/perltidy
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN1=	perlcritic.1
MAN3=	Perl::Critic.3 \
	Perl::Critic::Config.3 \
	Perl::Critic::Policy.3 \
	Perl::Critic::Policy::BuiltinFunctions::ProhibitLvalueSubstr.3 \
	Perl::Critic::Policy::BuiltinFunctions::ProhibitSleepViaSelect.3 \
	Perl::Critic::Policy::BuiltinFunctions::ProhibitStringyEval.3 \
	Perl::Critic::Policy::BuiltinFunctions::RequireBlockGrep.3 \
	Perl::Critic::Policy::BuiltinFunctions::RequireBlockMap.3 \
	Perl::Critic::Policy::BuiltinFunctions::RequireGlobFunction.3 \
	Perl::Critic::Policy::ClassHierarchies::ProhibitOneArgBless.3 \
	Perl::Critic::Policy::CodeLayout::ProhibitHardTabs.3 \
	Perl::Critic::Policy::CodeLayout::ProhibitParensWithBuiltins.3 \
	Perl::Critic::Policy::CodeLayout::ProhibitQuotedWordLists.3 \
	Perl::Critic::Policy::CodeLayout::RequireTidyCode.3 \
	Perl::Critic::Policy::CodeLayout::RequireTrailingCommas.3 \
	Perl::Critic::Policy::ControlStructures::ProhibitCStyleForLoops.3 \
	Perl::Critic::Policy::ControlStructures::ProhibitCascadingIfElse.3 \
	Perl::Critic::Policy::ControlStructures::ProhibitPostfixControls.3 \
	Perl::Critic::Policy::ControlStructures::ProhibitUnlessBlocks.3 \
	Perl::Critic::Policy::ControlStructures::ProhibitUntilBlocks.3 \
	Perl::Critic::Policy::InputOutput::ProhibitBacktickOperators.3 \
	Perl::Critic::Policy::InputOutput::ProhibitBarewordFileHandles.3 \
	Perl::Critic::Policy::InputOutput::ProhibitOneArgSelect.3 \
	Perl::Critic::Policy::InputOutput::ProhibitTwoArgOpen.3 \
	Perl::Critic::Policy::Miscellanea::RequireRcsKeywords.3 \
	Perl::Critic::Policy::Modules::ProhibitMultiplePackages.3 \
	Perl::Critic::Policy::Modules::ProhibitSpecificModules.3 \
	Perl::Critic::Policy::Modules::RequireBarewordIncludes.3 \
	Perl::Critic::Policy::Modules::RequireExplicitPackage.3 \
	Perl::Critic::Policy::Modules::RequireVersionVar.3 \
	Perl::Critic::Policy::NamingConventions::ProhibitMixedCaseSubs.3 \
	Perl::Critic::Policy::NamingConventions::ProhibitMixedCaseVars.3 \
	Perl::Critic::Policy::RegularExpressions::RequireExtendedFormatting.3 \
	Perl::Critic::Policy::RegularExpressions::RequireLineBoundaryMatching.3 \
	Perl::Critic::Policy::Subroutines::ProhibitBuiltinHomonyms.3 \
	Perl::Critic::Policy::Subroutines::ProhibitExplicitReturnUndef.3 \
	Perl::Critic::Policy::Subroutines::ProhibitSubroutinePrototypes.3 \
	Perl::Critic::Policy::TestingAndDebugging::RequirePackageStricture.3 \
	Perl::Critic::Policy::TestingAndDebugging::RequirePackageWarnings.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitConstantPragma.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitEmptyQuotes.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitInterpolationOfLiterals.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitLeadingZeros.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitNoisyQuotes.3 \
	Perl::Critic::Policy::ValuesAndExpressions::RequireInterpolationOfMetachars.3 \
	Perl::Critic::Policy::ValuesAndExpressions::RequireNumberSeparators.3 \
	Perl::Critic::Policy::ValuesAndExpressions::RequireQuotedHeredocTerminator.3 \
	Perl::Critic::Policy::ValuesAndExpressions::RequireUpperCaseHeredocTerminator.3 \
	Perl::Critic::Policy::Variables::ProhibitLocalVars.3 \
	Perl::Critic::Policy::Variables::ProhibitPackageVars.3 \
	Perl::Critic::Policy::Variables::ProhibitPunctuationVars.3 \
	Perl::Critic::Utils.3 \
	Perl::Critic::Violation.3

.include <bsd.port.mk>
