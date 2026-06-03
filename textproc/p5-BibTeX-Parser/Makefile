PORTNAME=	BibTeX-Parser
PORTVERSION=	1.93
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BORISV
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pure perl BibTeX parser
WWW=		https://metacpan.org/release/BibTeX-Parser

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-IO-String>=0:devel/p5-IO-String \
		p5-LaTeX-ToUnicode>=0.11:textproc/p5-LaTeX-ToUnicode

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
