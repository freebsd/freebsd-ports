# Created by: Beñat Gonzalez Etxepare <bbtruk@users.sourceforge.net>
# $FreeBSD$

PORTNAME=	doublecmd
PORTVERSION=	0.5.5
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}/Double%20Commander%20Source
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${PORTNAME}-${PORTVERSION}-src.tar.gz ${PORTNAME}-help-${PORTVERSION}-src.tar.gz

MAINTAINER=	bbtruk@users.sourceforge.net
COMMENT=	Total Commander like file manager for the X Window System

LICENSE=	GPLv2

BUILD_DEPENDS=	lazbuild:${PORTSDIR}/editors/lazarus \
		fpcres:${PORTSDIR}/lang/fpc-utils

ONLY_FOR_ARCHS=	i386 amd64

MAN1=		${PORTNAME}.1
PORTDOCS=	*

USE_DOS2UNIX=	src/dmhelpmanager.pas
USE_FPC=	yes
WANT_GNOME=	yes

PLIST=		${WRKDIR}/pkg-plist
SUB_FILES=	pkg-message

PROJECT_FILE=	src/doublecmd.lpi
LAZBUILD_CMD=	${LOCALBASE}/bin/lazbuild -d
LAZARUS_DIR=	${LOCALBASE}/share/lazarus

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DOCSRC=		${WRKDIR}/${PORTNAME}-help-${PORTVERSION}

OPTIONS_DEFINE=		DOCS DEBUG
OPTIONS_SINGLE=		LCL
OPTIONS_SINGLE_LCL=	GTK2 QT4

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

pre-patch:
	${TR} '\r' '\n' < ${WRKSRC}/src/uGlobsPaths.pas > ${WRKSRC}/src/uGlobsPaths.pas.unix
	${MV} ${WRKSRC}/src/uGlobsPaths.pas.unix ${WRKSRC}/src/uGlobsPaths.pas

post-patch:
	@${REINPLACE_CMD} -e 's|%%DOCSDIR%%|${DOCSDIR}|g' -e 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/src/uGlobsPaths.pas

do-build:
.for FILE in chsdet/chsdet.lpk CmdLine/cmdbox.lpk dcpcrypt/dcpcrypt.lpk \
	doublecmd/doublecmd_common.lpk KASToolBar/kascomp.lpk \
	viewer/viewerpackage.lpk gifanim/pkg_gifanim.lpk \
	ZVDateTimeCtrls/zvdatetimectrls.lpk
	@cd ${WRKSRC}/components && \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "${FILE}"
.endfor

	@cd ${WRKSRC} && \
		${LAZBUILD_CMD} --ws=${LCL_PLATFORM} --bm="${BUILD_MODE}" --lazarusdir=${LAZARUS_DIR} ${PROJECT_FILE}

post-build:
	@${RM} -rf ${DOCSRC}/*/dev-help

pre-install:
	@${RM} -f ${PLIST}

.for FILE in %%DATADIR%%/doublecmd.ext.example %%DATADIR%%/pixmaps.txt \
	%%DATADIR%%/multiarc.ini bin/doublecmd share/applications/doublecmd.desktop \
	share/pixmaps/doublecmd.png share/pixmaps/doublecmd.xpm
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

	@${ECHO_CMD} "@dirrmtry share/pixmaps" >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry share/applications" >> ${PLIST}

do-install:
.for DIRE in language pixmaps sdk
	@${MKDIR} ${DATADIR}/${DIRE}
	@cd ${WRKSRC}/${DIRE} && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/${DIRE}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/${DIRE}/{}" \;
.endfor

.for FILE in doublecmd.ext.example pixmaps.txt multiarc.ini
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DATADIR}
.endfor

	@${MKDIR} ${PREFIX}/share/pixmaps
.for FILE in doublecmd.png install/linux/doublecmd.xpm
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/share/pixmaps/
.endfor

	${INSTALL_PROGRAM} ${WRKSRC}/doublecmd ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/install/linux/${PORTNAME}.desktop ${DESKTOPDIR}/

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@cd ${DOCSRC} && \
		${FIND} * -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
	${INSTALL_MAN} ${WRKSRC}/install/linux/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
