# Created by: Heiner Eichmann <h.eichmann@gmx.de>
# $FreeBSD$

PORTNAME=	gdialog
PORTVERSION=	2.5
CATEGORIES=	multimedia java
MASTER_SITES=	SF/${PORTNAME}-x/${PORTNAME}-090400/${PORTVERSION}
DISTNAME=	GDialog-090400-25

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Project X addon to read Siemens Gigaset M740AV video recordings

LICENSE=	GPLv2

BUILD_DEPENDS=	projectx>=0.90.4.00:multimedia/projectx
RUN_DEPENDS=	projectx>=0.90.4.00:multimedia/projectx

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
SUB_FILES=	gdialog
DATADIR=	${JAVASHAREDIR}/projectx

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/GDialog.jar ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ReleaseNotes.txt ${STAGEDIR}${DATADIR}/GDialog-ReleaseNotes.txt
	${INSTALL_DATA} ${WRKSRC}/Copying ${STAGEDIR}${DATADIR}/GDialog-Copying
	${INSTALL_SCRIPT} ${WRKDIR}/gdialog ${STAGEDIR}${PREFIX}/bin/gdialog

.include <bsd.port.mk>
