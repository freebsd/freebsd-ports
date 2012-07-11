# Ports collection makefile for:	Perl::Critic
# Date created:			Nov 26, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Perl-Critic
PORTVERSION=	1.11.8
CATEGORIES=	textproc devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Critique Perl source for style and standards

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-B-Keywords>=1.05:${PORTSDIR}/devel/p5-B-Keywords \
		p5-Config-Tiny>=2:${PORTSDIR}/devel/p5-Config-Tiny \
		p5-Email-Address>=1.88.9:${PORTSDIR}/mail/p5-Email-Address \
		p5-Exception-Class>=1.23:${PORTSDIR}/devel/p5-Exception-Class \
		p5-File-HomeDir>=0:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-File-Which>=0:${PORTSDIR}/sysutils/p5-File-Which \
		p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		p5-List-MoreUtils>=0.19:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Pod-Spell>=0:${PORTSDIR}/textproc/p5-Pod-Spell \
		p5-PPI>=1.215:${PORTSDIR}/textproc/p5-PPI \
		p5-PPIx-Regexp>=0.027:${PORTSDIR}/textproc/p5-PPIx-Regexp \
		p5-PPIx-Utilities>=1.001:${PORTSDIR}/textproc/p5-PPIx-Utilities \
		p5-Readonly>=1.03:${PORTSDIR}/devel/p5-Readonly \
		p5-String-Format>=1.13:${PORTSDIR}/textproc/p5-String-Format \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-Term-ANSIColor>=2.02:${PORTSDIR}/devel/p5-Term-ANSIColor \
		perltidy:${PORTSDIR}/devel/perltidy
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Memory-Cycle>=0:${PORTSDIR}/devel/p5-Test-Memory-Cycle

PERL_MODBUILD=	yes

