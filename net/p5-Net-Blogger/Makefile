PORTNAME=	Net-Blogger
PORTVERSION=	1.03
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	OOP-ish interface for accessing a weblog via the XML-RPC API

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CGI>=0:www/p5-CGI \
		p5-Error>=0:lang/p5-Error \
		p5-HTTP-Cookies>=0:www/p5-HTTP-Cookies \
		p5-SOAP-Lite>0.55:net/p5-SOAP-Lite \
		p5-URI>=0:net/p5-URI
TEST_DEPENDS=	p5-Term-ReadKey>=0:devel/p5-Term-ReadKey

USES=		dos2unix perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
