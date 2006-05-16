# ex:ts=8
# Ports collection makefile for:	Perl::Critic
# Date created:			Nov 26, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Perl-Critic
PORTVERSION=	0.16
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
		${SITE_PERL}/Module/Pluggable.pm:${PORTSDIR}/devel/p5-Module-Pluggable \
		${SITE_PERL}/Perl/Tidy.pm:${PORTSDIR}/devel/perltidy
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN1=	perlcritic.1
MAN3=	Perl::Critic.3 \
	Perl::Critic::Config.3 \
	Perl::Critic::DEVELOPER.3 \
	Perl::Critic::Policy.3 \
	Perl::Critic::Policy::BuiltinFunctions::ProhibitLvalueSubstr.3 \
	Perl::Critic::Policy::BuiltinFunctions::ProhibitSleepViaSelect.3 \
	Perl::Critic::Policy::BuiltinFunctions::ProhibitStringyEval.3 \
	Perl::Critic::Policy::BuiltinFunctions::RequireBlockGrep.3 \
	Perl::Critic::Policy::BuiltinFunctions::RequireBlockMap.3 \
	Perl::Critic::Policy::BuiltinFunctions::RequireGlobFunction.3 \
	Perl::Critic::Policy::BuiltinFunctions::ProhibitUniversalIsa.3 \
	Perl::Critic::Policy::BuiltinFunctions::ProhibitUniversalCan.3 \
	Perl::Critic::Policy::ClassHierarchies::ProhibitAutoloading.3 \
	Perl::Critic::Policy::ClassHierarchies::ProhibitExplicitISA.3 \
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
	Perl::Critic::Policy::ControlStructures::ProhibitUnreachableCode.3 \
	Perl::Critic::Policy::Documentation::RequirePodAtEnd.3 \
	Perl::Critic::Policy::Documentation::RequirePodSections.3 \
	Perl::Critic::Policy::InputOutput::ProhibitBacktickOperators.3 \
	Perl::Critic::Policy::InputOutput::ProhibitBarewordFileHandles.3 \
	Perl::Critic::Policy::InputOutput::ProhibitOneArgSelect.3 \
	Perl::Critic::Policy::InputOutput::ProhibitReadlineInForLoop.3 \
	Perl::Critic::Policy::InputOutput::ProhibitTwoArgOpen.3 \
	Perl::Critic::Policy::InputOutput::RequireBracedFileHandleWithPrint.3 \
	Perl::Critic::Policy::Miscellanea::ProhibitFormats.3 \
	Perl::Critic::Policy::Miscellanea::ProhibitTies.3 \
	Perl::Critic::Policy::Miscellanea::RequireRcsKeywords.3 \
	Perl::Critic::Policy::Modules::ProhibitAutomaticExportation.3 \
	Perl::Critic::Policy::Modules::ProhibitMultiplePackages.3 \
	Perl::Critic::Policy::Modules::RequireBarewordIncludes.3 \
	Perl::Critic::Policy::Modules::RequireExplicitPackage.3 \
	Perl::Critic::Policy::Modules::RequireVersionVar.3 \
	Perl::Critic::Policy::Modules::RequireEndWithOne.3 \
	Perl::Critic::Policy::Modules::ProhibitEvilModules.3 \
	Perl::Critic::Policy::NamingConventions::ProhibitMixedCaseSubs.3 \
	Perl::Critic::Policy::NamingConventions::ProhibitMixedCaseVars.3 \
	Perl::Critic::Policy::NamingConventions::ProhibitAmbiguousNames.3 \
	Perl::Critic::Policy::References::ProhibitDoubleSigils.3 \
	Perl::Critic::Policy::RegularExpressions::RequireExtendedFormatting.3 \
	Perl::Critic::Policy::RegularExpressions::RequireLineBoundaryMatching.3 \
	Perl::Critic::Policy::Subroutines::ProtectPrivateSubs.3 \
	Perl::Critic::Policy::Subroutines::ProhibitBuiltinHomonyms.3 \
	Perl::Critic::Policy::Subroutines::ProhibitExplicitReturnUndef.3 \
	Perl::Critic::Policy::Subroutines::ProhibitSubroutinePrototypes.3 \
	Perl::Critic::Policy::Subroutines::ProhibitExcessComplexity.3 \
	Perl::Critic::Policy::Subroutines::RequireFinalReturn.3 \
	Perl::Critic::Policy::Subroutines::ProhibitAmpersandSigils.3 \
	Perl::Critic::Policy::TestingAndDebugging::ProhibitNoStrict.3 \
	Perl::Critic::Policy::TestingAndDebugging::ProhibitNoWarnings.3 \
	Perl::Critic::Policy::TestingAndDebugging::RequireUseStrict.3 \
	Perl::Critic::Policy::TestingAndDebugging::RequireUseWarnings.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitConstantPragma.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitEmptyQuotes.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitInterpolationOfLiterals.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitLeadingZeros.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitMixedBooleanOperators.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitNoisyQuotes.3 \
	Perl::Critic::Policy::ValuesAndExpressions::RequireInterpolationOfMetachars.3 \
	Perl::Critic::Policy::ValuesAndExpressions::RequireNumberSeparators.3 \
	Perl::Critic::Policy::ValuesAndExpressions::RequireQuotedHeredocTerminator.3 \
	Perl::Critic::Policy::ValuesAndExpressions::RequireUpperCaseHeredocTerminator.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitVersionStrings.3 \
	Perl::Critic::Policy::Variables::ProhibitLocalVars.3 \
	Perl::Critic::Policy::Variables::ProhibitPackageVars.3 \
	Perl::Critic::Policy::Variables::ProhibitPunctuationVars.3 \
	Perl::Critic::Policy::Variables::ProtectPrivateVars.3 \
	Perl::Critic::Policy::Variables::ProhibitMatchVars.3 \
	Perl::Critic::Policy::Variables::ProhibitConditionalDeclarations.3 \
	Perl::Critic::Policy::Variables::RequireInitializationForLocalVars.3 \
	Perl::Critic::Utils.3 \
	Perl::Critic::Violation.3

.include <bsd.port.mk>
