# Created by: Beñat Gonzalez Etxepare <bbtruk@users.sourceforge.net>
# $FreeBSD$

PORTNAME=	doublecmd
PORTVERSION=	0.9.7
CATEGORIES=	x11-fm
MASTER_SITES=	SF/${PORTNAME}/Double%20Commander%20Source
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}.tar.gz ${PORTNAME}-help-${HELPVERSION}-src.tar.gz

MAINTAINER=	bbtruk@users.sourceforge.net
COMMENT=	Total Commander like file manager for the X Window System

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386

USES=		dos2unix desktop-file-utils fpc gnome lazarus:flavors xorg

PORTDOCS=	*

USE_FPC=	cairo chm fcl-base fcl-db fcl-image fcl-json fcl-registry \
		fcl-xml iconvenc pasjpeg rtl-extra x11 regexpr
USE_GNOME=	cairo glib20
USE_XORG=	x11
DOS2UNIX_FILES=	src/dmhelpmanager.pas

PLIST=		${WRKDIR}/pkg-plist

LAZARUS_PROJECT_FILES=	components/chsdet/chsdet.lpk
LAZARUS_PROJECT_FILES+=	components/CmdLine/cmdbox.lpk
LAZARUS_PROJECT_FILES+=	components/multithreadprocs/multithreadprocslaz.lpk
LAZARUS_PROJECT_FILES+=	components/dcpcrypt/dcpcrypt.lpk
LAZARUS_PROJECT_FILES+=	components/doublecmd/doublecmd_common.lpk
LAZARUS_PROJECT_FILES+=	components/KASToolBar/kascomp.lpk
LAZARUS_PROJECT_FILES+=	components/viewer/viewerpackage.lpk
LAZARUS_PROJECT_FILES+=	components/gifanim/pkg_gifanim.lpk
LAZARUS_PROJECT_FILES+=	components/synunihighlighter/synuni.lpk

LAZBUILD_ARGS=	-d --pcp=${WRKSRC}/tmppcp
MAKE_ENV+=	LDVER=ld.bfd # for DragonFly

HELPVERSION=	0.6.0
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DOCSRC=		${WRKDIR}/${PORTNAME}-help-${HELPVERSION}

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt5
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2

OPTIONS_DEFINE=		DOCS DEBUG
OPTIONS_GROUP=		WCX WDX WFX WLX DSX
OPTIONS_GROUP_WCX=	WCX_CPIO \
			WCX_DEB \
			WCX_RPM \
			WCX_UNBZ2 \
			WCX_UNRAR \
			WCX_ZIP
OPTIONS_GROUP_WDX=	WDX_AUDIOINFO \
			WDX_RPM \
			WDX_DEB \
			WDX_XPI \
			WDX_SCRIPTS \
			WDX_TEXTLINE
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
WDX_AUDIOINFO_DESC=	Information about audio files
WDX_DEB_DESC=	Debian package file information
WDX_RPM_DESC=	Red Hat package file information
WDX_SCRIPTS_DESC=	Add support to use custom Lua scripts
WDX_XPI_DESC=	Mozilla plugin file information
WDX_TEXTLINE_DESC=	Show and replace single lines in text files

WFX_DESC=	File system plugins
WFX_FTP_DESC=	FTP protocol support
WFX_SAMBA_DESC=	SMB protocol support

WLX_DESC=	Internal viewer plugins
WLX_MPLAYER_DESC=	Use MPlayer for multimedia files

DSX_DESC=	Search plugins
DSX_LOCATE_DESC=	Support locate command

OPTIONS_DEFAULT=	WCX_CPIO \
			WCX_DEB \
			WCX_RPM \
			WCX_UNRAR \
			WCX_ZIP \
			WDX_AUDIOINFO \
			WDX_RPM \
			WDX_DEB \
			WDX_SCRIPTS \
			WDX_TEXTLINE \
			WDX_XPI \
			WFX_FTP \
			WFX_SAMBA \
			DSX_LOCATE

WCX_UNRAR_LIB_DEPENDS=	libunrar.so.5:archivers/libunrar5
WFX_SAMBA_USES=		samba:lib
WLX_MPLAYER_RUN_DEPENDS=	mplayer:multimedia/mplayer

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
LAZBUILD_ARGS+=	--bm="Debug"
.endif

