# Created by: Beñat Gonzalez Etxepare <bbtruk@users.sourceforge.net>
# $FreeBSD$

PORTNAME=	doublecmd
PORTVERSION=	0.5.7
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}/Double%20Commander%20Source
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${PORTNAME}-${PORTVERSION}-src.tar.gz ${PORTNAME}-help-${HELPVERSION}-src.tar.gz

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

HELPVERSION=	0.5.5
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DOCSRC=		${WRKDIR}/${PORTNAME}-help-${HELPVERSION}

OPTIONS_DEFINE=		DOCS DEBUG
OPTIONS_SINGLE=		LCL
OPTIONS_SINGLE_LCL=	GTK2 QT4
OPTIONS_GROUP=		WCX WDX WFX WLX DSX
WCX_DESC=	Packer plugins
WDX_DESC=	Content plugins
WFX_DESC=	File sytem plugins
WLX_DESC=	Lister plugins
DSX_DESC=	Search plugins
OPTIONS_GROUP_WCX=	WCX_CPIO \
			WCX_DEB \
			WCX_LZMA \
			WCX_RPM \
			WCX_UNRAR \
			WCX_ZIP
OPTIONS_GROUP_WDX=	WDX_RPM \
			WDX_DEB \
			WDX_SVN \
			WDX_XPI \
			WDX_SCRIPTS
OPTIONS_GROUP_WFX=	WFX_FTP \
			WFX_SAMBA
OPTIONS_GROUP_WLX=	WLX_MPLAYER
OPTIONS_GROUP_DSX=	DSX_LOCATE

OPTIONS_DEFAULT=	GTK2 \
			WCX_CPIO \
			WCX_DEB \
			WCX_LZMA \
			WCX_RPM \
			WDX_RPM \
			WDX_DEB \
			WDX_SVN \
			WDX_SCRIPTS \
			WDX_XPI \
			DSX_LOCATE

NO_STAGE=	yes
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

.if ${PORT_OPTIONS:MWCX_UNRAR}
LIB_DEPENDS+=	unrar:${PORTSDIR}/archivers/libunrar
.endif

.if ${PORT_OPTIONS:MWFX_SAMBA}
LIB_DEPENDS+=	smbclient:${PORTSDIR}/net/samba-libsmbclient
.endif

.if ${PORT_OPTIONS:MWLX_MPLAYER}
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
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
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/plugins/wlx/WlxMplayer/src/wlxMplayer.lpr

do-build:
.for FILE in chsdet/chsdet.lpk CmdLine/cmdbox.lpk dcpcrypt/dcpcrypt.lpk \
	doublecmd/doublecmd_common.lpk KASToolBar/kascomp.lpk \
	viewer/viewerpackage.lpk gifanim/pkg_gifanim.lpk \
	ZVDateTimeCtrls/zvdatetimectrls.lpk
	@cd ${WRKSRC}/components && \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "${FILE}"
.endfor

.if ${PORT_OPTIONS:MWCX_CPIO}
	@cd ${WRKSRC}/plugins && \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wcx/cpio/src/cpio.lpi"
.endif
.if ${PORT_OPTIONS:MWCX_DEB}
	@cd ${WRKSRC}/plugins && \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wcx/deb/src/deb.lpi"
.endif
.if ${PORT_OPTIONS:MWCX_LZMA}
	@cd ${WRKSRC}/plugins && \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wcx/lzma/src/lzma.lpi"
.endif
.if ${PORT_OPTIONS:MWCX_RPM}
	@cd ${WRKSRC}/plugins && \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wcx/rpm/src/rpm.lpi"
.endif
.if ${PORT_OPTIONS:MWCX_UNRAR}
	@cd ${WRKSRC}/plugins && \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wcx/unrar/src/unrar.lpi"
.endif
.if ${PORT_OPTIONS:MWCX_ZIP}
	@cd ${WRKSRC}/plugins && \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wcx/zip/src/Zip.lpi"
.endif

.if ${PORT_OPTIONS:MWDX_RPM}
	@cd ${WRKSRC}/plugins && \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wdx/rpm_wdx/src/rpm_wdx.lpi"
.endif
.if ${PORT_OPTIONS:MWDX_DEB}
	@cd ${WRKSRC}/plugins && \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wdx/deb_wdx/src/deb_wdx.lpi"
.endif
.if ${PORT_OPTIONS:MWDX_SVN}
	@cd ${WRKSRC}/plugins && \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wdx/svn_wdx/src/svn_wdx.lpi"
.endif
.if ${PORT_OPTIONS:MWDX_XPI}
	@cd ${WRKSRC}/plugins && \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wdx/xpi_wdx/src/xpi_wdx.lpi"
.endif

.if ${PORT_OPTIONS:MWFX_FTP}
	@cd ${WRKSRC}/plugins && \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wfx/ftp/src/ftp.lpi"
