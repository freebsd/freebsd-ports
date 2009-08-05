# New ports collection makefile for:	XML::RSS
# Date created:				4th September 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-RSS
PORTVERSION=	1.45
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl extension to manage RDF Site Summary (RSS) files

RUN_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Mail>=0:${PORTSDIR}/devel/p5-DateTime-Format-Mail \
		p5-DateTime-Format-W3CDTF>=0:${PORTSDIR}/devel/p5-DateTime-Format-W3CDTF \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-XML-Parser>=2.23:${PORTSDIR}/textproc/p5-XML-Parser
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-Manifest>=0.9:${PORTSDIR}/devel/p5-Test-Manifest

PERL_CONFIGURE=	yes

MAN3=		XML::RSS.3

.include <bsd.port.mk>