.if ${PORT_OPTIONS:MWFX_FTP}
USE_FPC+=	fcl-net
LAZARUS_PROJECT_FILES+=		plugins/wfx/ftp/src/ftp.lpi
.endif

.if ${PORT_OPTIONS:MWCX_CPIO}
LAZARUS_PROJECT_FILES+=		plugins/wcx/cpio/src/cpio.lpi
.endif

.if ${PORT_OPTIONS:MWCX_DEB}
LAZARUS_PROJECT_FILES+=		plugins/wcx/deb/src/deb.lpi
.endif

.if ${PORT_OPTIONS:MWCX_UNBZ2}
LAZARUS_PROJECT_FILES+=		plugins/wcx/unbz2/src/unbz2.lpi
.endif

.if ${PORT_OPTIONS:MWCX_RPM}
LAZARUS_PROJECT_FILES+=		plugins/wcx/rpm/src/rpm.lpi
.endif

.if ${PORT_OPTIONS:MWCX_UNRAR}
LAZARUS_PROJECT_FILES+=		plugins/wcx/unrar/src/unrar.lpi
.endif

.if ${PORT_OPTIONS:MWCX_ZIP}
LAZARUS_PROJECT_FILES+=		plugins/wcx/zip/src/Zip.lpi
.endif

.if ${PORT_OPTIONS:MWDX_AUDIOINFO}
LAZARUS_PROJECT_FILES+=		plugins/wdx/audioinfo/src/AudioInfo.lpi
.endif

.if ${PORT_OPTIONS:MWDX_RPM}
LAZARUS_PROJECT_FILES+=		plugins/wdx/rpm_wdx/src/rpm_wdx.lpi
.endif

.if ${PORT_OPTIONS:MWDX_DEB}
LAZARUS_PROJECT_FILES+=		plugins/wdx/deb_wdx/src/deb_wdx.lpi
.endif

.if ${PORT_OPTIONS:MWDX_XPI}
LAZARUS_PROJECT_FILES+=		plugins/wdx/xpi_wdx/src/xpi_wdx.lpi
.endif

.if ${PORT_OPTIONS:MWDX_TEXTLINE}
LAZARUS_PROJECT_FILES+=		plugins/wdx/textline/src/TextLine.lpi
.endif

.if ${PORT_OPTIONS:MWFX_SAMBA}
LAZARUS_PROJECT_FILES+=		plugins/wfx/samba/src/samba.lpi
.endif

.if ${PORT_OPTIONS:MWLX_MPLAYER}
LAZARUS_PROJECT_FILES+=		plugins/wlx/WlxMplayer/src/wlxMplayer.lpi
.endif

.if ${PORT_OPTIONS:MDSX_LOCATE}
LAZARUS_PROJECT_FILES+=		plugins/dsx/DSXLocate/src/DSXLocate.lpi
.endif

LAZARUS_PROJECT_FILES+=		src/doublecmd.lpi

pre-patch:
	${TR} '\r' '\n' < ${WRKSRC}/src/uGlobsPaths.pas > ${WRKSRC}/src/uGlobsPaths.pas.unix
	${MV} ${WRKSRC}/src/uGlobsPaths.pas.unix ${WRKSRC}/src/uGlobsPaths.pas

post-patch:
	@${REINPLACE_CMD} -e 's|%%DOCSDIR%%|${DOCSDIR}|g' -e 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/src/uGlobsPaths.pas
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/plugins/wlx/WlxMplayer/src/wlxMplayer.lpr
	@${REINPLACE_CMD} -e 's| Default="True"||g' \
		-e 's|Name="NoDebug Full Optimizations"|Name="NoDebug Full Optimizations" Default="True"|g' \
			${WRKSRC}/src/${PORTNAME}.lpi

