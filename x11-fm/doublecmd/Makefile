PORTNAME=	doublecmd
PORTVERSION=	1.1.28
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-fm
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Total Commander like file manager for the X Window System
WWW=		https://doublecmd.sourceforge.io

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	i386 amd64 aarch64

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt5 ${PORTNAME}-qt6
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt5

USES=		desktop-file-utils dos2unix fpc gnome lazarus:flavors xorg
DOS2UNIX_FILES=	components/multithreadprocs/mtpcpu.pas src/dmhelpmanager.pas
USE_GITHUB=	yes
GH_PROJECT=	doublecmd.github.io:help
GH_TAGNAME=	${DISTVERSIONPREFIX}${DCHELP}:help
USE_GNOME=	cairo glib20
USE_XORG=	x11
USE_BINUTILS=	yes

DCHELP=		1.1.26

LAZARUS_PROJECT_FILES=	components/chsdet/chsdet.lpk \
			components/multithreadprocs/multithreadprocslaz.lpk \
			components/kascrypt/kascrypt.lpk \
			components/doublecmd/doublecmd_common.lpk \
			components/Image32/Image32.lpk \
			components/KASToolBar/kascomp.lpk \
			components/viewer/viewerpackage.lpk \
			components/gifanim/pkg_gifanim.lpk \
			components/synunihighlighter/synuni.lpk \
			components/virtualterminal/virtualterminal.lpk
LAZBUILD_ARGS=		--pcp=${WRKSRC}/tmppcp -d
LAZARUS_NO_FLAVORS=	gtk3

MAKE_ENV+=	LDVER=ld.bfd # for DragonFly
#MAKE_ENV+=	CPU_TARGET=x86_64

PLIST=		${WRKDIR}/pkg-plist
PORTDOCS=	*

OPTIONS_DEFINE=		DEBUG DOCS
OPTIONS_DEFAULT=	DSX_LOCATE WCX_BASE64 WCX_CPIO WCX_DEB WCX_RPM WCX_UNRAR \
			WCX_ZIP WDX_AUDIOINFO WDX_DEB WDX_RPM WDX_SCRIPTS \
			WDX_TEXTLINE WFX_FTP WFX_SAMBA

OPTIONS_GROUP=		DSX WCX WDX WFX WLX
OPTIONS_GROUP_DSX=	DSX_LOCATE
OPTIONS_GROUP_WCX=	WCX_BASE64 WCX_CPIO WCX_DEB WCX_RPM WCX_SEVENZIP \
			WCX_TORRENT WCX_UNRAR WCX_ZIP
OPTIONS_GROUP_WDX=	WDX_AUDIOINFO WDX_DEB WDX_RPM WDX_SCRIPTS WDX_TEXTLINE
OPTIONS_GROUP_WFX=	WFX_FTP WFX_SAMBA
OPTIONS_GROUP_WLX=	WLX_MPLAYER

DSX_DESC=		Search plugins
DSX_LOCATE_DESC=	Support locate command

WCX_BASE64_DESC=	BASE64 plugin support
WCX_CPIO_DESC=	CPIO format support
WCX_DEB_DESC=	Debian package archive support
WCX_DESC=	Packer plugins to work with archives
WCX_RPM_DESC=	Red Hat package archive support
WCX_SEVENZIP_DESC=	7z format support (broken yet)
WCX_TORRENT_DESC=	BitTorrent format support
WCX_UNRAR_DESC=	RAR format support
WCX_ZIP_DESC=	ZIP format support

WDX_AUDIOINFO_DESC=	Information about audio files
WDX_DEB_DESC=		Debian package file information
WDX_DESC=		Plugins to display and search extended file attributes
WDX_RPM_DESC=		Red Hat package file information
WDX_SCRIPTS_DESC=	Add support to use custom Lua scripts
WDX_TEXTLINE_DESC=	Show and replace single lines in text files

WFX_DESC=	File system plugins
WFX_FTP_DESC=	FTP protocol support
WFX_SAMBA_DESC=	SMB protocol support

WLX_DESC=		Internal viewer plugins
WLX_MPLAYER_DESC=	Use MPlayer for multimedia files

