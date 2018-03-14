# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-RSS
PORTVERSION=	1.60
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl extension to manage RDF Site Summary (RSS) files

RUN_DEPENDS=	p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-Format-Mail>=0:devel/p5-DateTime-Format-Mail \
		p5-DateTime-Format-W3CDTF>=0:devel/p5-DateTime-Format-W3CDTF \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-XML-Parser>=2.23:textproc/p5-XML-Parser
BUILD_DEPENDS:=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-Manifest>=0.9:devel/p5-Test-Manifest

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
