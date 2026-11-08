PORTNAME=	XML-OPML-SimpleGen
PORTVERSION=	0.07
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Generate OPML documents without having too much to worry about
WWW=		https://metacpan.org/release/XML-OPML-SimpleGen

LICENSE=	ART10

TEST_DEPENDS=	${RUN_DEPENDS} \
		p5-XML-OPML>=0:textproc/p5-XML-OPML
RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-XML-Simple>=0:textproc/p5-XML-Simple

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