WCX_UNRAR_LIB_DEPENDS=		libunrar.so:archivers/libunrar
WFX_SAMBA_USES=			samba:lib
WLX_MPLAYER_RUN_DEPENDS=	mplayer:multimedia/mplayer

WCX_SEVENZIP_BROKEN=		Not ready yet to use, require unit JwaWinBase

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
LAZBUILD_ARGS+=	--bm="Debug"
.endif

.if ${PORT_OPTIONS:MWFX_FTP}
LAZARUS_PROJECT_FILES+=	plugins/wfx/ftp/src/ftp.lpi
.endif

.if ${PORT_OPTIONS:MWCX_BASE64}
LAZARUS_PROJECT_FILES+=	plugins/wcx/base64/src/base64wcx.lpi
.endif

.if ${PORT_OPTIONS:MWCX_CPIO}
LAZARUS_PROJECT_FILES+=	plugins/wcx/cpio/src/cpio.lpi
.endif

.if ${PORT_OPTIONS:MWCX_DEB}
LAZARUS_PROJECT_FILES+=	plugins/wcx/deb/src/deb.lpi
.endif

.if ${PORT_OPTIONS:MWCX_RPM}
LAZARUS_PROJECT_FILES+=	plugins/wcx/rpm/src/rpm.lpi
.endif

.if ${PORT_OPTIONS:MWCX_SEVENZIP}
LAZARUS_PROJECT_FILES+=	plugins/wcx/sevenzip/src/SevenZipWcx.lpi
.endif

.if ${PORT_OPTIONS:MWCX_TORRENT}
LAZARUS_PROJECT_FILES+=	plugins/wcx/torrent/src/torrent.lpi
.endif

.if ${PORT_OPTIONS:MWCX_UNRAR}
LAZARUS_PROJECT_FILES+=	plugins/wcx/unrar/src/unrar.lpi
.endif

.if ${PORT_OPTIONS:MWCX_ZIP}
LAZARUS_PROJECT_FILES+=	plugins/wcx/zip/src/Zip.lpi
.endif

.if ${PORT_OPTIONS:MWDX_AUDIOINFO}
LAZARUS_PROJECT_FILES+=	plugins/wdx/audioinfo/src/AudioInfo.lpi
.endif

.if ${PORT_OPTIONS:MWDX_RPM}
LAZARUS_PROJECT_FILES+=	plugins/wdx/rpm_wdx/src/rpm_wdx.lpi
.endif

.if ${PORT_OPTIONS:MWDX_DEB}
LAZARUS_PROJECT_FILES+=	plugins/wdx/deb_wdx/src/deb_wdx.lpi
.endif

.if ${PORT_OPTIONS:MWDX_TEXTLINE}
LAZARUS_PROJECT_FILES+=	plugins/wdx/textline/src/TextLine.lpi
.endif

.if ${PORT_OPTIONS:MWFX_SAMBA}
LAZARUS_PROJECT_FILES+=	plugins/wfx/samba/src/samba.lpi
.endif

.if ${PORT_OPTIONS:MWLX_MPLAYER}
LAZARUS_PROJECT_FILES+=	plugins/wlx/WlxMplayer/src/wlxMplayer.lpi
.endif

.if ${PORT_OPTIONS:MDSX_LOCATE}
LAZARUS_PROJECT_FILES+=	plugins/dsx/DSXLocate/src/DSXLocate.lpi
.endif

LAZARUS_PROJECT_FILES+=	src/doublecmd.lpi

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

.if ${PORT_OPTIONS:MWCX_BASE64}
	@${ECHO_CMD} "%%DATADIR%%/plugins/wcx/base64/base64.wcx" >> ${PLIST}
.endif
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

.for FILE in %%DATADIR%%/pixmaps.txt %%DATADIR%%/multiarc.ini bin/doublecmd \
	share/applications/doublecmd.desktop share/pixmaps/doublecmd.png \
	share/icons/hicolor/scalable/apps/doublecmd.svg
	@${ECHO_CMD} ${FILE} >> ${PLIST}
