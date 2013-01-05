# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	geogebra
PORTVERSION=	4.2.13.0
#PORTREVISION=	0
CATEGORIES=	math java
MASTER_SITES=	GOOGLE_CODE
PKGNAMESUFFIX=	-i18n
DISTNAME=	GeoGebra-Unixlike-Installer-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Dynamic software that joins geometry, algebra, and calculus

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/bin/update-mime-database:${PORTSDIR}/misc/shared-mime-info

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

INSTALLS_ICONS=	yes

JAVA_VERSION=	1.6+

NO_BUILD=	yes

USE_GNOME=	desktopfileutils
USE_JAVA=	yes

WRKSRC=	${WRKDIR}/geogebra-${PORTVERSION}

FIND_JARS=	-type f -name "*.jar" -maxdepth 1 -print0

do-install:
	cd ${WRKSRC} && ${MKDIR} ${DATADIR} && \
	${INSTALL_SCRIPT} ${WRKSRC}/geogebra ${DATADIR} && \
	${LN} -s ${DATADIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME} && \
	${FIND} . ${FIND_JARS} | ${XARGS} -0 -J % ${INSTALL_DATA} % ${DATADIR} && \
	${COPYTREE_SHARE} icons ${PREFIX}/share && \
	${MKDIR} ${PREFIX}/share/mime/packages && \
	${MKDIR} ${PREFIX}/share/applications && \
	${INSTALL_DATA} ${WRKSRC}/geogebra.xml ${PREFIX}/share/mime/packages && \
	${INSTALL_DATA} ${WRKSRC}/geogebra.desktop ${DESKTOPDIR}
	-${LOCALBASE}/bin/update-desktop-database
	-${LOCALBASE}/bin/update-mime-database ${LOCALBASE}/share/mime

.include <bsd.port.mk>
