PORTNAME=	XML-Twig
PORTVERSION=	3.54
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Process huge XML documents by chunks via a tree interface
WWW=		https://metacpan.org/release/XML-Twig

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTML-Entities-Numbered>=0:textproc/p5-HTML-Entities-Numbered \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-HTML-Tree>=3.13:www/p5-HTML-Tree \
		p5-libwww>=0:www/p5-libwww \
		p5-Text-Iconv>=0:converters/p5-Text-Iconv \
		p5-Tie-IxHash>=0:devel/p5-Tie-IxHash \
		p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-XML-XPath>=0:textproc/p5-XML-XPath \
		p5-XML-XPathEngine>=0:textproc/p5-XML-XPathEngine
TEST_DEPENDS=	p5-IO-CaptureOutput>=0:devel/p5-IO-CaptureOutput \
		p5-IO-Stringy>=0:devel/p5-IO-Stringy \
		p5-Unicode-Map8>=0:converters/p5-Unicode-Map8 \
		p5-Unicode-String>=0:converters/p5-Unicode-String \
		p5-XML-Handler-YAWriter>=0:textproc/p5-XML-Handler-YAWriter \
		p5-XML-SAX-Writer>=0:textproc/p5-XML-SAX-Writer \
		p5-XML-Simple>=2:textproc/p5-XML-Simple

USES=		perl5
USE_PERL5=	configure

CONFIGURE_ARGS=	-y
NO_ARCH=	yes

.include <bsd.port.mk>
