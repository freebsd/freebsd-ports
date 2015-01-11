# Created by: Andrey Fesenko <andrey@bsdnir.info>
# $FreeBSD$

PORTNAME=	emkatic
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	russian emulators
MASTER_SITES=	SF/${PORTNAME}/eMKatic%20Source
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	andrey@bsdnir.info
COMMENT=	Emulator of Elektronika RPN programmable calculator series

LICENSE=	GPLv3 # or later
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	lazbuild:${PORTSDIR}/editors/lazarus \
		fpcres:${PORTSDIR}/lang/fpc-utils

USE_FPC=	yes
WANT_GNOME=	yes

PROJECT_FILE=	emkatic.lpi
LAZARUS_VER=	1.2.6
LAZBUILD_CMD=	${LOCALBASE}/bin/lazbuild -d --pcp=${WRKSRC}/tmppcp
LAZARUS_DIR=	${LOCALBASE}/share/lazarus-${LAZARUS_VER}
#BUILD_MODE=	SrcDist

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=		PORTAUDIO
OPTIONS_SINGLE=		LCL
OPTIONS_SINGLE_LCL=	GTK2 QT4

GTK2_DESC=		Use gtk20 interface
QT4_DESC=		Use qt4 interface

OPTIONS_DEFAULT=        PORTAUDIO GTK2

PORTAUDIO_RUN_DEPENDS=	${LOCALBASE}/lib/portaudio2/libportaudio.so.2:${PORTSDIR}/audio/portaudio2

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGTK2}
USE_FPC+=	gtk2
USE_GNOME=	gtk20
LCL_PLATFORM=	gtk2
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-gtk2
.endif

.if ${PORT_OPTIONS:MQT4}
LIB_DEPENDS+=	libQt4Pas.so:${PORTSDIR}/x11-toolkits/qt4pas
LCL_PLATFORM=	qt
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-qt
.endif

do-build:
	@cd ${WRKSRC} && \
		${LAZBUILD_CMD} --ws="${LCL_PLATFORM}" --lazarusdir=${LAZARUS_DIR} ${PROJECT_FILE}

do-install:
	@cd ${WRKSRC} && \
		${INSTALL_PROGRAM} emkatic ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
