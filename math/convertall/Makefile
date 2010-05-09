# New ports collection makefile for:	convertall
# Date created:		2004-08-12
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	convertall
PORTVERSION=	0.5.0
CATEGORIES=	math
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another unit converter

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui

WRKSRC=		${WRKDIR}/ConvertAll

USE_PYTHON=	2.4+

post-patch:
	@cd ${WRKSRC}/source && ${REINPLACE_CMD} -e \
		"/^dataFilePath/s|None|\'${DATADIR}\'|g ; \
		 /^helpFilePath/s|None|\'${DOCSDIR}\'|g" convertall.py

do-build:
	@${ECHO_CMD} '#!/bin/sh' > ${WRKDIR}/convertall.sh
	@${ECHO_CMD} 'exec ${PYTHON_CMD} ${PYTHON_SITELIBDIR}/convertall/convertall.py $$*' >> ${WRKDIR}/convertall.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/convertall.sh ${PREFIX}/bin/convertall
	@${MKDIR} ${PYTHON_SITELIBDIR}/convertall
	${INSTALL_DATA} ${WRKSRC}/source/*.py ${PYTHON_SITELIBDIR}/convertall
	@${CHMOD} ${BINMODE} ${PYTHON_SITELIBDIR}/convertall/convertall.py
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PYTHON_SITELIBDIR}/convertall
	@${MKDIR} ${PREFIX}/share/icons
	${INSTALL_DATA} ${WRKSRC}/icons/convertall.svg ${PREFIX}/share/icons
	${INSTALL_DATA} ${WRKSRC}/icons/convertall_*.png ${PREFIX}/share/icons
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/*.dat ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
