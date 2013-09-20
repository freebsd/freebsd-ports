# Created by: petef@FreeBSD.org
# $FreeBSD$

PORTNAME=	log_analysis
PORTVERSION=	0.46
CATEGORIES=	sysutils
MASTER_SITES=	http://userpages.umbc.edu/~mabzug1/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility that extracts a summary of useful data from logs

LICENSE=	GPLv3

OPTIONS_DEFINE=	DOCS EXAMPLES TK

USES=		perl5
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL="${PERL}"

MAN1=		log_analysis.1
PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/log_analysis \
		%%DATADIR%%/AUTHORS \
		%%DATADIR%%/Tk/resizebutton.pm
PLIST_DIRS=	%%DATADIR%%/Tk \
		%%DATADIR%%

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTK}
RUN_DEPENDS+=	p5-Tk>0:${PORTSDIR}/x11-toolkits/p5-Tk
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/Tutorial ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sample-* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
