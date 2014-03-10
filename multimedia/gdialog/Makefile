# Created by: Heiner Eichmann <h.eichmann@gmx.de>
# $FreeBSD$

PORTNAME=	gdialog
PORTVERSION=	2.5
CATEGORIES=	multimedia java
MASTER_SITES=	SF/${PORTNAME}-x/${PORTNAME}-090400/${PORTVERSION}
DISTNAME=	GDialog-090400-25

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Project X addon to read Siemens Gigaset M740AV video recordings

BUILD_DEPENDS=	projectx>=0.90.4.00:${PORTSDIR}/multimedia/projectx
RUN_DEPENDS=	projectx>=0.90.4.00:${PORTSDIR}/multimedia/projectx

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
SUB_FILES=	gdialog
DATADIR=	${JAVASHAREDIR}/projectx

NO_STAGE=	yes
do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/GDialog.jar ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ReleaseNotes.txt ${DATADIR}/GDialog-ReleaseNotes.txt
	${INSTALL_DATA} ${WRKSRC}/Copying ${DATADIR}/GDialog-Copying
	${INSTALL_SCRIPT} ${WRKDIR}/gdialog ${PREFIX}/bin/gdialog

.include <bsd.port.mk>
