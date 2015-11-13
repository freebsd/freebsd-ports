# Created by: Beñat Gonzalez Etxepare <bbtruk@users.sourceforge.net>
# $FreeBSD$

PORTNAME=	doublecmd
PORTVERSION=	0.6.6
CATEGORIES=	x11-fm
MASTER_SITES=	SF/${PORTNAME}/Double%20Commander%20Source
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}.tar.gz ${PORTNAME}-help-${HELPVERSION}-src.tar.gz

MAINTAINER=	bbtruk@users.sourceforge.net
COMMENT=	Total Commander like file manager for the X Window System

LICENSE=	GPLv2

BUILD_DEPENDS=	lazbuild:${PORTSDIR}/editors/lazarus \
		fpcres:${PORTSDIR}/lang/fpc-utils

ONLY_FOR_ARCHS=	i386 amd64

PORTDOCS=	*

USES=		dos2unix
USE_FPC=	cairo fcl-base fcl-db fcl-image fcl-json fcl-process fcl-registry \
		fcl-xml hash iconvenc pasjpeg paszlib x11
DOS2UNIX_FILES=	src/dmhelpmanager.pas
WANT_GNOME=	yes

PLIST=		${WRKDIR}/pkg-plist

PROJECT_FILE=	src/doublecmd.lpi
LAZARUS_VER=	1.4.2
LAZBUILD_CMD=	${LOCALBASE}/bin/lazbuild -d --pcp=${WRKSRC}/tmppcp
LAZARUS_DIR=	${LOCALBASE}/share/lazarus-${LAZARUS_VER}

HELPVERSION=	0.6.0
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DOCSRC=		${WRKDIR}/${PORTNAME}-help-${HELPVERSION}

OPTIONS_DEFINE=		DOCS DEBUG
OPTIONS_SINGLE=		LCL
OPTIONS_SINGLE_LCL=	GTK2 QT4
OPTIONS_GROUP=		WCX WDX WFX WLX DSX
OPTIONS_GROUP_WCX=	WCX_CPIO \
			WCX_DEB \
			WCX_RPM \
			WCX_UNBZ2 \
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

WCX_DESC=	Packer plugins to work with archives
WCX_CPIO_DESC=	CPIO format support
WCX_DEB_DESC=	Debian package archive support
WCX_RPM_DESC=	Red Hat package archive support
WCX_UNBZ2_DESC=	BZIP2 format support
WCX_UNRAR_DESC=	RAR format support
WCX_ZIP_DESC=	ZIP format support

WDX_DESC=	Plugins to display and search extended file attributes
WDX_DEB_DESC=	Debian package file information
WDX_RPM_DESC=	Red Hat package file information
WDX_SCRIPTS_DESC=	Add support to use custom Lua scripts
WDX_SVN_DESC=	Subversion repository information
WDX_XPI_DESC=	Mozilla plugin file information

WFX_DESC=	File system plugins
WFX_FTP_DESC=	FTP protocol support
WFX_SAMBA_DESC=	SMB protocol support

WLX_DESC=	Internal viewer plugins
WLX_MPLAYER_DESC=	Use MPlayer for multimedia files

DSX_DESC=	Search plugins
DSX_LOCATE_DESC=	Support locate command

OPTIONS_DEFAULT=	GTK2 \
			WCX_CPIO \
			WCX_DEB \
			WCX_RPM \
			WCX_UNRAR \
			WCX_ZIP \
			WDX_RPM \
			WDX_DEB \
			WDX_SVN \
			WDX_SCRIPTS \
			WDX_XPI \
			WFX_FTP \
			WFX_SAMBA \
			DSX_LOCATE

GTK2_USE=		fpc=gtk2 gnome=gtk20
GTK2_BUILD_DEPENDS=	${LAZARUS_DIR}/lcl/units/${BUILDNAME}/${LCL_PLATFORM}/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-gtk2

QT4_USE=		fpc=yes
QT4_LIB_DEPENDS=	libQt4Pas.so:${PORTSDIR}/x11-toolkits/qt4pas
QT4_BUILD_DEPENDS=	${LAZARUS_DIR}/lcl/units/${BUILDNAME}/${LCL_PLATFORM}/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-qt

