# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clipgrab
PORTVERSION=	3.4.11
CATEGORIES=	multimedia
MASTER_SITES=	http://download.clipgrab.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to download videos from YouTube and etc

LICENSE=	GPLv3

USES=		qmake tar:bzip2
USE_QT4=	gui xml uic_build moc_build \
		rcc_build network dbus webkit

PLIST_FILES=	bin/${PORTNAME} \
		%%DATADIR%%/icon.png \
		%%DATADIR%%/logo.png \
		%%DATADIR%%/paypal-logo.png \
		%%DATADIR%%/splash.png

DESKTOP_ENTRIES="Clipgrab" "Download and convert videos from YouTube and etc" \
		"${DATADIR}/icon.png" "${PORTNAME}" \
		"AudioVideo;" true

QMAKE_SOURCE_PATH=	${WRKSRC}/${PORTNAME}.pro

post-patch:
	${REINPLACE_CMD} -e 's,img/,share/${PORTNAME}/,g' \
	${WRKSRC}/*.cpp

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.png ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
