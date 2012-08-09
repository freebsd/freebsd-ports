# New ports collection makefile for:	transmission-remote-gui
# Date created:		2009-05-20
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	transmission-remote-gui
PORTVERSION=	4.0.3
PORTREVISION=	0
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	transgui-${PORTVERSION}-src

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Remote GUI for transmission daemon

BUILD_DEPENDS=	lazbuild:${PORTSDIR}/editors/lazarus \
		fpcres:${PORTSDIR}/lang/fpc-utils
RUN_DEPENDS=	transmission-daemon:${PORTSDIR}/net-p2p/transmission-daemon

PROJECTHOST=	transmisson-remote-gui

USE_ZIP=	yes
USE_FPC=	fcl-net
USE_ICONV=	yes
USE_GNOME=	#

WRKSRC=		${WRKDIR}/TransGUI
PLIST_FILES=	bin/transgui
SUB_FILES=	pkg-message

LAZARUS_PROJECT_FILE=	transgui.lpi
LAZBUILD_CMD=		${LOCALBASE}/bin/lazbuild
LCL_UNITS_DIR=		${LOCALBASE}/share/lazarus/lcl/units/${BUILDNAME}

OPTIONS=	GTK2    "Use gtk20 interface instead of gtk12"  on \
		QT4     "Use qt4 interface" off

.include <bsd.port.pre.mk>

.if defined(WITH_GTK2) && defined(WITH_QT4)
IGNORE=	Please select only one option QT4 or GTK2, don't select both options
.endif

.if defined(WITH_GTK2)
USE_FPC+=	gtk2
USE_GNOME=	gtk20 gdkpixbuf
LCL_PLATFORM=	gtk2
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-gtk2
.else
.if !defined(WITH_QT4)
USE_FPC+=	gtk1
USE_GNOME=	gtk12 gdkpixbuf
LCL_PLATFORM=	gtk
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-gtk
.endif
.endif

.if defined(WITH_QT4)
LIB_DEPENDS+=	Qt4Pas.5:${PORTSDIR}/x11-toolkits/qt4pas
LCL_PLATFORM=	qt
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-qt
.endif

do-build:
	@cd ${WRKSRC} && \
		${LAZBUILD_CMD} --ws=${LCL_PLATFORM} ${LAZARUS_PROJECT_FILE}

do-install:
	@cd ${WRKSRC}/units && \
		${INSTALL_PROGRAM} transgui ${PREFIX}/bin

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
