# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Web-Scraper
PORTVERSION=	0.38
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Web Scraping Toolkit inspired by Scrapi

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-Parser>0:www/p5-HTML-Parser \
		p5-HTML-Selector-XPath>=0.03:www/p5-HTML-Selector-XPath \
		p5-HTML-Tagset>0:www/p5-HTML-Tagset \
		p5-HTML-TreeBuilder-LibXML>=0.04:www/p5-HTML-TreeBuilder-LibXML \
		p5-HTML-TreeBuilder-XPath>=0.08:www/p5-HTML-TreeBuilder-XPath \
		p5-HTML-Tree>=3.23:www/p5-HTML-Tree \
		p5-UNIVERSAL-require>0:devel/p5-UNIVERSAL-require \
		p5-URI>0:net/p5-URI \
		p5-XML-XPathEngine>=0.08:textproc/p5-XML-XPathEngine \
		p5-YAML>0:textproc/p5-YAML \
		p5-libwww>=5.827:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Base>=0:devel/p5-Test-Base \
		p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		perl5 shebangfix
USE_PERL5=	modbuildtiny

SHEBANG_FILES=	bin/scraper

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/scraper ${STAGEDIR}${PREFIX}/bin/scraper

.include <bsd.port.mk>
