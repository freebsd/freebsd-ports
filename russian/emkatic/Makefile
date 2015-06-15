# Created by: Andrey Fesenko <andrey@bsdnir.info>
# $FreeBSD$

PORTNAME=	emkatic
PORTVERSION=	0.20
PORTREVISION=	2
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
LAZARUS_VER=	1.4.0
LAZBUILD_CMD=	${LOCALBASE}/bin/lazbuild -d --pcp=${WRKSRC}/tmppcp
LAZARUS_DIR=	${LOCALBASE}/share/lazarus-${LAZARUS_VER}
LCL_UNITS_DIR=	${LAZARUS_DIR}/lcl/units/${BUILDNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.txt

OPTIONS_DEFINE=		DOCS PORTAUDIO
OPTIONS_SINGLE=		GUI
OPTIONS_SINGLE_GUI=	GTK2 QT4
OPTIONS_DEFAULT=	GTK2 PORTAUDIO

GTK2_DESC=	Build with GTK+ 2 interface
QT4_DESC=	Build with Qt 4 interface

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:${PORTSDIR}/audio/portaudio

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
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
