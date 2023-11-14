PORTNAME=	Text-MultiMarkdown
PORTVERSION=	1.002000
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	Text-MultiMarkdown-${PORTVERSION:S|000$||}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert MultiMarkdown syntax to (X)HTML
WWW=		https://metacpan.org/release/Text-MultiMarkdown

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTML-Parser>0:www/p5-HTML-Parser \
		p5-Text-Markdown>=1.0.26:textproc/p5-Text-Markdown
TEST_DEPENDS=	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
