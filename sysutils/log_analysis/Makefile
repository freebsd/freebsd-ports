# Created by: petef@FreeBSD.org
# $FreeBSD$

PORTNAME=	log_analysis
PORTVERSION=	0.46
CATEGORIES=	sysutils
MASTER_SITES=	http://userpages.umbc.edu/~mabzug1/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility that extracts a summary of useful data from logs

LICENSE=	GPLv3

USES=		perl5
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL="${PERL}"

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/log_analysis \
		man/man1/log_analysis.1.gz \
		%%DATADIR%%/AUTHORS \
		%%DATADIR%%/Tk/resizebutton.pm
PLIST_DIRS=	%%DATADIR%%/Tk \
		%%DATADIR%%

OPTIONS_DEFINE=	DOCS EXAMPLES TK

TK_RUN_DEPENDS=	p5-Tk>0:${PORTSDIR}/x11-toolkits/p5-Tk

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/Tutorial ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sample-* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
