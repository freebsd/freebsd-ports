# Created by: Greg Lehey <grog@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tempcontrol
PORTVERSION=	1.2
CATEGORIES=	misc
MASTER_SITES=	http://www.lemis.com/grog/brewing/src/brewing/tempcontrol/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Temperature control for fermenting beer and other applications

LICENSE=	BSD2CLAUSE

USES=		readline
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/tempcontrol share/tempcontrol/temperaturecontrolrc.sample \
		etc/rc.d/temperaturecontrol.sh.sample
PLIST_DIRS=	share/tempcontrol

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

# Must (re)generate depedencies, otherwise parallel builds would not work
pre-build:
	${DO_MAKE_BUILD} -C ${WRKSRC} depend

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tempcontrol ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/temperaturecontrolrc.sample \
		${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/temperaturecontrol.sh.sample \
		${STAGEDIR}${PREFIX}/etc/rc.d

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