MAN1=	perlcritic.1
MAN3=	Perl::Critic.3 \
	Perl::Critic::Annotation.3 \
	Perl::Critic::CORE_DEVELOPER.3 \
	Perl::Critic::Command.3 \
	Perl::Critic::Config.3 \
	Perl::Critic::DEVELOPER.3 \
	Perl::Critic::Document.3 \
	Perl::Critic::Exception.3 \
	Perl::Critic::Exception::AggregateConfiguration.3 \
	Perl::Critic::Exception::Configuration.3 \
	Perl::Critic::Exception::Configuration::Generic.3 \
	Perl::Critic::Exception::Configuration::NonExistentPolicy.3 \
	Perl::Critic::Exception::Configuration::Option.3 \
	Perl::Critic::Exception::Configuration::Option::Global.3 \
	Perl::Critic::Exception::Configuration::Option::Global::ExtraParameter.3 \
	Perl::Critic::Exception::Configuration::Option::Global::ParameterValue.3 \
	Perl::Critic::Exception::Configuration::Option::Policy.3 \
	Perl::Critic::Exception::Configuration::Option::Policy::ExtraParameter.3 \
	Perl::Critic::Exception::Configuration::Option::Policy::ParameterValue.3 \
	Perl::Critic::Exception::Fatal.3 \
	Perl::Critic::Exception::Fatal::Generic.3 \
	Perl::Critic::Exception::Fatal::Internal.3 \
	Perl::Critic::Exception::Fatal::PolicyDefinition.3 \
	Perl::Critic::Exception::IO.3 \
	Perl::Critic::Exception::Parse.3 \
	Perl::Critic::OptionsProcessor.3 \
	Perl::Critic::Policy.3 \
	Perl::Critic::Policy::BuiltinFunctions::ProhibitBooleanGrep.3 \
	Perl::Critic::Policy::BuiltinFunctions::ProhibitComplexMappings.3 \
	Perl::Critic::Policy::BuiltinFunctions::ProhibitLvalueSubstr.3 \
	Perl::Critic::Policy::BuiltinFunctions::ProhibitReverseSortBlock.3 \
	Perl::Critic::Policy::BuiltinFunctions::ProhibitSleepViaSelect.3 \
	Perl::Critic::Policy::BuiltinFunctions::ProhibitStringyEval.3 \
	Perl::Critic::Policy::BuiltinFunctions::ProhibitStringySplit.3 \
	Perl::Critic::Policy::BuiltinFunctions::ProhibitUniversalCan.3 \
	Perl::Critic::Policy::BuiltinFunctions::ProhibitUniversalIsa.3 \
	Perl::Critic::Policy::BuiltinFunctions::ProhibitVoidGrep.3 \
	Perl::Critic::Policy::BuiltinFunctions::ProhibitVoidMap.3 \
	Perl::Critic::Policy::BuiltinFunctions::RequireBlockGrep.3 \
	Perl::Critic::Policy::BuiltinFunctions::RequireBlockMap.3 \
	Perl::Critic::Policy::BuiltinFunctions::RequireGlobFunction.3 \
	Perl::Critic::Policy::BuiltinFunctions::RequireSimpleSortBlock.3 \
	Perl::Critic::Policy::ClassHierarchies::ProhibitAutoloading.3 \
	Perl::Critic::Policy::ClassHierarchies::ProhibitExplicitISA.3 \
	Perl::Critic::Policy::ClassHierarchies::ProhibitOneArgBless.3 \
	Perl::Critic::Policy::CodeLayout::ProhibitHardTabs.3 \
	Perl::Critic::Policy::CodeLayout::ProhibitParensWithBuiltins.3 \
	Perl::Critic::Policy::CodeLayout::ProhibitQuotedWordLists.3 \
	Perl::Critic::Policy::CodeLayout::ProhibitTrailingWhitespace.3 \
	Perl::Critic::Policy::CodeLayout::RequireConsistentNewlines.3 \
	Perl::Critic::Policy::CodeLayout::RequireTidyCode.3 \
	Perl::Critic::Policy::CodeLayout::RequireTrailingCommas.3 \
	Perl::Critic::Policy::ControlStructures::ProhibitCStyleForLoops.3 \
	Perl::Critic::Policy::ControlStructures::ProhibitCascadingIfElse.3 \
	Perl::Critic::Policy::ControlStructures::ProhibitDeepNests.3 \
	Perl::Critic::Policy::ControlStructures::ProhibitLabelsWithSpecialBlockNames.3 \
	Perl::Critic::Policy::ControlStructures::ProhibitMutatingListFunctions.3 \
	Perl::Critic::Policy::ControlStructures::ProhibitNegativeExpressionsInUnlessAndUntilConditions.3 \
	Perl::Critic::Policy::ControlStructures::ProhibitPostfixControls.3 \
	Perl::Critic::Policy::ControlStructures::ProhibitUnlessBlocks.3 \
	Perl::Critic::Policy::ControlStructures::ProhibitUnreachableCode.3 \
	Perl::Critic::Policy::ControlStructures::ProhibitUntilBlocks.3 \
	Perl::Critic::Policy::Documentation::PodSpelling.3 \
	Perl::Critic::Policy::Documentation::RequirePackageMatchesPodName.3 \
	Perl::Critic::Policy::Documentation::RequirePodAtEnd.3 \
	Perl::Critic::Policy::Documentation::RequirePodLinksIncludeText.3 \
	Perl::Critic::Policy::Documentation::RequirePodSections.3 \
	Perl::Critic::Policy::ErrorHandling::RequireCarping.3 \
	Perl::Critic::Policy::ErrorHandling::RequireCheckingReturnValueOfEval.3 \
	Perl::Critic::Policy::InputOutput::ProhibitBacktickOperators.3 \
	Perl::Critic::Policy::InputOutput::ProhibitBarewordFileHandles.3 \
	Perl::Critic::Policy::InputOutput::ProhibitExplicitStdin.3 \
	Perl::Critic::Policy::InputOutput::ProhibitInteractiveTest.3 \
	Perl::Critic::Policy::InputOutput::ProhibitJoinedReadline.3 \
	Perl::Critic::Policy::InputOutput::ProhibitOneArgSelect.3 \
	Perl::Critic::Policy::InputOutput::ProhibitReadlineInForLoop.3 \
	Perl::Critic::Policy::InputOutput::ProhibitTwoArgOpen.3 \
	Perl::Critic::Policy::InputOutput::RequireBracedFileHandleWithPrint.3 \
	Perl::Critic::Policy::InputOutput::RequireBriefOpen.3 \
	Perl::Critic::Policy::InputOutput::RequireCheckedClose.3 \
	Perl::Critic::Policy::InputOutput::RequireCheckedOpen.3 \
	Perl::Critic::Policy::InputOutput::RequireCheckedSyscalls.3 \
	Perl::Critic::Policy::InputOutput::RequireEncodingWithUTF8Layer.3 \
	Perl::Critic::Policy::Miscellanea::ProhibitFormats.3 \
	Perl::Critic::Policy::Miscellanea::ProhibitTies.3 \
	Perl::Critic::Policy::Miscellanea::ProhibitUnrestrictedNoCritic.3 \
	Perl::Critic::Policy::Miscellanea::ProhibitUselessNoCritic.3 \
	Perl::Critic::Policy::Modules::ProhibitAutomaticExportation.3 \
	Perl::Critic::Policy::Modules::ProhibitConditionalUseStatements.3 \
	Perl::Critic::Policy::Modules::ProhibitEvilModules.3 \
	Perl::Critic::Policy::Modules::ProhibitExcessMainComplexity.3 \
	Perl::Critic::Policy::Modules::ProhibitMultiplePackages.3 \
	Perl::Critic::Policy::Modules::RequireBarewordIncludes.3 \
	Perl::Critic::Policy::Modules::RequireEndWithOne.3 \
	Perl::Critic::Policy::Modules::RequireExplicitPackage.3 \
	Perl::Critic::Policy::Modules::RequireFilenameMatchesPackage.3 \
	Perl::Critic::Policy::Modules::RequireNoMatchVarsWithUseEnglish.3 \
	Perl::Critic::Policy::Modules::RequireVersionVar.3 \
	Perl::Critic::Policy::NamingConventions::Capitalization.3 \
	Perl::Critic::Policy::NamingConventions::ProhibitAmbiguousNames.3 \
	Perl::Critic::Policy::Objects::ProhibitIndirectSyntax.3 \
	Perl::Critic::Policy::References::ProhibitDoubleSigils.3 \
	Perl::Critic::Policy::RegularExpressions::ProhibitCaptureWithoutTest.3 \
	Perl::Critic::Policy::RegularExpressions::ProhibitComplexRegexes.3 \
	Perl::Critic::Policy::RegularExpressions::ProhibitEnumeratedClasses.3 \
	Perl::Critic::Policy::RegularExpressions::ProhibitEscapedMetacharacters.3 \
	Perl::Critic::Policy::RegularExpressions::ProhibitFixedStringMatches.3 \
	Perl::Critic::Policy::RegularExpressions::ProhibitSingleCharAlternation.3 \
	Perl::Critic::Policy::RegularExpressions::ProhibitUnusedCapture.3 \
	Perl::Critic::Policy::RegularExpressions::ProhibitUnusualDelimiters.3 \
	Perl::Critic::Policy::RegularExpressions::RequireBracesForMultiline.3 \
	Perl::Critic::Policy::RegularExpressions::RequireDotMatchAnything.3 \
	Perl::Critic::Policy::RegularExpressions::RequireExtendedFormatting.3 \
	Perl::Critic::Policy::RegularExpressions::RequireLineBoundaryMatching.3 \
	Perl::Critic::Policy::Subroutines::ProhibitAmpersandSigils.3 \
	Perl::Critic::Policy::Subroutines::ProhibitBuiltinHomonyms.3 \
	Perl::Critic::Policy::Subroutines::ProhibitExcessComplexity.3 \
	Perl::Critic::Policy::Subroutines::ProhibitExplicitReturnUndef.3 \
	Perl::Critic::Policy::Subroutines::ProhibitManyArgs.3 \
	Perl::Critic::Policy::Subroutines::ProhibitNestedSubs.3 \
	Perl::Critic::Policy::Subroutines::ProhibitReturnSort.3 \
	Perl::Critic::Policy::Subroutines::ProhibitSubroutinePrototypes.3 \
	Perl::Critic::Policy::Subroutines::ProhibitUnusedPrivateSubroutines.3 \
	Perl::Critic::Policy::Subroutines::ProtectPrivateSubs.3 \
	Perl::Critic::Policy::Subroutines::RequireArgUnpacking.3 \
	Perl::Critic::Policy::Subroutines::RequireFinalReturn.3 \
	Perl::Critic::Policy::TestingAndDebugging::ProhibitNoStrict.3 \
	Perl::Critic::Policy::TestingAndDebugging::ProhibitNoWarnings.3 \
	Perl::Critic::Policy::TestingAndDebugging::ProhibitProlongedStrictureOverride.3 \
	Perl::Critic::Policy::TestingAndDebugging::RequireTestLabels.3 \
	Perl::Critic::Policy::TestingAndDebugging::RequireUseStrict.3 \
	Perl::Critic::Policy::TestingAndDebugging::RequireUseWarnings.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitCommaSeparatedStatements.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitComplexVersion.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitConstantPragma.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitEmptyQuotes.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitEscapedCharacters.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitImplicitNewlines.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitInterpolationOfLiterals.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitLeadingZeros.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitLongChainsOfMethodCalls.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitMagicNumbers.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitMismatchedOperators.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitMixedBooleanOperators.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitNoisyQuotes.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitQuotesAsQuotelikeOperatorDelimiters.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitSpecialLiteralHeredocTerminator.3 \
	Perl::Critic::Policy::ValuesAndExpressions::ProhibitVersionStrings.3 \
	Perl::Critic::Policy::ValuesAndExpressions::RequireConstantVersion.3 \
	Perl::Critic::Policy::ValuesAndExpressions::RequireInterpolationOfMetachars.3 \
	Perl::Critic::Policy::ValuesAndExpressions::RequireNumberSeparators.3 \
	Perl::Critic::Policy::ValuesAndExpressions::RequireQuotedHeredocTerminator.3 \
	Perl::Critic::Policy::ValuesAndExpressions::RequireUpperCaseHeredocTerminator.3 \
	Perl::Critic::Policy::Variables::ProhibitAugmentedAssignmentInDeclaration.3 \
	Perl::Critic::Policy::Variables::ProhibitConditionalDeclarations.3 \
	Perl::Critic::Policy::Variables::ProhibitEvilVariables.3 \
	Perl::Critic::Policy::Variables::ProhibitLocalVars.3 \
	Perl::Critic::Policy::Variables::ProhibitMatchVars.3 \
	Perl::Critic::Policy::Variables::ProhibitPackageVars.3 \
	Perl::Critic::Policy::Variables::ProhibitPerl4PackageNames.3 \
	Perl::Critic::Policy::Variables::ProhibitPunctuationVars.3 \
	Perl::Critic::Policy::Variables::ProhibitReusedNames.3 \
	Perl::Critic::Policy::Variables::ProhibitUnusedVariables.3 \
	Perl::Critic::Policy::Variables::ProtectPrivateVars.3 \
	Perl::Critic::Policy::Variables::RequireInitializationForLocalVars.3 \
	Perl::Critic::Policy::Variables::RequireLexicalLoopIterators.3 \
	Perl::Critic::Policy::Variables::RequireLocalizedPunctuationVars.3 \
	Perl::Critic::Policy::Variables::RequireNegativeIndices.3 \
	Perl::Critic::PolicyConfig.3 \
	Perl::Critic::PolicyFactory.3 \
	Perl::Critic::PolicyListing.3 \
	Perl::Critic::PolicyParameter.3 \
	Perl::Critic::PolicyParameter::Behavior.3 \
	Perl::Critic::PolicyParameter::Behavior::Boolean.3 \
	Perl::Critic::PolicyParameter::Behavior::Enumeration.3 \
	Perl::Critic::PolicyParameter::Behavior::Integer.3 \
	Perl::Critic::PolicyParameter::Behavior::String.3 \
	Perl::Critic::PolicyParameter::Behavior::StringList.3 \
	Perl::Critic::PolicySummary.3 \
	Perl::Critic::ProfilePrototype.3 \
	Perl::Critic::Statistics.3 \
	Perl::Critic::TestUtils.3 \
	Perl::Critic::Theme.3 \
	Perl::Critic::ThemeListing.3 \
	Perl::Critic::UserProfile.3 \
	Perl::Critic::Utils.3 \
	Perl::Critic::Utils::Constants.3 \
	Perl::Critic::Utils::DataConversion.3 \
	Perl::Critic::Utils::McCabe.3 \
	Perl::Critic::Utils::POD.3 \
	Perl::Critic::Utils::POD::ParseInteriorSequence.3 \
	Perl::Critic::Utils::PPI.3 \
	Perl::Critic::Utils::Perl.3 \
	Perl::Critic::Violation.3 \
	Test::Perl::Critic::Policy.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-version>=0.77:${PORTSDIR}/devel/p5-version
RUN_DEPENDS+=	p5-version>=0.77:${PORTSDIR}/devel/p5-version
.endif

.include <bsd.port.post.mk>
