# New ports collection makefile for:	p5-HTML-FormFu
# Date created:		2007-12-24
# Whom:			Andrej Zverev <andrey.zverev@electro-com.ru>
#
# $FreeBSD$
#

PORTNAME=	HTML-FormFu
PORTVERSION=	0.07001
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	az@FreeBSD.org
COMMENT=	HTML Form Creation, Rendering and Validation Framework

BUILD_DEPENDS=	p5-Class-Accessor-Chained>=0:${PORTSDIR}/devel/p5-Class-Accessor-Chained \
		p5-Clone>=0:${PORTSDIR}/devel/p5-Clone \
		p5-Config-Any>=0.18:${PORTSDIR}/devel/p5-Config-Any \
		p5-Crypt-CBC>=0:${PORTSDIR}/security/p5-Crypt-CBC \
		p5-Crypt-DES>=0:${PORTSDIR}/security/p5-Crypt-DES \
		p5-Data-Visitor>=0.02:${PORTSDIR}/devel/p5-Data-Visitor \
		p5-Date-Calc>=0:${PORTSDIR}/devel/p5-Date-Calc \
		p5-Captcha-reCAPTCHA>=0.92:${PORTSDIR}/graphics/p5-Captcha-reCAPTCHA \
		p5-DateTime>=0.38:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Builder>=0.79.01:${PORTSDIR}/devel/p5-DateTime-Format-Builder \
		p5-DateTime-Format-Strptime>=0:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-DateTime-Locale>=0:${PORTSDIR}/devel/p5-DateTime-Locale \
		p5-Email-Valid>=0:${PORTSDIR}/mail/p5-Email-Valid \
		p5-File-ShareDir>=0.04:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-Hash-Flatten>=0:${PORTSDIR}/devel/p5-Hash-Flatten \
		p5-DateTime-Format-Natural>0:${PORTSDIR}/devel/p5-DateTime-Format-Natural \
		p5-HTML-Scrubber>=0:${PORTSDIR}/www/p5-HTML-Scrubber \
		p5-HTML-TokeParser-Simple>=3.14:${PORTSDIR}/www/p5-HTML-TokeParser-Simple \
		p5-List-MoreUtils>=0.16:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Number-Format>=0:${PORTSDIR}/textproc/p5-Number-Format \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Regexp-Copy>=0:${PORTSDIR}/textproc/p5-Regexp-Copy \
		p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Test-NoWarnings>=0.083:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-YAML-LibYAML>=0.32:${PORTSDIR}/textproc/p5-YAML-LibYAML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	HTML::FormFu::Inflator.3 \
	HTML::FormFu::Processor.3 \
	HTML::FormFu::Constraint::Integer.3 \
	HTML::FormFu::Constraint::AutoSet.3 \
	HTML::FormFu::Constraint::File.3 \
	HTML::FormFu::QueryType::CGI.3 \
	HTML::FormFu::Constraint::File::Size.3 \
	HTML::FormFu::Upload.3 \
	HTML::FormFu::QueryType::CGI::Simple.3 \
	HTML::FormFu::QueryType::Catalyst.3 \
	HTML::FormFu::Constraint::File::MIME.3 \
	HTML::FormFu::Manual::Cookbook.3 \
	HTML::FormFu::Filter::UpperCase.3 \
	HTML::FormFu::Constraint::Repeatable::Any.3 \
	HTML::FormFu::Element::Radio.3 \
	HTML::FormFu::Element::SimpleTable.3 \
	HTML::FormFu::Element::Block.3 \
	HTML::FormFu::Element::Button.3 \
	HTML::FormFu.3 \
	HTML::FormFu::Validator::Callback.3 \
	HTML::FormFu::Element::_Input.3 \
	HTML::FormFu::Filter::HTMLEscape.3 \
	HTML::FormFu::Element.3 \
	HTML::FormFu::Element::Multi.3 \
	HTML::FormFu::Filter::CopyValue.3 \
	HTML::FormFu::OutputProcessor::StripWhitespace.3 \
	HTML::FormFu::Constraint::Word.3 \
	HTML::FormFu::Element::Submit.3 \
	HTML::FormFu::OutputProcessor.3 \
	HTML::FormFu::Validator.3 \
	HTML::FormFu::Constraint::Number.3 \
	HTML::FormFu::Transformer.3 \
	HTML::FormFu::Filter::Encode.3 \
	HTML::FormFu::Element::Hidden.3 \
	HTML::FormFu::Element::Date.3 \
	HTML::FormFu::Constraint::Email.3 \
	HTML::FormFu::Constraint::Length.3 \
	HTML::FormFu::Constraint::CallbackOnce.3 \
	HTML::FormFu::Attribute.3 \
	HTML::FormFu::Filter::Whitespace.3 \
	HTML::FormFu::Element::Image.3 \
	HTML::FormFu::Inflator::DateTime.3 \
	HTML::FormFu::Constraint::MinMaxFields.3 \
	HTML::FormFu::Deflator.3 \
	HTML::FormFu::Filter::TrimEdges.3 \
	HTML::FormFu::Element::Radiogroup.3 \
	HTML::FormFu::Filter.3 \
	HTML::FormFu::Manual::Unicode.3 \
	HTML::FormFu::Deflator::Strftime.3 \
	HTML::FormFu::Element::Select.3 \
	HTML::FormFu::Filter::LowerCase.3 \
	HTML::FormFu::Filter::Callback.3 \
	HTML::FormFu::Element::Password.3 \
	HTML::FormFu::Constraint::MaxLength.3 \
	HTML::FormFu::Element::_NonBlock.3 \
	HTML::FormFu::Element::Blank.3 \
	HTML::FormFu::Element::_Field.3 \
	HTML::FormFu::Transformer::Callback.3 \
	HTML::FormFu::Constraint::Regex.3 \
	HTML::FormFu::Constraint::DependOn.3 \
	HTML::FormFu::Element::Reset.3 \
	HTML::FormFu::Element::_Group.3 \
	HTML::FormFu::Constraint::Bool.3 \
	HTML::FormFu::Element::Textarea.3 \
	HTML::FormFu::Constraint::MinLength.3 \
	HTML::FormFu::OutputProcessor::Indent.3 \
	HTML::FormFu::Element::Checkboxgroup.3 \
	HTML::FormFu::Constraint::Range.3 \
	HTML::FormFu::Element::Checkbox.3 \
	HTML::FormFu::Element::Repeatable.3 \
	HTML::FormFu::Element::Src.3 \
	HTML::FormFu::Element::Fieldset.3 \
	HTML::FormFu::Constraint::Printable.3 \
	HTML::FormFu::Element::Text.3 \
	HTML::FormFu::Constraint::AllOrNone.3 \
	HTML::FormFu::Constraint.3 \
	HTML::FormFu::Element::File.3 \
	HTML::FormFu::Filter::NonNumeric.3 \
	HTML::FormFu::Constraint::ASCII.3 \
	HTML::FormFu::Constraint::Required.3 \
	HTML::FormFu::Constraint::SingleValue.3 \
	HTML::FormFu::Constraint::Equal.3 \
	HTML::FormFu::Element::Hr.3 \
	HTML::FormFu::Constraint::Callback.3 \
	HTML::FormFu::Constraint::_others.3 \
	HTML::FormFu::Element::ContentButton.3 \
	HTML::FormFu::Filter::Regex.3 \
	HTML::FormFu::Filter::HTMLScrubber.3 \
	HTML::FormFu::Constraint::Set.3 \
	HTML::FormFu::UploadParam.3 \
	HTML::FormFu::Inflator::CompoundDateTime.3 \
	HTML::FormFu::Deflator::CompoundDateTime.3 \
	HTML::FormFu::Filter::Split.3 \
	HTML::FormFu::Filter::CompoundJoin.3 \
	HTML::FormFu::Plugin::StashValid.3 \
	HTML::FormFu::Deflator::CompoundSplit.3 \
	HTML::FormFu::Plugin.3 \
	HTML::FormFu::Model.3 \
	HTML::FormFu::Constraint::DateTime.3 \
	HTML::FormFu::Filter::CompoundSprintf.3 \
	HTML::FormFu::Filter::_Compound.3 \
	HTML::FormFu::Element::reCAPTCHA.3 \
	HTML::FormFu::Constraint::reCAPTCHA.3 \
	HTML::FormFu::Element::_MultiElement.3 \
	HTML::FormFu::Element::_MultiText.3 \
	HTML::FormFu::Element::_MultiSelect.3 \
	HTML::FormFu::Element::ComboBox.3 \
	HTML::FormFu::Constraint::MinRange.3 \
	HTML::FormFu::MultiForm.3 \
	HTML::FormFu::Element::DateTime.3 \
	HTML::FormFu::Constraint::MaxRange.3 \
	HTML::FormFu::Constraint::File::MinSize.3 \
	HTML::FormFu::Constraint::File::MaxSize.3 \
	HTML::FormFu::Element::Number.3 \
	HTML::FormFu::Model::HashRef.3 \
	HTML::FormFu::Deflator::Callback.3 \
	HTML::FormFu::Deflator::FormatNumber.3 \
	HTML::FormFu::Inflator::Callback.3 \
	HTML::FormFu::Deflator::PathClassFile.3 \
	HTML::FormFu::Filter::FormatNumber.3 \
	HTML::FormFu::Element::Label.3

.include <bsd.port.mk>
