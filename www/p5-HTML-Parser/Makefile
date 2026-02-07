PORTNAME=	HTML-Parser
PORTVERSION=	3.83
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for parsing HTML documents
WWW=		https://metacpan.org/release/HTML-Parser

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTML-Tagset>=0:www/p5-HTML-Tagset \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-URI>=0:net/p5-URI

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/HTML/Parser/Parser.so

.include <bsd.port.mk>
