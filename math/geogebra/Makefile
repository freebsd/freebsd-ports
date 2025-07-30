PORTNAME=	geogebra
DISTVERSION=	5-2-894-2
CATEGORIES=	math education java
MASTER_SITES=	http://download.geogebra.org/installers/5.2/ \
		https://static.geogebra.org/images/ \
		http://freebsd.uzsolt.hu/src/
DISTNAME=	GeoGebra-Linux-Portable-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		geogebra.png \
		geogebra-logo.svg
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Dynamic software that joins geometry, algebra, and calculus
WWW=		https://www.geogebra.org/

LICENSE=	GEOGEBRA
LICENSE_NAME=	GeoGebra Non-Commercial License Agreement
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64 i386

USES=		desktop-file-utils gnome java shared-mime-info shebangfix \
		tar:bzip2
JAVA_VERSION=	17+

CONFLICTS=	math/geogebra-i18n

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	geogebra.desktop geogebra.sh
SUB_LIST=	JAVA=${JAVA}

WRKSRC=		${WRKDIR}/${DISTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/geogebra.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/geogebra/*.jar ${STAGEDIR}${DATADIR}/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${FILESDIR}/geogebra-mime.xml ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKDIR}/geogebra.desktop ${STAGEDIR}${DESKTOPDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${DISTDIR}/geogebra.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/geogebra.png
	${INSTALL_DATA} ${DISTDIR}/geogebra-logo.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/geogebra.svg

.include <bsd.port.mk>
