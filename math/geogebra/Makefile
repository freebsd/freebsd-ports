# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	geogebra
PORTVERSION=	5.0.580.0
CATEGORIES=	math java
MASTER_SITES=	http://download.geogebra.org/installers/5.0/ \
		https://static.geogebra.org/images/ \
		http://freebsd.uzsolt.hu/src/
DISTNAME=	GeoGebra-Linux-Portable-${PORTVERSION:S/./-/g}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} geogebra.png geogebra-logo.svg
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Dynamic software that joins geometry, algebra, and calculus

LICENSE=	GEOGEBRA
LICENSE_NAME=	GeoGebra Non-Commercial License Agreement
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64 i386

USES=		tar:bzip2 desktop-file-utils gnome shebangfix
USE_JAVA=	yes

CONFLICTS=	math/geogebra-i18n-[0-9]*

NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

SUB_FILES=	geogebra.desktop geogebra.sh
SUB_LIST=	JAVA=${JAVA}

INSTALLS_ICONS=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/geogebra.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/geogebra/*.jar ${STAGEDIR}${DATADIR}/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKDIR}/geogebra.desktop ${STAGEDIR}${DESKTOPDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${DISTDIR}/geogebra.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/geogebra.png
	${INSTALL_DATA} ${DISTDIR}/geogebra-logo.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/geogebra.svg

.include <bsd.port.mk>