post-build:
	@${RM} -r ${DOCSRC}/*/dev-help

pre-install:
	@${RM} ${PLIST}

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

.if ${PORT_OPTIONS:MWDX_AUDIOINFO}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wdx/audioinfo/audioinfo.wdx" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWDX_RPM}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wdx/rpm_wdx/rpm_wdx.wdx" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWDX_DEB}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wdx/deb_wdx/deb_wdx.wdx" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWDX_XPI}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wdx/xpi_wdx/xpi_wdx.wdx" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWDX_SCRIPTS}
	@cd ${WRKSRC}/plugins/wdx/scripts && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/plugins/wdx/scripts/|' >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MWDX_TEXTLINE}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wdx/textline/textline.wdx" >> ${PLIST}
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
	share/pixmaps/doublecmd.png share/icons/hicolor/scalable/apps/doublecmd.svg
	@${ECHO_CMD} ${FILE} >> ${PLIST}
.endfor

	@cd ${WRKSRC}/language && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/language/|' >> ${PLIST}

	@cd ${WRKSRC}/pixmaps && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/pixmaps/|' >> ${PLIST}
	@${ECHO_CMD} "@dir %%DATADIR%%/pixmaps/dctheme/20x20/apps" >> ${PLIST}

	@cd ${WRKSRC}/sdk && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/sdk/|' >> ${PLIST}

	@${ECHO_CMD} "man/man1/doublecmd.1.gz" >> ${PLIST}

do-install:
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
	${INSTALL_LIB} ${WRKSRC}/plugins/wcx/zip/zip.wcx ${STAGEDIR}${DATADIR}/plugins/wcx/zip/
.endif

.if ${PORT_OPTIONS:MWDX_AUDIOINFO}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wdx/audioinfo/
	${INSTALL_LIB} ${WRKSRC}/plugins/wdx/audioinfo/audioinfo.wdx ${STAGEDIR}${DATADIR}/plugins/wdx/audioinfo/
.endif
.if ${PORT_OPTIONS:MWDX_RPM}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wdx/rpm_wdx/
	${INSTALL_LIB} ${WRKSRC}/plugins/wdx/rpm_wdx/lib/rpm_wdx.wdx ${STAGEDIR}${DATADIR}/plugins/wdx/rpm_wdx/
.endif
.if ${PORT_OPTIONS:MWDX_DEB}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wdx/deb_wdx/
	${INSTALL_LIB} ${WRKSRC}/plugins/wdx/deb_wdx/lib/deb_wdx.wdx ${STAGEDIR}${DATADIR}/plugins/wdx/deb_wdx/
.endif
.if ${PORT_OPTIONS:MWDX_XPI}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wdx/xpi_wdx/
	${INSTALL_LIB} ${WRKSRC}/plugins/wdx/xpi_wdx/lib/xpi_wdx.wdx ${STAGEDIR}${DATADIR}/plugins/wdx/xpi_wdx/
.endif
.if ${PORT_OPTIONS:MWDX_SCRIPTS}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wdx/scripts/
	${INSTALL_DATA} ${WRKSRC}/plugins/wdx/scripts/* ${STAGEDIR}${DATADIR}/plugins/wdx/scripts/
.endif
.if ${PORT_OPTIONS:MWDX_TEXTLINE}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wdx/textline/
	${INSTALL_LIB} ${WRKSRC}/plugins/wdx/textline/textline.wdx ${STAGEDIR}${DATADIR}/plugins/wdx/textline/
.endif

.if ${PORT_OPTIONS:MWFX_FTP}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wfx/ftp/
	${INSTALL_LIB} ${WRKSRC}/plugins/wfx/ftp/ftp.wfx ${STAGEDIR}${DATADIR}/plugins/wfx/ftp/
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
			${FIND} * -type f -exec ${INSTALL_DATA} {} "${STAGEDIR}${DATADIR}/${DIRE}/{}" \;
.endfor

.for FILE in doublecmd.ext.example pixmaps.txt multiarc.ini
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DATADIR}
.endfor

	${INSTALL_DATA} ${WRKSRC}/doublecmd.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/pixmaps/mainicon/alt/dcfinal.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/doublecmd.svg

	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/install/linux/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}/
	${INSTALL_MAN} ${WRKSRC}/install/linux/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@cd ${DOCSRC} && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${DOCSDIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} {} "${STAGEDIR}${DOCSDIR}/{}" \;
.endif

.include <bsd.port.mk>
