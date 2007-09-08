# New ports collection makefile for:	p5-Handel
# Date Created:				29 Dec 2005
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Handel
PORTVERSION=	0.33
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Template
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Simple commerce framework with AxKit/TT/Catalyst support

BUILD_DEPENDS=	${SITE_PERL}/Test/Strict.pm:${PORTSDIR}/devel/p5-Test-Strict \
	${SITE_PERL}/Path/Class.pm:${PORTSDIR}/devel/p5-Path-Class \
	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
	${SITE_PERL}/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Pod-Coverage \
	${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod \
	${SITE_PERL}/Test/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
	${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error \
	${SITE_PERL}/${PERL_ARCH}/Data/UUID.pm:${PORTSDIR}/devel/p5-Data-UUID \
	${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI \
	${SITE_PERL}/Locale/Maketext.pm:${PORTSDIR}/devel/p5-Locale-Maketext \
	${SITE_PERL}/Module/Pluggable.pm:${PORTSDIR}/devel/p5-Module-Pluggable
RUN_DEPENDS=	${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error \
	${SITE_PERL}/Module/Pluggable.pm:${PORTSDIR}/devel/p5-Module-Pluggable \
	${SITE_PERL}/${PERL_ARCH}/Data/UUID.pm:${PORTSDIR}/devel/p5-Data-UUID \
	${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI \
	${SITE_PERL}/Locale/Maketext.pm:${PORTSDIR}/devel/p5-Locale-Maketext

PERL_CONFIGURE=	yes

OPTIONS=CURRENCY_FORMAT "Currency formatting support" off \
	WEBSERVICEX "WebserviceX currency conversion support" off \
	CURRENCY_CODE "ISO currency code verification support" off \

MAN3=	Handel::Iterator.3 \
	Handel::DBI.3 \
	Template::Plugin::Handel::Order.3 \
	Template::Plugin::Handel::Checkout.3 \
	Catalyst::Helper::Controller::Handel::Checkout.3 \
	AxKit::XSP::Handel::Checkout.3 \
	Handel::Checkout.3 \
	Handel::Constants.3 \
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
	Handel::L10N::zh_tw.3 \
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
	Handel::Cart::Item.3

.include <bsd.port.pre.mk>

.if defined(WITH_CURRENCY_FORMAT)
RUN_DEPENDS+=	${SITE_PERL}/Locale/Currency/Format.pm:${PORTSDIR}/finance/p5-Locale-Currency-Format
.endif

.if defined(WITH_WEBSERVICEX)
RUN_DEPENDS+=	${SITE_PERL}/Finance/Currency/Convert/WebserviceX.pm:${PORTSDIR}/finance/p5-Finance-Currency-Convert-WebserviceX
.endif

.if defined(WITH_CURRENCY_CODE)
RUN_DEPENDS+=	${SITE_PERL}/Locale/Currency.pm:${PORTSDIR}/misc/p5-Locale-Codes
.endif

.include <bsd.port.post.mk>
