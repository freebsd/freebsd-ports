# Created by: petef@FreeBSD.org
# $FreeBSD$

PORTNAME=	log_analysis
PORTVERSION=	0.46
CATEGORIES=	sysutils
MASTER_SITES=	http://userpages.umbc.edu/~mabzug1/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility that extracts a summary of useful data from logs

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL="${PERL}"
NO_ARCH=	yes

PORTDOCS=	*
PORTEXAMPLES=	*
PORTDATA=	*
PLIST_FILES=	bin/log_analysis \
		man/man1/log_analysis.1.gz

OPTIONS_DEFINE=	DOCS EXAMPLES TK

TK_RUN_DEPENDS=	p5-Tk>0:x11-toolkits/p5-Tk

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/NEWS \
		${WRKSRC}/AUTHORS ${WRKSRC}/doc/Tutorial \
		${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sample-* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
