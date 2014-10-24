# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xpn
PORTVERSION=	1.2.6
PORTREVISION=	4
CATEGORIES=	news python
MASTER_SITES=	http://xpn.altervista.org/codice/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	X Python Newsreader

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2

NO_BUILD=	yes

FIND_DIRS=	-type d
FIND_DATA=	-type f -mindepth 2 -not -name "*~"

SUB_FILES=	${PORTNAME}
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} XPN=${XPN}

USES=		gettext python

XPN=	${PORTNAME}.py

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${XPN} ${STAGEDIR}${DATADIR}/${XPN}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	cd ${WRKSRC} && ${FIND} . ${FIND_DIRS} -exec ${MKDIR} ${STAGEDIR}${DATADIR}/{} ";"
	cd ${WRKSRC} && ${FIND} . ${FIND_DATA} -exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/{} ";"
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
