PORTNAME=	HTML-ExtractContent
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TARAO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for HTML content extractor with scoring heuristics
WWW=		https://metacpan.org/release/HTML-ExtractContent

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor-Lvalue>=0:devel/p5-Class-Accessor-Lvalue \
		p5-Exporter-Lite>=0:devel/p5-Exporter-Lite \
		p5-HTML-Parser>=0:www/p5-HTML-Parser
TEST_DEPENDS=	p5-File-Slurp>=0:devel/p5-File-Slurp

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
