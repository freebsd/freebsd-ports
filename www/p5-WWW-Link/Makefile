# New ports collection makefile for:	WWW::Link
# Date created:				31 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	WWW-Link
PORTVERSION=	0.030
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/M/MI/MIKEDLR
PKGNAMEPREFIX=	p5-

MAINTAINER=	svenasse@polaris.ca

PERL_CONFIGURE=	yes

MAN3=	WWW::Link.3 \
	WWW::Link::Change.3 \
	WWW::Link::Merge.3 \
	WWW::Link::Repair.3 \
	WWW::Link::Repair::ResourceMapper.3 \
	WWW::Link::Repair::Substitutor.3 \
	WWW::Link::Reporter.3 \
	WWW::Link::Reporter::Compile.3 \
	WWW::Link::Reporter::HTML.3 \
	WWW::Link::Reporter::LongList.3 \
	WWW::Link::Reporter::RepairForm.3 \
	WWW::Link::Reporter::Text.3 \
	WWW::Link::Selector.3 \
	WWW::Link::Test.3 \
	WWW::Link::Test::Validate.3 \
	WWW::Link::Tester.3 \
	WWW::Link::Tester::Adaptive.3 \
	WWW::Link::Tester::Base.3 \
	WWW::Link::Tester::Complex.3 \
	WWW::Link::Tester::Simple.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