.endif
.if ${PORT_OPTIONS:MWFX_SAMBA}
	@cd ${WRKSRC}/plugins && \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wfx/samba/src/samba.lpi"
.endif

.if ${PORT_OPTIONS:MWLX_MPLAYER}
	@cd ${WRKSRC}/plugins && \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wlx/WlxMplayer/src/wlxMplayer.lpi"
.endif

.if ${PORT_OPTIONS:MDSX_LOCATE}
	@cd ${WRKSRC}/plugins && \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "dsx/DSXLocate/src/DSXLocate.lpi"
.endif

	@cd ${WRKSRC} && \
		${LAZBUILD_CMD} --ws=${LCL_PLATFORM} --bm="${BUILD_MODE}" --lazarusdir=${LAZARUS_DIR} ${PROJECT_FILE}

post-build:
	@${RM} -rf ${DOCSRC}/*/dev-help

pre-install:
	@${RM} -f ${PLIST}

.if ${PORT_OPTIONS:MWCX_CPIO}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wcx/cpio/cpio.wcx" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/plugins/wcx/cpio" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWCX_DEB}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wcx/deb/deb.wcx" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/plugins/wcx/deb" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWCX_LZMA}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wcx/lzma/lzma.wcx" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/plugins/wcx/lzma" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWCX_RPM}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wcx/rpm/rpm.wcx" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/plugins/wcx/rpm" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWCX_UNRAR}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wcx/unrar/unrar.wcx" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/plugins/wcx/unrar" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWCX_ZIP}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wcx/zip/zip.wcx" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/plugins/wcx/zip" >> ${PLIST}
.endif

.if ${PORT_OPTIONS:MWDX_RPM}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wdx/rpm_wdx/rpm_wdx.wdx" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/plugins/wdx/rpm_wdx" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWDX_DEB}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wdx/deb_wdx/deb_wdx.wdx" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/plugins/wdx/deb_wdx" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWDX_SVN}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wdx/svn_wdx/svn_wdx.wdx" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/plugins/wdx/svn_wdx" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWDX_XPI}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wdx/xpi_wdx/xpi_wdx.wdx" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/plugins/wdx/xpi_wdx" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWDX_SCRIPTS}
	@cd ${WRKSRC}/plugins/wdx/scripts && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/plugins/wdx/scripts/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/plugins/wdx/scripts/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/plugins/wdx/scripts" >> ${PLIST}
.endif

.if ${PORT_OPTIONS:MWFX_FTP}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wfx/ftp/ftp.wfx" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/plugins/wfx/ftp" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWFX_SAMBA}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wfx/samba/samba.wfx" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/plugins/wfx/samba" >> ${PLIST}
.endif

.if ${PORT_OPTIONS:MWLX_MPLAYER}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wlx/wlxmplayer/wlxmplayer.wlx" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/plugins/wlx/wlxmplayer" >> ${PLIST}
.endif

.if ${PORT_OPTIONS:MDSX_LOCATE}
	@${ECHO_CMD} "%%DATADIR%%/plugins/dsx/dsxlocate/dsxlocate.dsx" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/plugins/dsx/dsxlocate" >> ${PLIST}
.endif

	@${ECHO_CMD} "@dirrm %%DATADIR%%/plugins/wcx" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/plugins/wdx" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/plugins/wfx" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/plugins/wlx" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/plugins/dsx" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/plugins" >> ${PLIST}

.for FILE in %%DATADIR%%/doublecmd.ext.example %%DATADIR%%/pixmaps.txt \
	%%DATADIR%%/multiarc.ini bin/doublecmd share/applications/doublecmd.desktop \
	share/pixmaps/doublecmd.png share/pixmaps/doublecmd.xpm \
	%%DATADIR%%/doublecmd.xml
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

do-install:
	@${MKDIR} ${DATADIR}/plugins
	@${MKDIR} ${DATADIR}/plugins/wcx
	@${MKDIR} ${DATADIR}/plugins/wdx
	@${MKDIR} ${DATADIR}/plugins/wfx
	@${MKDIR} ${DATADIR}/plugins/wlx
	@${MKDIR} ${DATADIR}/plugins/dsx
.if ${PORT_OPTIONS:MWCX_CPIO}
	@${MKDIR} ${DATADIR}/plugins/wcx/cpio
	${INSTALL_LIB} ${WRKSRC}/plugins/wcx/cpio/lib/cpio.wcx ${DATADIR}/plugins/wcx/cpio/
.endif
.if ${PORT_OPTIONS:MWCX_DEB}
	@${MKDIR} ${DATADIR}/plugins/wcx/deb
	${INSTALL_LIB} ${WRKSRC}/plugins/wcx/deb/lib/deb.wcx ${DATADIR}/plugins/wcx/deb/
.endif
.if ${PORT_OPTIONS:MWCX_LZMA}
	@${MKDIR} ${DATADIR}/plugins/wcx/lzma/
	${INSTALL_LIB} ${WRKSRC}/plugins/wcx/lzma/lib/lzma.wcx ${DATADIR}/plugins/wcx/lzma/
.endif
.if ${PORT_OPTIONS:MWCX_RPM}
	@${MKDIR} ${DATADIR}/plugins/wcx/rpm/
	${INSTALL_LIB} ${WRKSRC}/plugins/wcx/rpm/lib/rpm.wcx ${DATADIR}/plugins/wcx/rpm/
.endif
.if ${PORT_OPTIONS:MWCX_UNRAR}
	@${MKDIR} ${DATADIR}/plugins/wcx/unrar/
	${INSTALL_LIB} ${WRKSRC}/plugins/wcx/unrar/lib/unrar.wcx ${DATADIR}/plugins/wcx/unrar/
.endif
.if ${PORT_OPTIONS:MWCX_ZIP}
	@${MKDIR} ${DATADIR}/plugins/wcx/zip/
	${INSTALL_LIB} ${WRKSRC}/plugins/wcx/zip/lib/zip.wcx ${DATADIR}/plugins/wcx/zip/
.endif

.if ${PORT_OPTIONS:MWDX_RPM}
	@${MKDIR} ${DATADIR}/plugins/wdx/rpm_wdx/
	${INSTALL_LIB} ${WRKSRC}/plugins/wdx/rpm_wdx/lib/rpm_wdx.wdx ${DATADIR}/plugins/wdx/rpm_wdx/
.endif
.if ${PORT_OPTIONS:MWDX_DEB}
	@${MKDIR} ${DATADIR}/plugins/wdx/deb_wdx/
	${INSTALL_LIB} ${WRKSRC}/plugins/wdx/deb_wdx/lib/deb_wdx.wdx ${DATADIR}/plugins/wdx/deb_wdx/
.endif
.if ${PORT_OPTIONS:MWDX_SVN}
	@${MKDIR} ${DATADIR}/plugins/wdx/svn_wdx/
	${INSTALL_LIB} ${WRKSRC}/plugins/wdx/svn_wdx/lib/svn_wdx.wdx ${DATADIR}/plugins/wdx/svn_wdx/
.endif
.if ${PORT_OPTIONS:MWDX_XPI}
	@${MKDIR} ${DATADIR}/plugins/wdx/xpi_wdx/
	${INSTALL_LIB} ${WRKSRC}/plugins/wdx/xpi_wdx/lib/xpi_wdx.wdx ${DATADIR}/plugins/wdx/xpi_wdx/
.endif
.if ${PORT_OPTIONS:MWDX_SCRIPTS}
	@${MKDIR} ${DATADIR}/plugins/wdx/scripts/
	${INSTALL_DATA} ${WRKSRC}/plugins/wdx/scripts/* ${DATADIR}/plugins/wdx/scripts/
.endif

.if ${PORT_OPTIONS:MWFX_FTP}
	@${MKDIR} ${DATADIR}/plugins/wfx/ftp/
	${INSTALL_LIB} ${WRKSRC}/plugins/wfx/ftp/lib/ftp.wfx ${DATADIR}/plugins/wfx/ftp/
.endif
.if ${PORT_OPTIONS:MWFX_SAMBA}
	@${MKDIR} ${DATADIR}/plugins/wfx/samba/
	${INSTALL_LIB} ${WRKSRC}/plugins/wfx/samba/lib/samba.wfx ${DATADIR}/plugins/wfx/samba/
.endif

.if ${PORT_OPTIONS:MWLX_MPLAYER}
	@${MKDIR} ${DATADIR}/plugins/wlx/wlxmplayer/
	${INSTALL_LIB} ${WRKSRC}/plugins/wlx/WlxMplayer/lib/wlxmplayer.wlx ${DATADIR}/plugins/wlx/wlxmplayer/
.endif

.if ${PORT_OPTIONS:MDSX_LOCATE}
	@${MKDIR} ${DATADIR}/plugins/dsx/dsxlocate/
	${INSTALL_LIB} ${WRKSRC}/plugins/dsx/DSXLocate/lib/dsxlocate.dsx ${DATADIR}/plugins/dsx/dsxlocate/
.endif

.for DIRE in language pixmaps sdk
	@${MKDIR} ${DATADIR}/${DIRE}
	@cd ${WRKSRC}/${DIRE} && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/${DIRE}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/${DIRE}/{}" \;
.endfor

.for FILE in doublecmd.ext.example pixmaps.txt multiarc.ini install/linux/doublecmd.xml
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DATADIR}
.endfor

.for FILE in doublecmd.png install/linux/doublecmd.xpm
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/share/pixmaps/
.endfor

	${INSTALL_PROGRAM} ${WRKSRC}/doublecmd ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/install/linux/${PORTNAME}.desktop ${DESKTOPDIR}/
	${INSTALL_MAN} ${WRKSRC}/install/linux/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@cd ${DOCSRC} && \
		${FIND} * -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
