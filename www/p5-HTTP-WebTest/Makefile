# New ports collection makefile for:	p5-HTTP-WebTest
# Date Created:				9 Jan, 2003
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-WebTest
PORTVERSION=	2.04
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTTP
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Tests remote URLs or local web files

BUILD_DEPENDS=	${BUILD_DEPENDS_56} \
	${SITE_PERL}/Algorithm/Diff.pm:${PORTSDIR}/devel/p5-Algorithm-Diff \
	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
	${SITE_PERL}/Test/Builder/Tester.pm:${PORTSDIR}/devel/p5-Test-Builder-Tester \
	${SITE_PERL}/Test/MockObject.pm:${PORTSDIR}/devel/p5-Test-MockObject \

PERL_CONFIGURE=	yes
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
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS_56=	\
	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
	${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net \
	${SITE_PERL}/Text/Balanced.pm:${PORTSDIR}/textproc/p5-Text-Balanced \
	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
	${SITE_PERL}/Test/Builder.pm:${PORTSDIR}/devel/p5-Test-Simple \
	${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI
.endif
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.post.mk>
