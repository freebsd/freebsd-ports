# New ports collection makefile for:	WWW::Link
# Date created:				31 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	WWW-Link
PORTVERSION=	0.036
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Maintain information about the state of links

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-HTML-Stream>=0:${PORTSDIR}/www/p5-HTML-Stream \
		p5-CGI-modules>=0:${PORTSDIR}/www/p5-CGI-modules \
		p5-Net-Telnet>=0:${PORTSDIR}/net/p5-Net-Telnet \
		p5-MLDBM>=0:${PORTSDIR}/databases/p5-MLDBM \
		p5-Getopt-Long>=0:${PORTSDIR}/devel/p5-Getopt-Long
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	WWW::Link.3 \
	WWW::Link::Change.3 \
	WWW::Link::Merge.3 \
	WWW::Link::Redirect.3 \
	WWW::Link::Repair.3 \
	WWW::Link::Repair::ResourceMapper.3 \
	WWW::Link::Repair::Substitutor.3 \
	WWW::Link::Reporter.3 \
	WWW::Link::Reporter::Compile.3 \
	WWW::Link::Reporter::HTML.3 \
	WWW::Link::Reporter::LongList.3 \
	WWW::Link::Reporter::RepairForm.3 \
	WWW::Link::Reporter::Text.3 \
	WWW::Link::Reporter::URI.3 \
	WWW::Link::Selector.3 \
	WWW::Link::Test.3 \
	WWW::Link::Test::Validate.3 \
	WWW::Link::Tester.3 \
	WWW::Link::Tester::Adaptive.3 \
	WWW::Link::Tester::Base.3 \
	WWW::Link::Tester::Complex.3 \
	WWW::Link::Tester::Simple.3

.include <bsd.port.mk>
