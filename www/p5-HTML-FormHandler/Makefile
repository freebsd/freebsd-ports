# New ports collection makefile for:  HTML-FormHandler
# Date created:		2009-12-03
# Whom:			gugu
# $FreeBSD$

PORTNAME=	HTML-FormHandler
PORTVERSION=	0.33002
PORTEPOCH=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/G/GS/GSHANK
PKGNAMEPREFIX=	p5-

MAINTAINER=	az@FreeBSD.org
COMMENT=	Form handler written in Moose

BUILD_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Strptime>=0:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-Email-Valid>=0:${PORTSDIR}/mail/p5-Email-Valid \
		p5-File-ShareDir>=0:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-Locale-Maketext>=1.09:${PORTSDIR}/devel/p5-Locale-Maketext \
		p5-Moose>=0.90:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Getopt>=0.16:${PORTSDIR}/devel/p5-MooseX-Getopt \
		p5-MooseX-Types>=0.20:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-MooseX-Types-Common>=0:${PORTSDIR}/devel/p5-MooseX-Types-Common \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-aliased>=0:${PORTSDIR}/devel/p5-aliased \
		p5-namespace-autoclean>=0.09:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-File-ShareDir-Install>=0.3:${PORTSDIR}/devel/p5-File-ShareDir-Install

RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Differences>=0:${PORTSDIR}/devel/p5-Test-Differences

PERL_CONFIGURE=	5.8.0+
MAN3=	HTML::FormHandler.3 \
	HTML::FormHandler::Field.3 HTML::FormHandler::TraitFor::I18N.3 \
	HTML::FormHandler::Render::WithTT.3 HTML::FormHandler::Field::NoValue.3 \
	HTML::FormHandler::BuildPages.3 \
	HTML::FormHandler::Field::Button.3 \
	HTML::FormHandler::Field::Boolean.3 HTML::FormHandler::Field::Checkbox.3 \
	HTML::FormHandler::Field::Compound.3 HTML::FormHandler::Field::Date.3 \
	HTML::FormHandler::Field::DateMDY.3 HTML::FormHandler::Field::DateTime.3 \
	HTML::FormHandler::Field::Display.3 HTML::FormHandler::Field::Duration.3 \
	HTML::FormHandler::Field::Email.3 HTML::FormHandler::Field::Hidden.3 \
	HTML::FormHandler::Field::Hour.3 HTML::FormHandler::Field::HtmlArea.3 \
	HTML::FormHandler::Field::IntRange.3 HTML::FormHandler::Field::Integer.3 \
	HTML::FormHandler::Field::Minute.3 HTML::FormHandler::Field::Money.3 \
	HTML::FormHandler::Field::Month.3 HTML::FormHandler::Field::MonthDay.3 \
	HTML::FormHandler::Field::MonthName.3 HTML::FormHandler::Field::Multiple.3 \
	HTML::FormHandler::Field::Nested.3 HTML::FormHandler::Field::Password.3 \
	HTML::FormHandler::Field::PasswordConf.3 HTML::FormHandler::Field::PosInteger.3 \
	HTML::FormHandler::Field::PrimaryKey.3 \
	HTML::FormHandler::Field::Repeatable.3 \
	HTML::FormHandler::Field::Repeatable::Instance.3 \
	HTML::FormHandler::Field::Reset.3 \
	HTML::FormHandler::Field::Result.3 \
	HTML::FormHandler::Field::Second.3 HTML::FormHandler::Field::Select.3 \
	HTML::FormHandler::Field::Submit.3 HTML::FormHandler::Field::Text.3 \
	HTML::FormHandler::Field::TextArea.3 HTML::FormHandler::Field::Upload.3 \
	HTML::FormHandler::Field::Weekday.3 HTML::FormHandler::Field::Year.3 \
	HTML::FormHandler::Widget::Field::Repeatable.3 \
	HTML::FormHandler::Fields.3 HTML::FormHandler::InitResult.3 \
	HTML::FormHandler::Manual.3 HTML::FormHandler::Manual::Catalyst.3 \
	HTML::FormHandler::Manual::Cookbook.3 HTML::FormHandler::Manual::Intro.3 \
	HTML::FormHandler::Manual::Reference.3 \
	HTML::FormHandler::Manual::Rendering.3 \
	HTML::FormHandler::Manual::Templates.3 \
	HTML::FormHandler::Manual::Tutorial.3 HTML::FormHandler::Meta::Role.3 \
	HTML::FormHandler::Model.3 HTML::FormHandler::Model::CDBI.3 \
	HTML::FormHandler::Moose.3 HTML::FormHandler::Field::Captcha.3 \
	HTML::FormHandler::Moose::Role.3 \
	HTML::FormHandler::Page.3 \
	HTML::FormHandler::Page::Simple.3 \
	HTML::FormHandler::Pages.3 \
	HTML::FormHandler::Render::Simple.3 \
	HTML::FormHandler::Render::Table.3 HTML::FormHandler::Result.3 \
	HTML::FormHandler::Result::Role.3 HTML::FormHandler::Types.3 \
	HTML::FormHandler::Validate.3 \
	HTML::FormHandler::Widget::Form::Simple.3 \
	HTML::FormHandler::Widget::Form::Table.3 \
	HTML::FormHandler::Widget::Wrapper::Simple.3 \
	HTML::FormHandler::TraitFor::Captcha.3 \
	HTML::FormHandler::Widget::Wrapper::Fieldset.3 \
	HTML::FormHandler::Widget::Field::Button.3 \
	HTML::FormHandler::Widget::Field::NoRender.3 \
	HTML::FormHandler::Widget::Field::Textarea.3 \
	HTML::FormHandler::Widget::Field::Password.3 \
	HTML::FormHandler::Widget::Field::Select.3 \
	HTML::FormHandler::I18N::ua_ua.3 \
	HTML::FormHandler::I18N::ru_ru.3 \
	HTML::FormHandler::Widget::Field::Hidden.3 \
	HTML::FormHandler::I18N.3 \
	HTML::FormHandler::Widget::ApplyRole.3 \
	HTML::FormHandler::I18N::hu_hu.3 \
	HTML::FormHandler::Widget::Field::Checkbox.3 \
	HTML::FormHandler::Model::Object.3 \
	HTML::FormHandler::Widget::Field::Reset.3 \
	HTML::FormHandler::I18N::de_de.3 \
	HTML::FormHandler::Widget::Field::Role::HTMLAttributes.3 \
	HTML::FormHandler::Widget::Field::Role::SelectedOption.3 \
	HTML::FormHandler::Widget::Field::Compound.3 \
	HTML::FormHandler::Widget::Field::Text.3 \
	HTML::FormHandler::Widget::Form::Role::HTMLAttributes.3 \
	HTML::FormHandler::Widget::Field::RadioGroup.3 \
	HTML::FormHandler::Widget::Field::Upload.3 \
	HTML::FormHandler::I18N::tr_tr.3 \
	HTML::FormHandler::I18N::en_us.3 \
	HTML::FormHandler::Widget::Wrapper::Table.3 \
	HTML::FormHandler::Widget::Field::CheckboxGroup.3 \
	HTML::FormHandler::Widget::Field::Submit.3 \
	HTML::FormHandler::Widget::Wrapper::None.3 \
	HTML::FormHandler::Widget::Wrapper::Base.3 \
	HTML::FormHandler::Wizard.3 \
	HTML::FormHandler::Params.3 HTML::FormHandler::Base.3 \
	HTML::FormHandler::BuildFields.3 HTML::FormHandler::Traits.3

.include <bsd.port.mk>
