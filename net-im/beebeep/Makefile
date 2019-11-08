# $FreeBSD$

PORTNAME=	beebeep
DISTVERSIONPREFIX=code-
DISTVERSION=	5.8.2
CATEGORIES=	net-im
MASTER_SITES=	SF/${PORTNAME}/Sources/
# Weird SVN-versioned directory in the source zip
WRKSRC=		${WRKDIR}/${PORTNAME}-code-r1352

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Secure office (Local-area-network) chat

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c++17-lang pkgconfig \
		qmake qt:5 zip
USE_QT=		core gui multimedia network widgets x11extras \
		buildtools_build linguist_build

do-install:
	${MKDIR} ${STAGEDIR}${LOCALBASE}/bin ${STAGEDIR}${QT_PLUGINDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/test/beebeep ${STAGEDIR}${LOCALBASE}/bin/
	${INSTALL_LIB} ${WRKSRC}/test/libnumbertextmarker.so ${STAGEDIR}${QT_PLUGINDIR}/
	${INSTALL_LIB} ${WRKSRC}/test/librainbowtextmarker.so ${STAGEDIR}${QT_PLUGINDIR}/
	${INSTALL_LIB} ${WRKSRC}/test/libregularboldtextmarker.so ${STAGEDIR}${QT_PLUGINDIR}/

PLIST_FILES=	bin/beebeep \
		lib/qt5/plugins/libnumbertextmarker.so \
		lib/qt5/plugins/librainbowtextmarker.so \
		lib/qt5/plugins/libregularboldtextmarker.so

.include <bsd.port.mk>
