# New ports collection makefile for:	p5-XML-Feed
# Date created:				Jul 31 2004
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	XML-Feed
PORTVERSION=	0.43
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
#DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 modules for Syndication feed parser and auto-discovery

RUN_DEPENDS=	p5-Class-ErrorHandler>=0:${PORTSDIR}/devel/p5-Class-ErrorHandler \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Mail>=0:${PORTSDIR}/devel/p5-DateTime-Format-Mail \
		p5-DateTime-Format-W3CDTF>=0:${PORTSDIR}/devel/p5-DateTime-Format-W3CDTF \
		p5-Feed-Find>=0:${PORTSDIR}/www/p5-Feed-Find \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-URI-Fetch>=0:${PORTSDIR}/www/p5-URI-Fetch \
		p5-XML-Atom>=0.23:${PORTSDIR}/textproc/p5-XML-Atom \
		p5-XML-LibXML>=1.66:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-RSS>=1.37:${PORTSDIR}/textproc/p5-XML-RSS \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.5+

MAN3=		XML::Feed.3 \
		XML::Feed::Content.3 \
		XML::Feed::Enclosure.3 \
		XML::Feed::Entry.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.if ${PERL_LEVEL} < 500905
RUN_DEPENDS+=	p5-Module-Pluggable>=0:${PORTSDIR}/devel/p5-Module-Pluggable
.endif

.include <bsd.port.post.mk>
