# New ports collection makefile for:	p5-XML-Feed
# Date created:				Jul 31 2004
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	XML-Feed
PORTVERSION=	0.08
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 modules for Syndication feed parser and auto-discovery

RUN_DEPENDS=	${SITE_PERL}/Class/ErrorHandler.pm:${PORTSDIR}/devel/p5-Class-ErrorHandler \
		${SITE_PERL}/Feed/Find.pm:${PORTSDIR}/www/p5-Feed-Find \
		${SITE_PERL}/URI/Fetch.pm:${PORTSDIR}/www/p5-URI-Fetch \
		${SITE_PERL}/XML/RSS.pm:${PORTSDIR}/textproc/p5-XML-RSS \
		${SITE_PERL}/XML/Atom.pm:${PORTSDIR}/textproc/p5-XML-Atom \
		${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/DateTime/Format/Mail.pm:${PORTSDIR}/devel/p5-DateTime-Format-Mail \
		${SITE_PERL}/DateTime/Format/W3CDTF.pm:${PORTSDIR}/devel/p5-DateTime-Format-W3CDTF \
		${SITE_PERL}/${PERL_ARCH}/List/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/HTML/TokeParser.pm:${PORTSDIR}/www/p5-HTML-Parser

PERL_MODBUILD=	yes

MAN3=		XML::Feed.3 \
		XML::Feed::Content.3 \
		XML::Feed::Entry.3

post-patch:
	${PERL} -pi -e '$$_ = "" if m|auto_install|' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>

# p5-XML-Atom needs 5.8.5
.if ${PERL_LEVEL} < 500805
IGNORE=		requires perl 5.8.5 or later. Install lang/perl5. then try again
.endif

.include <bsd.port.post.mk>
