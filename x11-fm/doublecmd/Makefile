# Created by: Beñat Gonzalez Etxepare <bbtruk@users.sourceforge.net>
# $FreeBSD$

PORTNAME=	doublecmd
PORTVERSION=	0.5.4
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}/Double%20Commander%20Source
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${PORTNAME}-${PORTVERSION}-src.tar.gz ${PORTNAME}-help-0.5.1-src.tar.gz

MAINTAINER=	bbtruk@users.sourceforge.net
COMMENT=	Total Commander like file manager for the X Window System

BUILD_DEPENDS=	lazbuild:${PORTSDIR}/editors/lazarus \
		fpcres:${PORTSDIR}/lang/fpc-utils

ONLY_FOR_ARCHS=	i386 amd64

MAN1=		${PORTNAME}.1
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(pas)
USE_FPC=	yes
USE_GNOME=	desktopfileutils
PLIST=		${WRKDIR}/pkg-plist
SUB_FILES=	pkg-message
PROJECT_FILE=	src/doublecmd.lpi
LAZBUILD_CMD=	${LOCALBASE}/bin/lazbuild -d
LAZARUS_DIR=	${LOCALBASE}/share/lazarus
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DOCSRC=		${WRKDIR}/${PORTNAME}-help-0.5.1

OPTIONS_DEFINE=		DEBUG
OPTIONS_SINGLE=		LCL
OPTIONS_SINGLE_LCL=	GTK2 QT4

GTK2_DESC=		Use gtk20 interface
QT4_DESC=		Use qt4 interface
DEBUG_DESC=		Build with complete symbolic debug information

OPTIONS_DEFAULT=	GTK2

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGTK2}
USE_FPC+=	gtk2
USE_GNOME=	gtk20 gdkpixbuf
LCL_PLATFORM=	gtk2
BUILD_DEPENDS+=	${LOCALBASE}/share/lazarus/lcl/units/${BUILDNAME}/${LCL_PLATFORM}/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-gtk2
.endif

.if ${PORT_OPTIONS:MQT4}
LIB_DEPENDS+=	Qt4Pas:${PORTSDIR}/x11-toolkits/qt4pas
LCL_PLATFORM=	qt
BUILD_DEPENDS+=	${LOCALBASE}/share/lazarus/lcl/units/${BUILDNAME}/${LCL_PLATFORM}/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-qt
.endif

.if ${PORT_OPTIONS:MDEBUG}
BUILD_MODE=	Debug
.else
BUILD_MODE=	NoDebug Full Optimizations
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%DOCSDIR%%|${DOCSDIR}|g' ${WRKSRC}/src/dmhelpmanager.pas
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' -e 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/src/uGlobsPaths.pas
	@${REINPLACE_CMD} -e 's|.GetSize|.Size|g' ${WRKSRC}/src/platform/uClipboard.pas

do-build:
	@cd ${WRKSRC}/components && \
		${FIND} * -name *.lpk -exec ${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "{}" \;
	@cd ${WRKSRC} && \
		${LAZBUILD_CMD} --ws=${LCL_PLATFORM} --bm="${BUILD_MODE}" --lazarusdir=${LAZARUS_DIR} ${PROJECT_FILE}

post-build:
	@${RM} -rf ${DOCSRC}/*/dev-help

pre-install:
	@${RM} -f ${PLIST}

.for FILE in %%DATADIR%%/doublecmd.ext.example \
	%%DATADIR%%/editor.col %%DATADIR%%/twilight.col %%DATADIR%%/pixmaps.txt \
	%%DATADIR%%/default.bar %%DATADIR%%/multiarc.ini bin/doublecmd \
	share/applications/doublecmd.desktop
	@${ECHO_CMD} ${FILE} >> ${PLIST}
.endfor

	@cd ${WRKSRC}/language && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/language/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/language/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/language" >> ${PLIST}

	@cd ${WRKSRC}/pixmaps && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/pixmaps/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/pixmaps/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/pixmaps" >> ${PLIST}

	@cd ${WRKSRC}/sdk && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/sdk/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/sdk/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/sdk" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%" >> ${PLIST}

.if ${PORT_OPTIONS:MDOCS}
	@cd ${DOCSRC} && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DOCSDIR%%/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DOCSDIR%%/|' >> ${PLIST}
	@${ECHO} "@dirrm %%DOCSDIR%%" >> ${PLIST}
.endif

	@${ECHO_CMD} "@exec %%LOCALBASE%%/bin/update-desktop-database > /dev/null || /usr/bin/true" >> ${PLIST}
	@${ECHO_CMD} "@unexec %%LOCALBASE%%/bin/update-desktop-database > /dev/null || /usr/bin/true" >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry share/applications" >> ${PLIST}

do-install:
.for DIRE in language pixmaps sdk
	@${MKDIR} ${DATADIR}/${DIRE}
	@cd ${WRKSRC}/${DIRE} && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/${DIRE}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/${DIRE}/{}" \;
.endfor

.if ${PORT_OPTIONS:MDOCS}
	@cd ${DOCSRC} && \
		${FIND} * -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
.endif

.for FILE in doublecmd.ext.example editor.col twilight.col pixmaps.txt default.bar multiarc.ini
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DATADIR}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/doublecmd ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/install/linux/${PORTNAME}.desktop ${DESKTOPDIR}/

post-install:
	-@update-desktop-database
	${INSTALL_MAN} ${WRKSRC}/install/linux/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