WCX_UNRAR_LIB_DEPENDS=	libunrar.so:${PORTSDIR}/archivers/libunrar
WFX_SAMBA_LIB_DEPENDS=	libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient
WLX_MPLAYER_RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
LCL_PLATFORM=	gtk2
.elif ${PORT_OPTIONS:MQT4}
LCL_PLATFORM=	qt
.endif

.if ${PORT_OPTIONS:MDEBUG}
BUILD_MODE=	Debug
.else
BUILD_MODE=	NoDebug Full Optimizations
.endif

.if ${PORT_OPTIONS:MWFX_FTP}
USE_FPC+=	fcl-net
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
	@cd ${WRKSRC}/components && ${SETENV} ${MAKE_ENV} \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "${FILE}"
.endfor

.if ${PORT_OPTIONS:MWCX_CPIO}
	@cd ${WRKSRC}/plugins && ${SETENV} ${MAKE_ENV} \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wcx/cpio/src/cpio.lpi"
.endif
.if ${PORT_OPTIONS:MWCX_DEB}
	@cd ${WRKSRC}/plugins && ${SETENV} ${MAKE_ENV} \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wcx/deb/src/deb.lpi"
.endif
.if ${PORT_OPTIONS:MWCX_UNBZ2}
	@cd ${WRKSRC}/plugins && ${SETENV} ${MAKE_ENV} \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wcx/unbz2/src/unbz2.lpi"
.endif
.if ${PORT_OPTIONS:MWCX_RPM}
	@cd ${WRKSRC}/plugins && ${SETENV} ${MAKE_ENV} \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wcx/rpm/src/rpm.lpi"
.endif
.if ${PORT_OPTIONS:MWCX_UNRAR}
	@cd ${WRKSRC}/plugins && ${SETENV} ${MAKE_ENV} \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wcx/unrar/src/unrar.lpi"
.endif
.if ${PORT_OPTIONS:MWCX_ZIP}
	@cd ${WRKSRC}/plugins && ${SETENV} ${MAKE_ENV} \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wcx/zip/src/Zip.lpi"
.endif

.if ${PORT_OPTIONS:MWDX_RPM}
	@cd ${WRKSRC}/plugins && ${SETENV} ${MAKE_ENV} \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wdx/rpm_wdx/src/rpm_wdx.lpi"
.endif
.if ${PORT_OPTIONS:MWDX_DEB}
	@cd ${WRKSRC}/plugins && ${SETENV} ${MAKE_ENV} \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wdx/deb_wdx/src/deb_wdx.lpi"
.endif
.if ${PORT_OPTIONS:MWDX_SVN}
	@cd ${WRKSRC}/plugins && ${SETENV} ${MAKE_ENV} \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wdx/svn_wdx/src/svn_wdx.lpi"
.endif
.if ${PORT_OPTIONS:MWDX_XPI}
	@cd ${WRKSRC}/plugins && ${SETENV} ${MAKE_ENV} \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wdx/xpi_wdx/src/xpi_wdx.lpi"
.endif

.if ${PORT_OPTIONS:MWFX_FTP}
	@cd ${WRKSRC}/plugins && ${SETENV} ${MAKE_ENV} \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wfx/ftp/src/ftp.lpi"
.endif
.if ${PORT_OPTIONS:MWFX_SAMBA}
	@cd ${WRKSRC}/plugins && ${SETENV} ${MAKE_ENV} \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wfx/samba/src/samba.lpi"
.endif

.if ${PORT_OPTIONS:MWLX_MPLAYER}
	@cd ${WRKSRC}/plugins && ${SETENV} ${MAKE_ENV} \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "wlx/WlxMplayer/src/wlxMplayer.lpi"
.endif

.if ${PORT_OPTIONS:MDSX_LOCATE}
	@cd ${WRKSRC}/plugins && ${SETENV} ${MAKE_ENV} \
		${LAZBUILD_CMD} --lazarusdir=${LAZARUS_DIR} --ws=${LCL_PLATFORM} "dsx/DSXLocate/src/DSXLocate.lpi"
.endif

	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LAZBUILD_CMD} --ws=${LCL_PLATFORM} --bm="${BUILD_MODE}" --lazarusdir=${LAZARUS_DIR} ${PROJECT_FILE}

