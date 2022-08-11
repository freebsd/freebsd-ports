PORTNAME=	XML-RSS
PORTVERSION=	1.62
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl extension to manage RDF Site Summary (RSS) files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS} \
		p5-Test-Manifest>=0.9:devel/p5-Test-Manifest
RUN_DEPENDS=	p5-DateTime-Format-Mail>=0:devel/p5-DateTime-Format-Mail \
		p5-DateTime-Format-W3CDTF>=0:devel/p5-DateTime-Format-W3CDTF \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-XML-Parser>=2.23:textproc/p5-XML-Parser

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
