# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	transmission-remote-gui
PORTVERSION=	5.0.1
PORTREVISION=	9
CATEGORIES=	net-p2p
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	transgui-${PORTVERSION}-src

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Remote GUI for transmission daemon

BUILD_DEPENDS=	lazbuild:editors/lazarus \
		fpcres:lang/fpc-utils
RUN_DEPENDS=	transmission-daemon:net-p2p/transmission-daemon

PROJECTHOST=	transmisson-remote-gui

USE_FPC=	cairo fcl-base fcl-image fcl-net pasjpeg rtl-objpas rtl-extra \
		x11
USES=		iconv zip
USE_GNOME=	#

WRKSRC=		${WRKDIR}/TransGUI
PLIST_FILES=	bin/transgui
SUB_FILES=	pkg-message

LAZARUS_PROJECT_FILE=	transgui.lpi
LAZBUILD_CMD=		${LOCALBASE}/bin/lazbuild -d
LCL_UNITS_DIR=		${LOCALBASE}/share/lazarus-${LAZARUS_VER}/lcl/units/${BUILDNAME}
LAZARUS_VER=		1.6.0
LAZARUS_DIR=		${LOCALBASE}/share/lazarus-${LAZARUS_VER}

OPTIONS_SINGLE=		LCL
OPTIONS_SINGLE_LCL=	GTK2 QT4

GTK2_DESC=		Use gtk20 interface
QT4_DESC=		Use qt4 interface

OPTIONS_DEFAULT=	GTK2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
USE_FPC+=	gtk2
USE_GNOME=	gtk20
LCL_PLATFORM=	gtk2
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:editors/lazarus-lcl-gtk2
.endif

.if ${PORT_OPTIONS:MQT4}
LIB_DEPENDS+=	libQt4Pas.so:x11-toolkits/qt4pas
LCL_PLATFORM=	qt
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:editors/lazarus-lcl-qt
.endif

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LAZBUILD_CMD} --ws=${LCL_PLATFORM} --lazarusdir=${LAZARUS_DIR} ${LAZARUS_PROJECT_FILE}

do-install:
	@cd ${WRKSRC}/units && \
		${INSTALL_PROGRAM} transgui ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
