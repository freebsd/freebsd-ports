PORTNAME=	URI-Sequin
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SARGIE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extract information from the URLs of Search-Engines

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/URI/Sequin/examples
	${INSTALL_DATA} ${WRKSRC}/example.pl ${WRKSRC}/ref?.log \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/URI/Sequin/examples

.include <bsd.port.mk>
