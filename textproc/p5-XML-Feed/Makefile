# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	XML-Feed
PORTVERSION=	0.52
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 modules for Syndication feed parser and auto-discovery

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-ErrorHandler>=0:${PORTSDIR}/devel/p5-Class-ErrorHandler \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Mail>=0:${PORTSDIR}/devel/p5-DateTime-Format-Mail \
		p5-DateTime-Format-W3CDTF>=0:${PORTSDIR}/devel/p5-DateTime-Format-W3CDTF \
		p5-Feed-Find>=0:${PORTSDIR}/www/p5-Feed-Find \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-URI-Fetch>=0:${PORTSDIR}/www/p5-URI-Fetch \
		p5-XML-Atom>=0.38:${PORTSDIR}/textproc/p5-XML-Atom \
		p5-XML-LibXML>=1.66:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-RSS>=1.47:${PORTSDIR}/textproc/p5-XML-RSS \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-XML-RSS-LibXML>=0.30.04:${PORTSDIR}/textproc/p5-XML-RSS-LibXML

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
