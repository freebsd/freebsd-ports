# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	convertall
PORTVERSION=	0.5.2
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-i18n-${PORTVERSION}a${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another unit converter

LICENSE=	GPLv2 # (or later)

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui

WRKSRC=		${WRKDIR}/ConvertAll

USE_PYTHON=	yes

DESKTOP_ENTRIES="ConvertAll" "Unit converter" "${DATADIR}/icons/${PORTNAME}.svg" \
		"${PORTNAME}" "Utility;Calculator;" true

OPTIONS_DEFINE=	DOCS

post-patch:
	@cd ${WRKSRC}/source && ${REINPLACE_CMD} -e \
		"/^dataFilePath/s|None|\'${DATADIR}\'|g ; \
		 /^helpFilePath/s|None|\'${DOCSDIR}\'|g ; \
		 /^iconPath/s|None|\'${DATADIR}/icons\'|g ; \
		 /^translationPath/s|'translations'|'${DATADIR}/translations'|" convertall.py

do-build:
	@${ECHO_CMD} '#!/bin/sh' > ${WRKDIR}/convertall.sh
	@${ECHO_CMD} 'exec ${PYTHON_CMD} ${PYTHON_SITELIBDIR}/convertall/convertall.py $$*' >> ${WRKDIR}/convertall.sh
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/source
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/source

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/convertall.sh ${STAGEDIR}${PREFIX}/bin/convertall
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/convertall
	${INSTALL_DATA} ${WRKSRC}/source/*.py ${STAGEDIR}${PYTHON_SITELIBDIR}/convertall
	${INSTALL_DATA} ${WRKSRC}/source/*.pyc ${STAGEDIR}${PYTHON_SITELIBDIR}/convertall
	${INSTALL_DATA} ${WRKSRC}/source/*.pyo ${STAGEDIR}${PYTHON_SITELIBDIR}/convertall
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/*.dat ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/icons/*.png ${STAGEDIR}${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/icons/*.svg ${STAGEDIR}${DATADIR}/icons
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/translations/*.qm ${STAGEDIR}${DATADIR}/translations
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