post-build:
	@${RM} -rf ${DOCSRC}/*/dev-help

pre-install:
	@${RM} -f ${PLIST}

	@${ECHO_CMD} "@dir %%DATADIR%%/plugins/wcx" >> ${PLIST}
	@${ECHO_CMD} "@dir %%DATADIR%%/plugins/wdx" >> ${PLIST}
	@${ECHO_CMD} "@dir %%DATADIR%%/plugins/wfx" >> ${PLIST}
	@${ECHO_CMD} "@dir %%DATADIR%%/plugins/wlx" >> ${PLIST}
	@${ECHO_CMD} "@dir %%DATADIR%%/plugins/dsx" >> ${PLIST}

.if ${PORT_OPTIONS:MWCX_CPIO}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wcx/cpio/cpio.wcx" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWCX_DEB}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wcx/deb/deb.wcx" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWCX_RPM}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wcx/rpm/rpm.wcx" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWCX_UNBZ2}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wcx/unbz2/unbz2.wcx" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWCX_UNRAR}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wcx/unrar/unrar.wcx" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWCX_ZIP}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wcx/zip/zip.wcx" >> ${PLIST}
.endif

.if ${PORT_OPTIONS:MWDX_RPM}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wdx/rpm_wdx/rpm_wdx.wdx" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWDX_DEB}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wdx/deb_wdx/deb_wdx.wdx" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWDX_SVN}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wdx/svn_wdx/svn_wdx.wdx" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWDX_XPI}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wdx/xpi_wdx/xpi_wdx.wdx" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWDX_SCRIPTS}
	@cd ${WRKSRC}/plugins/wdx/scripts && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/plugins/wdx/scripts/|' >> ${PLIST}
.endif

.if ${PORT_OPTIONS:MWFX_FTP}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wfx/ftp/ftp.wfx" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWFX_SAMBA}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wfx/samba/samba.wfx" >> ${PLIST}
.endif

.if ${PORT_OPTIONS:MWLX_MPLAYER}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wlx/wlxmplayer/wlxmplayer.wlx" >> ${PLIST}
.endif

.if ${PORT_OPTIONS:MDSX_LOCATE}
	@${ECHO_CMD} "%%DATADIR%%/plugins/dsx/dsxlocate/dsxlocate.dsx" >> ${PLIST}
.endif

.for FILE in %%DATADIR%%/doublecmd.ext.example %%DATADIR%%/pixmaps.txt \
	%%DATADIR%%/multiarc.ini bin/doublecmd share/applications/doublecmd.desktop \
	share/pixmaps/doublecmd.png share/pixmaps/doublecmd.xpm \
	%%DATADIR%%/doublecmd.xml
	@${ECHO_CMD} ${FILE} >> ${PLIST}
.endfor

	@cd ${WRKSRC}/language && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/language/|' >> ${PLIST}

	@cd ${WRKSRC}/pixmaps && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/pixmaps/|' >> ${PLIST}

	@cd ${WRKSRC}/sdk && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/sdk/|' >> ${PLIST}

	@${ECHO_CMD} "man/man1/doublecmd.1.gz" >> ${PLIST}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wcx
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wdx
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wfx
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wlx
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/dsx
.if ${PORT_OPTIONS:MWCX_CPIO}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wcx/cpio
	${INSTALL_LIB} ${WRKSRC}/plugins/wcx/cpio/lib/cpio.wcx ${STAGEDIR}${DATADIR}/plugins/wcx/cpio/
.endif
.if ${PORT_OPTIONS:MWCX_DEB}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wcx/deb
	${INSTALL_LIB} ${WRKSRC}/plugins/wcx/deb/lib/deb.wcx ${STAGEDIR}${DATADIR}/plugins/wcx/deb/
.endif
.if ${PORT_OPTIONS:MWCX_RPM}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wcx/rpm/
	${INSTALL_LIB} ${WRKSRC}/plugins/wcx/rpm/lib/rpm.wcx ${STAGEDIR}${DATADIR}/plugins/wcx/rpm/
.endif
.if ${PORT_OPTIONS:MWCX_UNBZ2}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wcx/unbz2/
	${INSTALL_LIB} ${WRKSRC}/plugins/wcx/unbz2/lib/unbz2.wcx ${STAGEDIR}${DATADIR}/plugins/wcx/unbz2/
.endif
.if ${PORT_OPTIONS:MWCX_UNRAR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wcx/unrar/
	${INSTALL_LIB} ${WRKSRC}/plugins/wcx/unrar/lib/unrar.wcx ${STAGEDIR}${DATADIR}/plugins/wcx/unrar/
.endif
.if ${PORT_OPTIONS:MWCX_ZIP}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wcx/zip/
	${INSTALL_LIB} ${WRKSRC}/plugins/wcx/zip/lib/zip.wcx ${STAGEDIR}${DATADIR}/plugins/wcx/zip/
.endif

.if ${PORT_OPTIONS:MWDX_RPM}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wdx/rpm_wdx/
	${INSTALL_LIB} ${WRKSRC}/plugins/wdx/rpm_wdx/lib/rpm_wdx.wdx ${STAGEDIR}${DATADIR}/plugins/wdx/rpm_wdx/
.endif
.if ${PORT_OPTIONS:MWDX_DEB}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wdx/deb_wdx/
	${INSTALL_LIB} ${WRKSRC}/plugins/wdx/deb_wdx/lib/deb_wdx.wdx ${STAGEDIR}${DATADIR}/plugins/wdx/deb_wdx/
.endif
.if ${PORT_OPTIONS:MWDX_SVN}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wdx/svn_wdx/
	${INSTALL_LIB} ${WRKSRC}/plugins/wdx/svn_wdx/lib/svn_wdx.wdx ${STAGEDIR}${DATADIR}/plugins/wdx/svn_wdx/
.endif
.if ${PORT_OPTIONS:MWDX_XPI}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wdx/xpi_wdx/
	${INSTALL_LIB} ${WRKSRC}/plugins/wdx/xpi_wdx/lib/xpi_wdx.wdx ${STAGEDIR}${DATADIR}/plugins/wdx/xpi_wdx/
.endif
.if ${PORT_OPTIONS:MWDX_SCRIPTS}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wdx/scripts/
	${INSTALL_DATA} ${WRKSRC}/plugins/wdx/scripts/* ${STAGEDIR}${DATADIR}/plugins/wdx/scripts/
.endif

.if ${PORT_OPTIONS:MWFX_FTP}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wfx/ftp/
	${INSTALL_LIB} ${WRKSRC}/plugins/wfx/ftp/lib/ftp.wfx ${STAGEDIR}${DATADIR}/plugins/wfx/ftp/
.endif
.if ${PORT_OPTIONS:MWFX_SAMBA}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wfx/samba/
	${INSTALL_LIB} ${WRKSRC}/plugins/wfx/samba/lib/samba.wfx ${STAGEDIR}${DATADIR}/plugins/wfx/samba/
.endif

.if ${PORT_OPTIONS:MWLX_MPLAYER}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wlx/wlxmplayer/
	${INSTALL_LIB} ${WRKSRC}/plugins/wlx/WlxMplayer/lib/wlxmplayer.wlx ${STAGEDIR}${DATADIR}/plugins/wlx/wlxmplayer/
.endif

.if ${PORT_OPTIONS:MDSX_LOCATE}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/dsx/dsxlocate/
	${INSTALL_LIB} ${WRKSRC}/plugins/dsx/DSXLocate/lib/dsxlocate.dsx ${STAGEDIR}${DATADIR}/plugins/dsx/dsxlocate/
.endif

.for DIRE in language pixmaps sdk
	@${MKDIR} ${STAGEDIR}${DATADIR}/${DIRE}
	@cd ${WRKSRC}/${DIRE} && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${DATADIR}/${DIRE}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${STAGEDIR}${DATADIR}/${DIRE}/{}" \;
.endfor

.for FILE in doublecmd.ext.example pixmaps.txt multiarc.ini install/linux/doublecmd.xml
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DATADIR}
.endfor

.for FILE in doublecmd.png install/linux/doublecmd.xpm
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${PREFIX}/share/pixmaps/
.endfor

	${INSTALL_PROGRAM} ${WRKSRC}/doublecmd ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/install/linux/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}/
	${INSTALL_MAN} ${WRKSRC}/install/linux/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@cd ${DOCSRC} && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${DOCSDIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${STAGEDIR}${DOCSDIR}/{}" \;
.endif

.include <bsd.port.mk>
