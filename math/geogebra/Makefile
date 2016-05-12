# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	geogebra
PORTVERSION=	5.0.236.0
CATEGORIES=	math java
MASTER_SITES=	http://download.geogebra.org/installers/5.0/ \
		http://freebsd.uzsolt.hu/src/
DISTNAME=	GeoGebra-Linux-Portable-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} geogebra.png
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	udvzsolt@gmail.com
COMMENT=	Dynamic software that joins geometry, algebra, and calculus

LICENSE=	GEOGEBRA
LICENSE_NAME=	GeoGebra Non-Commercial License Agreement
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

USE_LINUX?=	c6

USE_LINUX_APPS=	xorglibs

ONLY_FOR_ARCHS=	i386 amd64

SUB_FILES=	geogebra.desktop
CONFLICTS=	math/geogebra-i18n-[0-9]*
NO_BUILD=	yes
USES=		tar:bzip2 desktop-file-utils shared-mime-info shebangfix
WRKSRC=		${WRKDIR}/${DISTNAME}
JAVADIR=	jre1.7.0_45-i686

SUB_FILES=	geogebra.desktop geogebra.sh
SUB_LIST=	JAVADIR=${DATADIR}/${JAVADIR}

INSTALLS_ICONS=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/geogebra.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/geogebra/*.jar ${STAGEDIR}${DATADIR}/${PORTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${JAVADIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${JAVADIR}/bin/java ${STAGEDIR}${DATADIR}/${JAVADIR}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKDIR}/geogebra.desktop ${STAGEDIR}${DESKTOPDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps
	${INSTALL_DATA} ${DISTDIR}/geogebra.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/geogebra.png

.include <bsd.port.mk>
