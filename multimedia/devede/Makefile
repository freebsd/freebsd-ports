# New ports collection makefile for:	devede
# Date created:		2007-06-20
# Whom:			Lars Engels <lars.engels@0x20.net>
#
# $FreeBSD$
#

PORTNAME=	devede
DISTVERSION=	3.15.2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.rastersoft.com/descargas/ \
		http://www.bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Create video DVDs, VCDs, sVCDs or CVDs from any number of video files

RUN_DEPENDS=	mencoder:${PORTSDIR}/multimedia/mencoder \
		spumux:${PORTSDIR}/multimedia/dvdauthor \
		vcdimager:${PORTSDIR}/multimedia/vcdimager

USE_BZIP2=	yes
USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_CDRTOOLS=	yes
NO_BUILD=	yes

OPTIONS=	PSYCO "Enable devel/py-psyco optimization support" off

# Strip last character not present in distribution.
WRKSRC=		${WRKDIR}/${DISTNAME:C/b//}

DEJAVU_FONTSDIR=	${LOCALBASE}/lib/X11/fonts/dejavu
DEJAVU_FONTFILE=	${DEJAVU_FONTSDIR}/DejaVuSans.ttf

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
.undef WITH_PSYCO

WITHOUT_PSYCO=	yes
.endif

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

PORTDOCS=	docs/*

DEVEDE_INTERFACE=	aboutdialog1.ui add_subtitle.ui add_subtitle2.ui \
			codepages.lst languages.lst waborted_dialog.ui \
			wcancel_dialog.ui wcancel_job_dialog.ui wdel_chapter_dialog.ui \
			wdel_subtitle.ui wdel_title_dialog.ui wdisk_type.ui \
			wempty_titles_dialog.ui wend_dialog.ui werase_dialog.ui \
			werror_dialog.ui wfile.ui wfolder_dialog.ui \
			wfolder_exists.ui wloadconfig.ui wloosecurrent.ui \
			wmain.ui wmenu_preview_ntsc.ui wmenu_preview_pal.ui \
			wmenu_properties.ui wnofonts.ui wpreview_dialog.ui \
			wpreviewagain_dialog.ui wprograms.ui wprogress.ui \
			wsaveconfig.ui wtitle_properties_dialog.ui wwarning_dialog.ui
DEVEDE_LIBS=	devede_bincue.py devede_convert.py devede_delete.py \
		devede_dialogs.py devede_disctype.py devede_dvd.py \
		devede_dvdmenu.py devede_executor.py devede_fonts.py \
		devede_help.py devede_loadsave.py devede_main.py \
		devede_newfiles.py devede_other.py devede_subtitles.py \
		devede_title_properties.py devede_video_convert.py \
		devede_xml_menu.py
DEVEDE_PIXMAPS=	background.png barras.png base_ntsc.mpg base_ntsc_wide.mpg \
		base_pal.mpg base_pal_wide.mpg estira.png icon_cvd.png \
		icon_divx.png icon_dvd.png icon_svcd.png icon_vcd.png silence.ogg
DEVEDE_BACKGROUNDS=	biglens.png default_bg.png dvdfilm.png

.if defined(WITH_PSYCO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco
EXTRA_PATCHES+=	${FILESDIR}/extra-psyco-patch-devede.py
.endif

post-patch:
# Fix general locations
	@${REINPLACE_CMD} -E \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%PORTNAME%%|${PORTNAME}|' \
		-e 's|%%DATADIR%%|${DATADIR}|' \
		-e 's|%%DOCSDIR%%|${DOCSDIR}|' \
		${WRKSRC}/devede.py
# Fix font location
	@${REINPLACE_CMD} -E \
		-e 's,/usr/share/fonts/truetype/ttf-dejavu/(DejaVuSans|dejavusans).ttf,${DEJAVU_FONTFILE},g' \
		${WRKSRC}/devede_fonts.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/devede.py ${PREFIX}/bin/devede
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}/backgrounds
	${INSTALL_DATA} ${WRKSRC}/devede.svg ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/devedesans.ttf ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/changes.txt ${DATADIR}
.for pixmap in ${DEVEDE_PIXMAPS}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/${pixmap} ${DATADIR}
.endfor
.for background in ${DEVEDE_BACKGROUNDS}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/backgrounds/${background} ${DATADIR}/backgrounds
.endfor
.for interface in ${DEVEDE_INTERFACE}
	${INSTALL_DATA} ${WRKSRC}/interface/${interface} ${DATADIR}
.endfor
	@${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/devede.desktop ${DESKTOPDIR}
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}
.for lib in ${DEVEDE_LIBS}
	${INSTALL_SCRIPT} ${WRKSRC}/${lib} ${PREFIX}/lib/${PORTNAME}
.endfor
.if !defined(WITHOUT_NLS)
	${INSTALL_DATA} ${WRKSRC}/po/ca.mo ${PREFIX}/share/locale/ca/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/cs_CZ.mo ${PREFIX}/share/locale/cs/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/da.mo ${PREFIX}/share/locale/da/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/de_DE.mo ${PREFIX}/share/locale/de/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/el.mo ${PREFIX}/share/locale/el/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/es.mo ${PREFIX}/share/locale/es/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/fr.mo ${PREFIX}/share/locale/fr/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/gl.mo ${PREFIX}/share/locale/gl/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/it_IT.mo ${PREFIX}/share/locale/it/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/nb_NO.mo ${PREFIX}/share/locale/nb/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/nl.mo ${PREFIX}/share/locale/nl/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/pl.mo ${PREFIX}/share/locale/pl/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/pt_BR.mo ${PREFIX}/share/locale/pt_BR/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/pt_PT.mo ${PREFIX}/share/locale/pt_PT/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/ru.mo ${PREFIX}/share/locale/ru/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/sk.mo ${PREFIX}/share/locale/sk/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/sv.mo ${PREFIX}/share/locale/sv/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/zh_CN.mo ${PREFIX}/share/locale/zh_CN/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/zh_TW.mo ${PREFIX}/share/locale/zh_TW/LC_MESSAGES/devede.mo
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/docs/html/* ${DOCSDIR}/html
.endif

.include <bsd.port.post.mk>
