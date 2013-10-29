# Created by: Gregory Edigarov <greg@bestnet.kharkov.ua>
# $FreeBSD$

PORTNAME=	sflowtool
PORTVERSION=	3.30
CATEGORIES=	net
MASTER_SITES=	http://www.inmon.com/bin/

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	sFlow capture and sFlow-to-NetFlow conversion tool

GNU_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	bin/sflowtool
PORTDOCS=	README
PORTEXAMPLES=	README ipTopTalkers ipTrafficMatrix sflowRRDChart.cgi \
		sflowRRDLoad sflowenable

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/scripts/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
