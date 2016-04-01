# Created by: Andrey Fesenko <andrey@bsdnir.info>
# $FreeBSD$

PORTNAME=	emkatic
PORTVERSION=	0.27
CATEGORIES=	russian emulators
MASTER_SITES=	SF/${PORTNAME}/eMKatic%20Source
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	andrey@bsdnir.info
COMMENT=	Emulator of Elektronika RPN programmable calculator series

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	lazbuild:editors/lazarus \
		fpcres:lang/fpc-utils

USE_FPC=	cairo fcl-base fcl-image fcl-json fcl-xml pasjpeg x11

PROJECT_FILE=	emkatic.lpi
LAZARUS_VER=	1.6.0
LAZBUILD_CMD=	${LOCALBASE}/bin/lazbuild -d --pcp=${WRKSRC}/tmppcp
LAZARUS_DIR=	${LOCALBASE}/share/lazarus-${LAZARUS_VER}
LCL_UNITS_DIR=	${LAZARUS_DIR}/lcl/units/${BUILDNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*
PORTDOCS=	CHANGELOG.*.txt README.*.txt

OPTIONS_DEFINE=		DOCS PORTAUDIO
OPTIONS_SINGLE=		GUI
OPTIONS_SINGLE_GUI=	GTK2 QT4
OPTIONS_DEFAULT=	GTK2 PORTAUDIO

GTK2_DESC=	Build with GTK+ 2 interface
QT4_DESC=	Build with Qt 4 interface

GTK2_BUILD_DEPENDS=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:editors/lazarus-lcl-gtk2
GTK2_USE=		GNOME=gtk20 FPC=gtk2

QT4_BUILD_DEPENDS=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:editors/lazarus-lcl-qt
QT4_LIB_DEPENDS=	libQt4Pas.so:x11-toolkits/qt4pas

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
LCL_PLATFORM=	gtk2
.endif

.if ${PORT_OPTIONS:MQT4}
LCL_PLATFORM=	qt
.endif

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LAZBUILD_CMD} --ws="${LCL_PLATFORM}" \
			--lazarusdir=${LAZARUS_DIR} ${PROJECT_FILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
