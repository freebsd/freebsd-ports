# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	WinFF
PORTVERSION=	1.5.2
PORTREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	${_PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Convert your videos quickly, easily, and all at once

LICENSE=	GPLv3

BUILD_DEPENDS=	lazbuild:editors/lazarus
LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg

NO_WRKSUBDIR=	yes
USE_FPC=	cairo fcl-base fcl-image fcl-json fcl-xml pasjpeg x11
USE_GNOME=	#
_PORTNAME=	${PORTNAME:tl}
DATADIR=	${PREFIX}/share/${_PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${_PORTNAME}
INSTALLS_ICONS=	yes

DESKTOP_ENTRIES=	"${PORTNAME}"	\
			"${COMMENT}"	\
			"${_PORTNAME}"	\
			"${_PORTNAME}"	\
			"AudioVideo;"	\
			true

LAZBUILD_CMD=	${LOCALBASE}/bin/lazbuild -d
LAZARUS_VER=	1.6.0
LAZARUS_DIR=	${LOCALBASE}/share/lazarus-${LAZARUS_VER}
LCL_UNITS_DIR=	${LOCALBASE}/share/lazarus-${LAZARUS_VER}/lcl/units/${BUILDNAME}

OPTIONS_SINGLE=		LCL
OPTIONS_SINGLE_LCL=	GTK2 QT4

GTK2_DESC=		Use gtk20 interface
QT4_DESC=		Use qt4 interface

OPTIONS_DEFAULT=	GTK2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
USE_FPC+=	gtk2
USE_GNOME+=	gtk20
LCL_PLATFORM=	gtk2
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:editors/lazarus-lcl-gtk2
.endif

.if ${PORT_OPTIONS:MQT4}
LIB_DEPENDS+=	libQt4Pas.so:x11-toolkits/qt4pas
LCL_PLATFORM=	qt
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:editors/lazarus-lcl-qt
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' ${WRKSRC}/unit1.pas
.for fp in unit1.pas unit4.pas
	${REINPLACE_CMD} -e 's|/usr/bin/|${LOCALBASE}/bin/|g' ${WRKSRC}/${fp}
.endfor

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LAZBUILD_CMD} --ws=${LCL_PLATFORM} --lazarusdir=${LAZARUS_DIR} -B winff.lpr

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME:tl} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/languages
	${INSTALL_DATA} ${WRKSRC}/presets.xml ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/languages/* ${STAGEDIR}${DATADIR}/languages/
	${INSTALL_MAN} ${WRKSRC}/${_PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/winff-icons/48x48/${_PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
