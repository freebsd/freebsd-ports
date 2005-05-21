# New ports collection makefile for:	WWW::Link
# Date created:				31 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	WWW-Link
PORTVERSION=	0.036
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	svenasse@polaris.ca
COMMENT=	Maintain information about the state of links

BUILD_DEPENDS=	${SITE_PERL}/HTTP/Response.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/HTML/Stream.pm:${PORTSDIR}/www/p5-HTML-Stream \
		${SITE_PERL}/CGI/Form.pm:${PORTSDIR}/www/p5-CGI-modules \
		${SITE_PERL}/Net/Telnet.pm:${PORTSDIR}/net/p5-Net-Telnet \
		${SITE_PERL}/MLDBM.pm:${PORTSDIR}/databases/p5-MLDBM \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
BROKEN=		"Incomplete pkg-plist"

post-patch:
	${PERL} -pi.bak \
		-e 's/^\s*our\s+\(?\s*([\$$\@]\w+)\s*\)?/use vars qw($$1);$$1/;' \
		-e '$$_="" if /use warnings/;' \
		$$(${FIND} ${WRKSRC}/lib -name '*.pm')
.endif

.include <bsd.port.post.mk>
