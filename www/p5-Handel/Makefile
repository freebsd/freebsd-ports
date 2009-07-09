# New ports collection makefile for:	p5-Handel
# Date Created:				29 Dec 2005
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Handel
PORTVERSION=	1.00011
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Simple ecommerce framework with AxKit/Catalyst support

BUILD_DEPENDS=	${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error \
	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
	${SITE_PERL}/Locale/Maketext.pm:${PORTSDIR}/devel/p5-Locale-Maketext \
	${SITE_PERL}/Module/Pluggable.pm:${PORTSDIR}/devel/p5-Module-Pluggable \
	${SITE_PERL}/Class/Accessor/Grouped.pm:${PORTSDIR}/devel/p5-Class-Accessor-Grouped \
	${SITE_PERL}/Data/Currency.pm:${PORTSDIR}/finance/p5-Data-Currency \
	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
	${SITE_PERL}/DBIx/Class/UUIDColumns.pm:${PORTSDIR}/databases/p5-DBIx-Class-UUIDColumns \
	${SITE_PERL}/DBIx/Class/Validation.pm:${PORTSDIR}/databases/p5-DBIx-Class-Validation \
	${SITE_PERL}/SQL/Translator.pm:${PORTSDIR}/databases/p5-SQL-Translator \
	${SITE_PERL}/Finance/Currency/Convert/WebserviceX.pm:${PORTSDIR}/finance/p5-Finance-Currency-Convert-WebserviceX \
	${SITE_PERL}/DateTime/Format/MySQL.pm:${PORTSDIR}/devel/p5-DateTime-Format-MySQL \
	${SITE_PERL}/Module/Starter.pm:${PORTSDIR}/devel/p5-Module-Starter \
	${SITE_PERL}/FormValidator/Simple.pm:${PORTSDIR}/textproc/p5-FormValidator-Simple \
	${SITE_PERL}/Locale/Currency/Format.pm:${PORTSDIR}/finance/p5-Locale-Currency-Format \
	${SITE_PERL}/${PERL_ARCH}/Clone.pm:${PORTSDIR}/devel/p5-Clone
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.6.0+

MAN1=	handel.pl.1
MAN3=	Handel::Iterator.3 \
	Template::Plugin::Handel::Order.3 \
	Template::Plugin::Handel::Checkout.3 \
	Catalyst::Helper::Controller::Handel::Checkout.3 \
	AxKit::XSP::Handel::Checkout.3 \
	Handel::Checkout.3 \
	Handel::Constants.3 \
	Handel::L10N::bg.3 \
	Handel::L10N::fr.3 \
	Handel::L10N::en_us.3 \
	Handel::Checkout::Message.3 \
	AxKit::XSP::Handel::Order.3 \
	Handel.3 \
	Handel::Checkout::Plugin.3 \
	Handel::Checkout::Stash.3 \
	Catalyst::Helper::Model::Handel::Cart.3 \
	Handel::L10N.3 \
	Catalyst::Helper::Controller::Handel::Order.3 \
	Catalyst::Helper::Model::Handel::Order.3 \
	Handel::Checkout::Plugin::AssignOrderNumber.3 \
	Catalyst::Helper::Controller::Handel::Cart.3 \
	Template::Plugin::Handel::Cart.3 \
	Handel::Exception.3 \
	AxKit::XSP::Handel::Cart.3 \
	Catalyst::Helper::Handel::Scaffold.3 \
	Template::Plugin::Handel::Constants.3 \
	Handel::Checkout::Plugin::MarkOrderSaved.3 \
	Handel::Order::Item.3 \
	Handel::Constraints.3 \
	Handel::Cart.3 \
	Handel::ConfigReader.3 \
	Handel::Order.3 \
	Handel::Currency.3 \
	Handel::Cart::Item.3 \
	Handel::Storage::DBIC::Cart.3 \
	Handel::Storage::DBIC::Result.3 \
	Handel::Components::DefaultValues.3 \
	Handel::Schema::DBIC::Order.3 \
	Handel::Cart::Schema.3 \
	Handel::Manual::QuickStart.3 \
	Handel::Manual::Intro.3 \
	Handel::Storage::DBIC.3 \
	Handel::Manual::Cookbook.3 \
	Handel::Compat::Currency.3 \
	Handel::Manual::Requirements.3 \
	Handel::Schema::DBIC::Cart.3 \
	Handel::Storage::DBIC::Cart::Item.3 \
	Handel::Manual.3 \
	Handel::Iterator::Results.3 \
	Handel::Iterator::List.3 \
	Handel::Manual::Storage::DBIC.3 \
	Handel::Manual::Cookbook::AddingColumns.3 \
	Handel::Schema::DBIC::Cart::Item.3 \
	Handel::Compat.3 \
	Handel::Manual::Storage.3 \
	Handel::Components::Validation.3 \
	Module::Starter::Handel.3 \
	Catalyst::Helper::Handel.3 \
	Handel::Order::Schema.3 \
	Handel::Base.3 \
	Handel::Manual::Schema.3 \
	Handel::Manual::KnownIssues.3 \
	Handel::Storage::DBIC::Order::Item.3 \
	Handel::Schema::DBIC::Order::Item.3 \
	Handel::Storage::Result.3 \
	Catalyst::Model::Handel::Cart.3 \
	Catalyst::Model::Handel::Order.3 \
	Handel::Components::Constraints.3 \
	Handel::Storage::DBIC::Order.3 \
	Handel::Manual::Upgrading.3 \
	Handel::Storage.3 \
	Handel::Manual::Cookbook::WritingCustomStorage.3 \
	Handel::Schema.3 \
	Handel::Iterator::DBIC.3 \
	Handel::Manual::About.3

.include <bsd.port.pre.mk>

post-extract:
	@${PERL} -pi -e '$$_ = undef if /^auto_install/' ${WRKSRC}/Makefile.PL

.include <bsd.port.post.mk>
