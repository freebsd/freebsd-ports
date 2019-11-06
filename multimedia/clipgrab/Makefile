# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clipgrab
PORTVERSION=	3.7.2
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	https://download.clipgrab.org/

PATCH_SITES=	https://gitlab.com/kikadf/clipgrab-qt5/raw/patches/patches/
PATCHFILES=	clipgrab-qt5-${PORTVERSION}.patch:-p1

MAINTAINER=	kikadf.01@gmail.com
COMMENT=	Program to download videos from YouTube and etc

BROKEN=		unfetchable

LICENSE=	GPLv3

USES=		compiler:c++11-lang qmake qt:5
USE_QT=		core dbus gui network webkit widgets xml buildtools_build

LDFLAGS+=	-Wl,--as-needed # cf. PR 224488
PLIST_FILES=	bin/${PORTNAME} \
		${DATADIR}/icon.png \
		${DATADIR}/logo.png \
		${DATADIR}/paypal-logo.png \
		${DATADIR}/splash.png

DESKTOP_ENTRIES="Clipgrab" "Download and convert videos from YouTube and etc" \
		"${DATADIR}/icon.png" "${PORTNAME}" \
		"AudioVideo;" true

QMAKE_SOURCE_PATH=	${WRKSRC}/${PORTNAME}.pro

post-patch:
	@${REINPLACE_CMD} -e 's,img/,share/${PORTNAME}/,g' ${WRKSRC}/*.cpp

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.png ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