.endfor

	@cd ${WRKSRC}/language && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/language/|' >> ${PLIST}

	@cd ${WRKSRC}/pixmaps && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/pixmaps/|' >> ${PLIST}

	@cd ${WRKSRC}/sdk && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/sdk/|' >> ${PLIST}

	@${ECHO_CMD} "share/man/man1/doublecmd.1.gz" >> ${PLIST}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wcx
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wdx
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wfx
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wlx
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/dsx

.if ${PORT_OPTIONS:MWCX_BASE64}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wcx/base64
	${INSTALL_LIB} ${WRKSRC}/plugins/wcx/base64/base64.wcx ${STAGEDIR}${DATADIR}/plugins/wcx/base64/
.endif
.if ${PORT_OPTIONS:MWCX_CPIO}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wcx/cpio
	${INSTALL_LIB} ${WRKSRC}/plugins/wcx/cpio/cpio.wcx ${STAGEDIR}${DATADIR}/plugins/wcx/cpio/
.endif
.if ${PORT_OPTIONS:MWCX_DEB}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wcx/deb
	${INSTALL_LIB} ${WRKSRC}/plugins/wcx/deb/deb.wcx ${STAGEDIR}${DATADIR}/plugins/wcx/deb/
.endif
.if ${PORT_OPTIONS:MWCX_RPM}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wcx/rpm/
	${INSTALL_LIB} ${WRKSRC}/plugins/wcx/rpm/rpm.wcx ${STAGEDIR}${DATADIR}/plugins/wcx/rpm/
.endif
.if ${PORT_OPTIONS:MWCX_UNBZ2}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wcx/unbz2/
	${INSTALL_LIB} ${WRKSRC}/plugins/wcx/unbz2/lib/unbz2.wcx ${STAGEDIR}${DATADIR}/plugins/wcx/unbz2/
.endif
.if ${PORT_OPTIONS:MWCX_UNRAR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wcx/unrar/
	${INSTALL_LIB} ${WRKSRC}/plugins/wcx/unrar/unrar.wcx ${STAGEDIR}${DATADIR}/plugins/wcx/unrar/
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
	${INSTALL_LIB} ${WRKSRC}/plugins/wdx/rpm_wdx/rpm_wdx.wdx ${STAGEDIR}${DATADIR}/plugins/wdx/rpm_wdx/
.endif
.if ${PORT_OPTIONS:MWDX_DEB}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wdx/deb_wdx/
	${INSTALL_LIB} ${WRKSRC}/plugins/wdx/deb_wdx/deb_wdx.wdx ${STAGEDIR}${DATADIR}/plugins/wdx/deb_wdx/
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
	${INSTALL_LIB} ${WRKSRC}/plugins/wfx/samba/samba.wfx ${STAGEDIR}${DATADIR}/plugins/wfx/samba/
.endif

.if ${PORT_OPTIONS:MWLX_MPLAYER}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/wlx/wlxmplayer/
	${INSTALL_LIB} ${WRKSRC}/plugins/wlx/WlxMplayer/wlxmplayer.wlx ${STAGEDIR}${DATADIR}/plugins/wlx/wlxmplayer/
.endif

.if ${PORT_OPTIONS:MDSX_LOCATE}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/dsx/dsxlocate/
	${INSTALL_LIB} ${WRKSRC}/plugins/dsx/DSXLocate/dsxlocate.dsx ${STAGEDIR}${DATADIR}/plugins/dsx/dsxlocate/
.endif

.for DIRE in language pixmaps sdk
	@${MKDIR} ${STAGEDIR}${DATADIR}/${DIRE}
	@cd ${WRKSRC}/${DIRE} && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${DATADIR}/${DIRE}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} {} "${STAGEDIR}${DATADIR}/${DIRE}/{}" \;
.endfor

.for FILE in default/pixmaps.txt default/multiarc.ini
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DATADIR}
.endfor

	${INSTALL_DATA} ${WRKSRC}/doublecmd.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/pixmaps/mainicon/alt/dcfinal.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/doublecmd.svg

	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/install/linux/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}/
	${INSTALL_MAN} ${WRKSRC}/install/linux/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1/

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC_help} && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${DOCSDIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} {} "${STAGEDIR}${DOCSDIR}/{}" \;
.endif

.include <bsd.port.mk>
