PORTNAME=	Net-eBay
PORTVERSION=	0.62
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl Interface to XML based eBay API

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay \
		p5-DateTime-Precise>=0:devel/p5-DateTime-Precise \
		p5-HTML-PrettyPrinter>=0:www/p5-HTML-PrettyPrinter \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-HTTP-Date>=0:www/p5-HTTP-Date \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-Net-SSLeay>=0:security/p5-Net-SSLeay \
		p5-Text-Format>=0:textproc/p5-Text-Format \
		p5-XML-Dumper>=0:textproc/p5-XML-Dumper \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-libwww>=0:www/p5-libwww

USES=		perl5 shebangfix
USE_PERL5=	configure

NO_ARCH=	yes

SHEBANG_FILES=	*.pl

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${MKDIR} ${WRKSRC}/examples/
	@${MV} ${WRKSRC}/*.pl ${WRKSRC}/examples/

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.pl ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
