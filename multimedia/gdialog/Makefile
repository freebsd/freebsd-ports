# New ports collection makefile for:	gdialog
# Date created:			Sun Apr 19 21:30:26 CEST 2009
# Whom:				Heiner Eichmann <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	gdialog
PORTVERSION=	2.5
CATEGORIES=	multimedia java
MASTER_SITES=	SF/${PORTNAME}-x/${PORTNAME}-090400/${PORTVERSION}
DISTNAME=	GDialog-090400-25

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	A Project X addon to read Siemens Gigaset M740AV video recordings

BUILD_DEPENDS=	projectx>=0.90.4.00:${PORTSDIR}/multimedia/projectx
RUN_DEPENDS=	projectx>=0.90.4.00:${PORTSDIR}/multimedia/projectx

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.3+
USE_JIKES=	no

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
SUB_FILES=	gdialog
DATADIR=	${JAVASHAREDIR}/projectx

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/GDialog.jar ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ReleaseNotes.txt ${DATADIR}/GDialog-ReleaseNotes.txt
	${INSTALL_DATA} ${WRKSRC}/Copying ${DATADIR}/GDialog-Copying
	${INSTALL_SCRIPT} ${WRKDIR}/gdialog ${PREFIX}/bin/gdialog

.include <bsd.port.mk>
