# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Reaction
PORTVERSION=	0.001001
PORTREVISION=	5
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extended MVC framework built upon Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7002:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Plugin-ConfigLoader>=0.19:${PORTSDIR}/www/p5-Catalyst-Plugin-ConfigLoader \
		p5-Catalyst-Plugin-Static-Simple>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Static-Simple \
		p5-Catalyst-Plugin-I18N>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-I18N \
		p5-Catalyst-Model-DBIC-Schema>=0:${PORTSDIR}/www/p5-Catalyst-Model-DBIC-Schema \
		p5-Catalyst-View-TT>=0.23:${PORTSDIR}/www/p5-Catalyst-View-TT \
		p5-Catalyst-Component-ACCEPT_CONTEXT>=0:${PORTSDIR}/www/p5-Catalyst-Component-ACCEPT_CONTEXT \
		p5-Config-General>=0:${PORTSDIR}/devel/p5-Config-General \
		p5-Test-Class>=0:${PORTSDIR}/devel/p5-Test-Class \
		p5-Test-Memory-Cycle>=0:${PORTSDIR}/devel/p5-Test-Memory-Cycle \
		p5-DBIx-Class>=0.07001:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-SQL-Translator>=0.08:${PORTSDIR}/databases/p5-SQL-Translator \
		p5-Moose>=0.54:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0.04:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-aliased>=0:${PORTSDIR}/devel/p5-aliased \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Set>=0:${PORTSDIR}/devel/p5-DateTime-Set \
		p5-DateTime-Event-Recurrence>=0:${PORTSDIR}/devel/p5-DateTime-Event-Recurrence \
		p5-DateTime-Format-MySQL>=0:${PORTSDIR}/devel/p5-DateTime-Format-MySQL \
		p5-Time-modules>=0:${PORTSDIR}/devel/p5-Time-modules \
		p5-Email-Valid>=0:${PORTSDIR}/mail/p5-Email-Valid \
		p5-Email-Send>=0:${PORTSDIR}/mail/p5-Email-Send \
		p5-Email-MIME>=0:${PORTSDIR}/mail/p5-Email-MIME \
		p5-Text-CSV_XS>=0:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		p5-File-ShareDir>=1.00:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-Devel-Declare>=0:${PORTSDIR}/devel/p5-Devel-Declare
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		componentui_cgi.pl.1 componentui_create.pl.1 \
		componentui_fastcgi.pl.1 componentui_server.pl.1 \
		componentui_test.pl.1

