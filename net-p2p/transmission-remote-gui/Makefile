# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	transmission-remote-gui
PORTVERSION=	4.1
PORTREVISION=	2
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	transgui-${PORTVERSION}-src

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Remote GUI for transmission daemon

BUILD_DEPENDS=	lazbuild:${PORTSDIR}/editors/lazarus \
		fpcres:${PORTSDIR}/lang/fpc-utils
RUN_DEPENDS=	transmission-daemon:${PORTSDIR}/net-p2p/transmission-daemon

PROJECTHOST=	transmisson-remote-gui

USE_FPC=	fcl-net
USES=		iconv zip
USE_GNOME=	#

WRKSRC=		${WRKDIR}/TransGUI
PLIST_FILES=	bin/transgui
SUB_FILES=	pkg-message

LAZARUS_PROJECT_FILE=	transgui.lpi
LAZBUILD_CMD=		${LOCALBASE}/bin/lazbuild -d
LCL_UNITS_DIR=		${LOCALBASE}/share/lazarus/lcl/units/${BUILDNAME}
LAZARUS_DIR=		${LOCALBASE}/share/lazarus

OPTIONS_SINGLE=		LCL
OPTIONS_SINGLE_LCL=	GTK1 GTK2 QT4

GTK1_DESC=		Use gtk12 interface
GTK2_DESC=		Use gtk20 interface
QT4_DESC=		Use qt4 interface

OPTIONS_DEFAULT=	GTK2

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGTK2}
USE_FPC+=	gtk2
USE_GNOME=	gtk20 gdkpixbuf
LCL_PLATFORM=	gtk2
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-gtk2
.endif

.if ${PORT_OPTIONS:MGTK1}
USE_FPC+=	gtk1
USE_GNOME=	gtk12 gdkpixbuf
LCL_PLATFORM=	gtk
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-gtk
.endif

.if ${PORT_OPTIONS:MQT4}
LIB_DEPENDS+=	Qt4Pas.5:${PORTSDIR}/x11-toolkits/qt4pas
LCL_PLATFORM=	qt
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-qt
.endif

do-build:
	@cd ${WRKSRC} && \
		${LAZBUILD_CMD} --ws=${LCL_PLATFORM} --lazarusdir=${LAZARUS_DIR} ${LAZARUS_PROJECT_FILE}

do-install:
	@cd ${WRKSRC}/units && \
		${INSTALL_PROGRAM} transgui ${PREFIX}/bin

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
