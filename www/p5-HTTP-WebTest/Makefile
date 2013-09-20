# $FreeBSD$

PORTNAME=	HTTP-WebTest
PORTVERSION=	2.04
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Tests remote URLs or local web files

BUILD_DEPENDS=	\
	p5-Algorithm-Diff>=0:${PORTSDIR}/devel/p5-Algorithm-Diff \
	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
	p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject \

USES=		perl5
USE_PERL5=	configure
INSTALL_TARGET=	pure_install

MAN1=		wt.1
MAN3=		Bundle::HTTP::WebTest.3 \
		HTTP::WebTest.3 HTTP::WebTest::API.3 \
		HTTP::WebTest::Cookbook.3 HTTP::WebTest::Cookies.3 \
		HTTP::WebTest::Parser.3 HTTP::WebTest::Plugin.3 \
		HTTP::WebTest::Plugin::Click.3 \
		HTTP::WebTest::Plugin::ContentSizeTest.3 \
		HTTP::WebTest::Plugin::Cookies.3 \
		HTTP::WebTest::Plugin::DefaultReport.3 \
		HTTP::WebTest::Plugin::Delay.3 \
		HTTP::WebTest::Plugin::HarnessReport.3 \
		HTTP::WebTest::Plugin::Hooks.3 \
		HTTP::WebTest::Plugin::Loader.3 \
		HTTP::WebTest::Plugin::ResponseTimeTest.3 \
		HTTP::WebTest::Plugin::SetRequest.3 \
		HTTP::WebTest::Plugin::StatusTest.3 \
		HTTP::WebTest::Plugin::TextMatchTest.3 \
		HTTP::WebTest::Plugins.3 HTTP::WebTest::ReportPlugin.3 \
		HTTP::WebTest::Request.3 HTTP::WebTest::SelfTest.3 \
		HTTP::WebTest::Test.3 HTTP::WebTest::TestResult.3 \
		HTTP::WebTest::Utils.3

NO_STAGE=	yes
.include <bsd.port.mk>