MAN3=		Catalyst::Model::Reaction::InterfaceModel::DBIC.3 \
		ComponentUI.3 Reaction::Class.3 Reaction::ClassExporter.3 \
		Reaction::InterfaceModel::Action.3 \
		Reaction::InterfaceModel::Action::DBIC::Result::Delete.3 \
		Reaction::InterfaceModel::Action::DBIC::Result::Update.3 \
		Reaction::InterfaceModel::Action::DBIC::ResultSet::Create.3 \
		Reaction::InterfaceModel::Action::DBIC::ResultSet::DeleteAll.3 \
		Reaction::InterfaceModel::Action::DBIC::Role::CheckUniques.3 \
		Reaction::InterfaceModel::Action::DBIC::User::ChangePassword.3 \
		Reaction::InterfaceModel::Action::DBIC::User::ResetPassword.3 \
		Reaction::InterfaceModel::Action::DBIC::User::Role::SetPassword.3 \
		Reaction::InterfaceModel::Action::DBIC::User::SetPassword.3 \
		Reaction::InterfaceModel::Action::User::ChangePassword.3 \
		Reaction::InterfaceModel::Action::User::Login.3 \
		Reaction::InterfaceModel::Action::User::ResetPassword.3 \
		Reaction::InterfaceModel::Action::User::Role::ConfirmationCodeSupport.3 \
		Reaction::InterfaceModel::Action::User::SetPassword.3 \
		Reaction::InterfaceModel::Collection.3 \
		Reaction::InterfaceModel::Collection::DBIC::Role::Base.3 \
		Reaction::InterfaceModel::Collection::DBIC::Role::Where.3 \
		Reaction::InterfaceModel::Collection::Persistent.3 \
		Reaction::InterfaceModel::Collection::Persistent::ResultSet.3 \
		Reaction::InterfaceModel::Collection::Virtual.3 \
		Reaction::InterfaceModel::Collection::Virtual::ResultSet.3 \
		Reaction::InterfaceModel::Object.3 \
		Reaction::InterfaceModel::Reflector::DBIC.3 Reaction::Manual.3 \
		Reaction::Manual::Intro.3 Reaction::Meta::Attribute.3 \
		Reaction::Meta::InterfaceModel::Action::Class.3 \
		Reaction::Meta::InterfaceModel::Action::ParameterAttribute.3 \
		Reaction::Meta::InterfaceModel::Object::Class.3 \
		Reaction::Meta::InterfaceModel::Object::DomainModelAttribute.3 \
		Reaction::Meta::InterfaceModel::Object::ParameterAttribute.3 \
		Reaction::Object.3 Reaction::Role.3 Reaction::Test.3 \
		Reaction::Test::WithDB.3 Reaction::Types::Core.3 \
		Reaction::Types::DBIC.3 Reaction::Types::DateTime.3 \
		Reaction::Types::Email.3 Reaction::Types::File.3 \
		Reaction::UI::Controller.3 \
		Reaction::UI::Controller::Collection.3 \
		Reaction::UI::Controller::Collection::CRUD.3 \
		Reaction::UI::Controller::Root.3 Reaction::UI::FocusStack.3 \
		Reaction::UI::ViewPort.3 Reaction::UI::ViewPort::Action.3 \
		Reaction::UI::ViewPort::Collection.3 \
		Reaction::UI::ViewPort::Collection::Grid.3 \
		Reaction::UI::ViewPort::Field.3 \
		Reaction::UI::ViewPort::Field::.ToDo::File.3 \
		Reaction::UI::ViewPort::Field::.ToDo::TimeRange.3 \
		Reaction::UI::ViewPort::Field::Mutable::ChooseMany.3 \
		Reaction::UI::ViewPort::Field::Mutable::DateTime.3 \
		Reaction::UI::ViewPort::Field::Mutable::HiddenArray.3 \
		Reaction::UI::ViewPort::Field::Password.3 \
		Reaction::UI::ViewPort::Field::Role::Mutable.3 \
		Reaction::UI::ViewPort::Field::TimeRange.3 \
		Reaction::UI::ViewPort::Object.3 \
		Reaction::UI::ViewPort::Role::Actions.3 Reaction::UI::Widget.3 \
		Reaction::UI::Widget::Action.3 \
		Reaction::UI::Widget::Collection.3 \
		Reaction::UI::Widget::Collection::Grid.3 \
		Reaction::UI::Widget::Collection::Grid::Member.3 \
		Reaction::UI::Widget::Field.3 \
		Reaction::UI::Widget::Field::Array.3 \
		Reaction::UI::Widget::Field::Boolean.3 \
		Reaction::UI::Widget::Field::Collection.3 \
		Reaction::UI::Widget::Field::DateTime.3 \
		Reaction::UI::Widget::Field::Integer.3 \
		Reaction::UI::Widget::Field::Mutable::Boolean.3 \
		Reaction::UI::Widget::Field::Mutable::ChooseMany.3 \
		Reaction::UI::Widget::Field::Mutable::ChooseOne.3 \
		Reaction::UI::Widget::Field::Mutable::DateTime.3 \
		Reaction::UI::Widget::Field::Mutable::File.3 \
		Reaction::UI::Widget::Field::Mutable::HiddenArray.3 \
		Reaction::UI::Widget::Field::Mutable::Integer.3 \
		Reaction::UI::Widget::Field::Mutable::Number.3 \
		Reaction::UI::Widget::Field::Mutable::Password.3 \
		Reaction::UI::Widget::Field::Mutable::String.3 \
		Reaction::UI::Widget::Field::Mutable::Text.3 \
		Reaction::UI::Widget::Field::Mutable::TimeRange.3 \
		Reaction::UI::Widget::Field::Number.3 \
		Reaction::UI::Widget::Field::RelatedObject.3 \
		Reaction::UI::Widget::Field::String.3 \
		Reaction::UI::Widget::Field::Text.3 \
		Reaction::UI::Widget::ListView.3 Reaction::UI::Widget::Object.3 \
		Reaction::UI::Widget::Value.3 \
		Reaction::UI::Widget::Value::Boolean.3 \
		Reaction::UI::Widget::Value::Collection.3 \
		Reaction::UI::Widget::Value::DateTime.3 \
		Reaction::UI::Widget::Value::Number.3 \
		Reaction::UI::Widget::Value::RelatedObject.3 \
		Reaction::UI::Widget::Value::String.3 \
		Reaction::UI::Widget::Value::Text.3 Reaction::UI::WidgetClass.3 \
		Reaction::UI::Window.3

.include <bsd.port.mk>
