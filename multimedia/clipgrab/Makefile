# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clipgrab
PORTVERSION=	3.2.0.10
CATEGORIES=	multimedia
MASTER_SITES=	http://clipgrab.de/download/ \
		http://vanbittern.org/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Program to download videos from YouTube and etc

LICENSE=	GPLv3

USE_BZIP2=	yes
USE_QT4=	gui xml qmake_build uic_build moc_build \
		rcc_build network dbus webkit

PLIST_FILES=	bin/${PORTNAME} \
		%%DATADIR%%/icon.png \
		%%DATADIR%%/logo.png \
		%%DATADIR%%/paypal-logo.png \
		%%DATADIR%%/paypal.png \
		%%DATADIR%%/splash.png
PLIST_DIRS=	%%DATADIR%%

DESKTOP_ENTRIES="Clipgrab" "Download and convert videos from YouTube and etc" \
		"${DATADIR}/icon.png" "${PORTNAME}" \
		"AudioVideo;" false

post-patch:
	${REINPLACE_CMD} -e 's,img/,share/${PORTNAME}/,g' \
	${WRKSRC}/*.cpp

do-configure:
	cd ${WRKSRC} && ${QMAKE}

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.png ${DATADIR}

.include <bsd.port.mk>
