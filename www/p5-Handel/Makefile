# New ports collection makefile for:	p5-Handel
# Date Created:				29 Dec 2005
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Handel
PORTVERSION=	1.00013
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple ecommerce framework with AxKit/Catalyst support

BUILD_DEPENDS=	p5-Error>=0.17016:${PORTSDIR}/lang/p5-Error \
	p5-Class-Accessor-Grouped>=0.09003:${PORTSDIR}/devel/p5-Class-Accessor-Grouped \
	p5-Data-Currency>=0.04002:${PORTSDIR}/finance/p5-Data-Currency \
	p5-DBD-SQLite>=1.29:${PORTSDIR}/databases/p5-DBD-SQLite \
	p5-DBIx-Class-UUIDColumns>=0.02005:${PORTSDIR}/databases/p5-DBIx-Class-UUIDColumns \
	p5-DBIx-Class-Validation>=0.02005:${PORTSDIR}/databases/p5-DBIx-Class-Validation \
	p5-SQL-Translator>=0.11006:${PORTSDIR}/databases/p5-SQL-Translator \
	p5-Finance-Currency-Convert-WebserviceX>=0.07001:${PORTSDIR}/finance/p5-Finance-Currency-Convert-WebserviceX \
	p5-DateTime-Format-MySQL>=0.04:${PORTSDIR}/devel/p5-DateTime-Format-MySQL \
	p5-Module-Starter>=1.54:${PORTSDIR}/devel/p5-Module-Starter \
	p5-FormValidator-Simple>=0.28:${PORTSDIR}/textproc/p5-FormValidator-Simple \
	p5-Locale-Currency-Format>=1.28:${PORTSDIR}/finance/p5-Locale-Currency-Format \
	p5-Clone>=0.31:${PORTSDIR}/devel/p5-Clone \
	p5-Class-ISA>=0.36:${PORTSDIR}/devel/p5-Class-ISA \
	p5-File-Path>=2.08:${PORTSDIR}/devel/p5-File-Path
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.6.0+

LICENSE_COMB=	dual
LICENSE=	ART20 GPLv1

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
	Handel::L10N::de.3 \
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
