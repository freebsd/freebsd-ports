# New ports collection makefile for:	mplayer gui skins
# Date created:				Sat Jan 12 10:59:45 BRST 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mplayer
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.mplayerhq.hu/MPlayer/Skin/ \
		http://ftp.lug.udel.edu/MPlayer/Skin/ \
		ftp://ftp.mplayerhq.hu/MPlayer/Skin/ \
		ftp://ftp.lug.udel.edu/MPlayer/Skin/
PKGNAMESUFFIX=	-skins
DISTFILES=	\
		${ABYSS_FILE} \
		${ALIENMIND_FILE} \
		${AVIFILE_FILE} \
		${DEFAULT_FILE} \
		${DEFAULT_SMALL_FILE} \
		${BLUEHEART_FILE} \
		${CANARY_FILE} \
		${CORELIAN_FILE} \
		${CORNERMP_FILE} \
		${CORNERMP_AQUA_FILE} \
		${CYRUS_FILE} \
		${DISAPPEARER_FILE} \
		${DUSHKU_FILE} \
		${DVDPLAYER_FILE} \
		${GNOME_FILE} \
		${HANDHELD_FILE} \
		${HAYRAPHON_FILE} \
		${HWSW_FILE} \
		${INDUSTRIAL_FILE} \
		${JIMPLAYER_FILE} \
		${KDE_FILE} \
		${KRYSTAL_FILE} \
		${MENTALIC_FILE} \
		${MIDNIGHTLOVE_FILE} \
		${MINI_FILE} \
		${NEUTRON_FILE} \
		${NEWAGE_FILE} \
		${ORANGE_FILE} \
		${OSXBRUSHED_FILE} \
		${OSXMOD_FILE} \
		${PHONY_FILE} \
		${PLASTIC_FILE} \
		${POWERPLAYER_FILE} \
		${PROTON_FILE} \
		${QPLAYER_FILE} \
		${SLIM_FILE} \
		${SOFTGRIP_FILE} \
		${TERMINATOR3_FILE} \
		${TRIUM_FILE} \
		${TVISOR_FILE} \
		${ULTRAFINA_FILE} \
		${WMP6_FILE} \
		${XANIM_FILE} \
		${XFCE4_FILE} \
		${XINE_LCD_FILE} \
		${XMMPLAYER_FILE}

DIST_SUBDIR=	mplayer

MAINTAINER=	riggs@rrr.de
COMMENT=	Skins for MPlayer's Graphical User Interface (GUI)

USE_BZIP2=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

ABYSS_FILE=		Abyss-1.1.tar.bz2 
ALIENMIND_FILE=		AlienMind-1.2.tar.bz2
AVIFILE_FILE=		avifile-1.6.tar.bz2
DEFAULT_FILE=		Blue-1.4.tar.bz2
DEFAULT_SMALL_FILE=	Blue-small-1.2.tar.bz2
BLUEHEART_FILE=		BlueHeart-1.5.tar.bz2
CANARY_FILE=		Canary-1.2.tar.bz2
CORELIAN_FILE=		Corelian-1.1.tar.bz2
CORNERMP_FILE=		CornerMP-1.2.tar.bz2
CORNERMP_AQUA_FILE=	CornerMP-aqua-1.4.tar.bz2
CYRUS_FILE=		Cyrus-1.2.tar.bz2
DISAPPEARER_FILE=	disappearer-1.1.tar.bz2
DUSHKU_FILE=		Dushku-1.2.tar.bz2
DVDPLAYER_FILE=		DVDPlayer-1.1.tar.bz2
GNOME_FILE=		gnome-1.1.tar.bz2
HANDHELD_FILE=		handheld-1.0.tar.bz2
HAYRAPHON_FILE=		hayraphon-1.0.tar.bz2
HWSW_FILE=		hwswskin-1.1.tar.bz2
INDUSTRIAL_FILE=	Industrial-1.0.tar.bz2
JIMPLAYER_FILE=		JiMPlayer-1.4.tar.bz2
KDE_FILE=		KDE-0.3.tar.bz2
KRYSTAL_FILE=		krystal-1.1.tar.bz2
MENTALIC_FILE=		mentalic-1.2.tar.bz2
MIDNIGHTLOVE_FILE=	MidnightLove-1.6.tar.bz2
MINI_FILE=		mini-0.1.tar.bz2
NEUTRON_FILE=		neutron-1.5.tar.bz2
NEWAGE_FILE=		new-age-1.0.tar.bz2
ORANGE_FILE=		Orange-1.3.tar.bz2
OSXBRUSHED_FILE=	OSX-Brushed-2.3.tar.bz2
OSXMOD_FILE=		OSX-Mod-1.1.tar.bz2
PHONY_FILE=		phony-1.1.tar.bz2
PLASTIC_FILE=		plastic-1.2.tar.bz2
POWERPLAYER_FILE=	PowerPlayer-1.1.tar.bz2
PROTON_FILE=		proton-1.2.tar.bz2
QPLAYER_FILE=		QPlayer-1.2.tar.bz2
SLIM_FILE=		slim-1.2.tar.bz2
SOFTGRIP_FILE=		softgrip-1.1.tar.bz2
TERMINATOR3_FILE=	Terminator3-1.1.tar.bz2
TRIUM_FILE=		trium-1.3.tar.bz2
TVISOR_FILE=		tvisor-1.1.tar.bz2
ULTRAFINA_FILE=		ultrafina-1.1.tar.bz2
WMP6_FILE=		WMP6-2.2.tar.bz2
XANIM_FILE=		xanim-1.6.tar.bz2
XFCE4_FILE=		XFce4-1.0.tar.bz2
XINE_LCD_FILE=		xine-lcd-1.2.tar.bz2
XMMPLAYER_FILE=		xmmplayer-1.5.tar.bz2

OPTIONS=	SKIN_ALL "all skins" off
OPTIONS+=	SKIN_DEFAULT "the defaul MPlayer skin" on
OPTIONS+=	SKIN_DEFAULT_SMALL "compact version of the default skin" off
OPTIONS+=	SKIN_ABYSS "beautiful MPlayer skin" off
OPTIONS+=	SKIN_ALIENMIND "AlienMind XMMS" off
OPTIONS+=	SKIN_AVIFILE "aviplay look" off
OPTIONS+=	SKIN_BLUEHEART "BlueHeart XMMS" off
OPTIONS+=	SKIN_CANARY "small, compact" off
OPTIONS+=	SKIN_CORELIAN "plain look" off
OPTIONS+=	SKIN_CORNERMP "WinAMP corner" off
OPTIONS+=	SKIN_CORNERMP_AQUA "WinAMP corner aqua" off
OPTIONS+=	SKIN_CYRUS "Cyrus XMMS" off
OPTIONS+=	SKIN_DISAPPEARER "very slim" off
OPTIONS+=	SKIN_DUSHKU "Eliza Dushku" off
OPTIONS+=	SKIN_DVDPLAYER "hardware player lookalike" off
OPTIONS+=	SKIN_GNOME "based on the GNOME logo" off
OPTIONS+=	SKIN_HANDHELD "remote control look" off
OPTIONS+=	SKIN_HAYRAPHON "Hayraphon" off
OPTIONS+=	SKIN_HWSW "simplistic" off
OPTIONS+=	SKIN_INDUSTRIAL "Industrial GTK theme" off
OPTIONS+=	SKIN_JIMPLAYER "round and colorful" off
OPTIONS+=	SKIN_KDE "uses KDE images" off
OPTIONS+=	SKIN_KRYSTAL "very colorful" off
OPTIONS+=	SKIN_MENTALIC "sharp and shiny" off
OPTIONS+=	SKIN_MIDNIGHTLOVE "XMMS skin of Rei Ayanami" off
OPTIONS+=	SKIN_MINI "MPlayer-plugin for mozilla" off
OPTIONS+=	SKIN_NEUTRON "futuristic look" off
OPTIONS+=	SKIN_NEWAGE "clean and simple" off
OPTIONS+=	SKIN_ORANGE "clean, good looking" off
OPTIONS+=	SKIN_OSXBRUSHED "iTunes lookalike" off
OPTIONS+=	SKIN_OSXMOD "QuickTime player lookalike" off
OPTIONS+=	SKIN_PHONY "desktop DVD player" off
OPTIONS+=	SKIN_PLASTIC "plastic remote control" off
OPTIONS+=	SKIN_POWERPLAYER "PowerDVD lookalike" off
OPTIONS+=	SKIN_PROTON "silver, shiny" off
OPTIONS+=	SKIN_QPLAYER "playful look" off
OPTIONS+=	SKIN_SLIM "small and cute" off
OPTIONS+=	SKIN_SOFTGRIP "strange design" off
OPTIONS+=	SKIN_TERMINATOR3 "inspired by Terminator 3" off
OPTIONS+=	SKIN_TRIUM "based on a mobile phone" off
OPTIONS+=	SKIN_TVISOR "simple, well-designed" off
OPTIONS+=	SKIN_ULTRAFINA "XMMS ultrafina" off
OPTIONS+=	SKIN_WINDOWSMEDIAPLAYER6 "Windows Media Player 6" off
OPTIONS+=	SKIN_XANIM "XAnim feeling" off
OPTIONS+=	SKIN_XFCE4 "default XFce4 theme" off
OPTIONS+=	SKIN_XINE_LCD "xine LCD skin" off
OPTIONS+=	SKIN_XMMPLAYER "XMMS lookalike" off

.include <bsd.port.pre.mk>

INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755

myDATADIR=	share/${PORTNAME}/Skin
# Used by other ports to detect if this is installed
DETECTION_FILE=	${LOCALBASE}/${myDATADIR}/${PKGNAME}

PLIST_SUB+=	PKGNAME="${PKGNAME}"

.if defined(BATCH)
WITH_SKIN_ALL=yes
.endif	# BATCH

# Build and install all skins (rather expensive)
.if defined(WITH_SKIN_ALL)
WITH_SKIN_DEFAULT=yes
WITH_SKIN_DEFAULT_SMALL=yes
WITH_SKIN_ABYSS=yes
WITH_SKIN_ALIENMIND=yes
WITH_SKIN_AVIFILE=yes
WITH_SKIN_BLUEHEART=yes
WITH_SKIN_CANARY=yes
WITH_SKIN_CORELIAN=yes
WITH_SKIN_CORNERMP=yes
WITH_SKIN_CORNERMP_AQUA=yes
WITH_SKIN_CYRUS=yes
WITH_SKIN_DISAPPEARER=yes
WITH_SKIN_DUSHKU=yes
WITH_SKIN_DVDPLAYER=yes
WITH_SKIN_GNOME=yes
WITH_SKIN_HANDHELD=yes
WITH_SKIN_HAYRAPHON=yes
WITH_SKIN_HWSW=yes
WITH_SKIN_INDUSTRIAL=yes
WITH_SKIN_JIMPLAYER=yes
WITH_SKIN_KDE=yes
WITH_SKIN_KRYSTAL=yes
WITH_SKIN_MENTALIC=yes
WITH_SKIN_MIDNIGHTLOVE=yes
WITH_SKIN_MINI=yes
WITH_SKIN_NEUTRON=yes
WITH_SKIN_NEWAGE=yes
WITH_SKIN_ORANGE=yes
WITH_SKIN_OSXBRUSHED=yes
WITH_SKIN_OSXMOD=yes
WITH_SKIN_PHONY=yes
WITH_SKIN_PLASTIC=yes
WITH_SKIN_POWERPLAYER=yes
WITH_SKIN_PROTON=yes
WITH_SKIN_QPLAYER=yes
WITH_SKIN_SLIM=yes
WITH_SKIN_SOFTGRIP=yes
WITH_SKIN_TERMINATOR3=yes
WITH_SKIN_TRIUM=yes
WITH_SKIN_TVISOR=yes
WITH_SKIN_ULTRAFINA=yes
WITH_SKIN_WINDOWSMEDIAPLAYER6=yes
WITH_SKIN_XANIM=yes
WITH_SKIN_XFCE4=yes
WITH_SKIN_XINE_LCD=yes
WITH_SKIN_XMMPLAYER=yes
.endif # WITH_SKIN_ALL

#
# files to extract
#
.ifdef(WITH_SKIN_DEFAULT)
EXTRACT_ONLY+=	${DEFAULT_FILE}
PLIST_SUB+=	DEFAULT=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	DEFAULT="@comment "
.endif

.ifdef(WITH_SKIN_DEFAULT_SMALL)
EXTRACT_ONLY+=	${DEFAULT_SMALL_FILE}
PLIST_SUB+=	DEFAULT_SMALL=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	DEFAULT_SMALL="@comment "
.endif

.ifdef(WITH_SKIN_ABYSS)
EXTRACT_ONLY+=	${ABYSS_FILE}
PLIST_SUB+=	ABYSS=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	ABYSS="@comment "
.endif

.ifdef(WITH_SKIN_ALIENMIND)
EXTRACT_ONLY+=	${ALIENMIND_FILE}
PLIST_SUB+=	ALIENMIND=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	ALIENMIND="@comment "
.endif

.ifdef(WITH_SKIN_AVIFILE)
EXTRACT_ONLY+=	${AVIFILE_FILE}
PLIST_SUB+=	AVIFILE=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	AVIFILE="@comment "
.endif

.ifdef(WITH_SKIN_BLUEHEART)
EXTRACT_ONLY+=	${BLUEHEART_FILE}
PLIST_SUB+=	BLUEHEART=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	BLUEHEART="@comment "
.endif

.ifdef(WITH_SKIN_CANARY)
EXTRACT_ONLY+=	${CANARY_FILE}
PLIST_SUB+=	CANARY=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	CANARY="@comment "
.endif

.ifdef(WITH_SKIN_CORELIAN)
EXTRACT_ONLY+=	${CORELIAN_FILE}
PLIST_SUB+=	CORELIAN=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	CORELIAN="@comment "
.endif

.ifdef(WITH_SKIN_CORNERMP)
EXTRACT_ONLY+=	${CORNERMP_FILE}
PLIST_SUB+=	CORNERMP=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	CORNERMP="@comment "
.endif

.ifdef(WITH_SKIN_CORNERMP_AQUA)
EXTRACT_ONLY+=	${CORNERMP_AQUA_FILE}
PLIST_SUB+=	CORNERMP_AQUA=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	CORNERMP_AQUA="@comment "
.endif

.ifdef(WITH_SKIN_CYRUS)
EXTRACT_ONLY+=	${CYRUS_FILE}
PLIST_SUB+=	CYRUS=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	CYRUS="@comment "
.endif

.ifdef(WITH_SKIN_DISAPPEARER)
EXTRACT_ONLY+=	${DISAPPEARER_FILE}
PLIST_SUB+=	DISAPPEARER=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	DISAPPEARER="@comment "
.endif

.ifdef(WITH_SKIN_DUSHKU)
EXTRACT_ONLY+=	${DUSHKU_FILE}
PLIST_SUB+=	DUSHKU=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	DUSHKU="@comment "
.endif

.ifdef(WITH_SKIN_DVDPLAYER)
EXTRACT_ONLY+=	${DVDPLAYER_FILE}
PLIST_SUB+=	DVDPLAYER=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	DVDPLAYER="@comment "
.endif

.ifdef(WITH_SKIN_GNOME)
EXTRACT_ONLY+=	${GNOME_FILE}
PLIST_SUB+=	GNOME=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	GNOME="@comment "
.endif

.ifdef(WITH_SKIN_HANDHELD)
EXTRACT_ONLY+=	${HANDHELD_FILE}
PLIST_SUB+=	HANDHELD=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	HANDHELD="@comment "
.endif

.ifdef(WITH_SKIN_HAYRAPHON)
EXTRACT_ONLY+=	${HAYRAPHON_FILE}
PLIST_SUB+=	HAYRAPHON=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	HAYRAPHON="@comment "
.endif

.ifdef(WITH_SKIN_HWSW)
EXTRACT_ONLY+=	${HWSW_FILE}
PLIST_SUB+=	HWSW=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	HWSW="@comment "
.endif

.ifdef(WITH_SKIN_INDUSTRIAL)
EXTRACT_ONLY+=	${INDUSTRIAL_FILE}
PLIST_SUB+=	INDUSTRIAL=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	INDUSTRIAL="@comment "
.endif

.ifdef(WITH_SKIN_JIMPLAYER)
EXTRACT_ONLY+=	${JIMPLAYER_FILE}
PLIST_SUB+=	JIMPLAYER=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	JIMPLAYER="@comment "
.endif

.ifdef(WITH_SKIN_KDE)
EXTRACT_ONLY+=	${KDE_FILE}
PLIST_SUB+=	KDE=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	KDE="@comment "
.endif

.ifdef(WITH_SKIN_KRYSTAL)
EXTRACT_ONLY+=	${KRYSTAL_FILE}
PLIST_SUB+=	KRYSTAL=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	KRYSTAL="@comment "
.endif

.ifdef(WITH_SKIN_MENTALIC)
EXTRACT_ONLY+=	${MENTALIC_FILE}
PLIST_SUB+=	MENTALIC=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	MENTALIC="@comment "
.endif

.ifdef(WITH_SKIN_MIDNIGHTLOVE)
EXTRACT_ONLY+=	${MIDNIGHTLOVE_FILE}
PLIST_SUB+=	MIDNIGHTLOVE=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	MIDNIGHTLOVE="@comment "
.endif

.ifdef(WITH_SKIN_MINI)
EXTRACT_ONLY+=	${MINI_FILE}
PLIST_SUB+=	MINI=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	MINI="@comment "
.endif

.ifdef(WITH_SKIN_NEUTRON)
EXTRACT_ONLY+=	${NEUTRON_FILE}
PLIST_SUB+=	NEUTRON=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	NEUTRON="@comment "
.endif

.ifdef(WITH_SKIN_NEWAGE)
EXTRACT_ONLY+=	${NEWAGE_FILE}
PLIST_SUB+=	NEWAGE=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	NEWAGE="@comment "
.endif

.ifdef(WITH_SKIN_ORANGE)
EXTRACT_ONLY+=	${ORANGE_FILE}
PLIST_SUB+=	ORANGE=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	ORANGE="@comment "
.endif

.ifdef(WITH_SKIN_OSXBRUSHED)
EXTRACT_ONLY+=	${OSXBRUSHED_FILE}
PLIST_SUB+=	OSXBRUSHED=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	OSXBRUSHED="@comment "
.endif

.ifdef(WITH_SKIN_OSXMOD)
EXTRACT_ONLY+=	${OSXMOD_FILE}
PLIST_SUB+=	OSXMOD=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	OSXMOD="@comment "
.endif

.ifdef(WITH_SKIN_PHONY)
EXTRACT_ONLY+=	${PHONY_FILE}
PLIST_SUB+=	PHONY=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	PHONY="@comment "
.endif

.ifdef(WITH_SKIN_PLASTIC)
EXTRACT_ONLY+=	${PLASTIC_FILE}
PLIST_SUB+=	PLASTIC=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	PLASTIC="@comment "
.endif

.ifdef(WITH_SKIN_POWERPLAYER)
EXTRACT_ONLY+=	${POWERPLAYER_FILE}
PLIST_SUB+=	POWERPLAYER=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	POWERPLAYER="@comment "
.endif

.ifdef(WITH_SKIN_PROTON)
EXTRACT_ONLY+=	${PROTON_FILE}
PLIST_SUB+=	PROTON=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	PROTON="@comment "
.endif

.ifdef(WITH_SKIN_QPLAYER)
EXTRACT_ONLY+=	${QPLAYER_FILE}
PLIST_SUB+=	QPLAYER=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	QPLAYER="@comment "
.endif

.ifdef(WITH_SKIN_SLIM)
EXTRACT_ONLY+=	${SLIM_FILE}
PLIST_SUB+=	SLIM=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	SLIM="@comment "
.endif

.ifdef(WITH_SKIN_SOFTGRIP)
EXTRACT_ONLY+=	${SOFTGRIP_FILE}
PLIST_SUB+=	SOFTGRIP=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	SOFTGRIP="@comment "
.endif

.ifdef(WITH_SKIN_TERMINATOR3)
EXTRACT_ONLY+=	${TERMINATOR3_FILE}
PLIST_SUB+=	TERMINATOR3=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	TERMINATOR3="@comment "
.endif

.ifdef(WITH_SKIN_TRIUM)
EXTRACT_ONLY+=	${TRIUM_FILE}
PLIST_SUB+=	TRIUM=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	TRIUM="@comment "
.endif

.ifdef(WITH_SKIN_TVISOR)
EXTRACT_ONLY+=	${TVISOR_FILE}
PLIST_SUB+=	TVISOR=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	TVISOR="@comment "
.endif

.ifdef(WITH_SKIN_ULTRAFINA)
EXTRACT_ONLY+=	${ULTRAFINA_FILE}
PLIST_SUB+=	ULTRAFINA=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	ULTRAFINA="@comment "
.endif

.ifdef(WITH_SKIN_WINDOWSMEDIAPLAYER6)
EXTRACT_ONLY+=	${WMP6}
PLIST_SUB+=	WINDOWSMEDIAPLAYER6=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	WINDOWSMEDIAPLAYER6="@comment "
.endif

.ifdef(WITH_SKIN_XANIM)
EXTRACT_ONLY+=	${XANIM_FILE}
PLIST_SUB+=	XANIM=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	XANIM="@comment "
.endif

.ifdef(WITH_SKIN_XFCE4)
EXTRACT_ONLY+=	${XFCE4_FILE}
PLIST_SUB+=	XFCE4=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	XFCE4="@comment "
.endif

.ifdef(WITH_SKIN_XINE_LCD)
EXTRACT_ONLY+=	${XINE_LCD_FILE}
PLIST_SUB+=	XINE_LCD=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	XINE_LCD="@comment "
.endif

.ifdef(WITH_SKIN_XMMPLAYER)
EXTRACT_ONLY+=	${XMMPLAYER_FILE}
PLIST_SUB+=	XMMPLAYER=""
HAVE_SKIN=	true
.else
PLIST_SUB+=	XMMPLAYER="@comment "
.endif

do-build:
.if defined(HAVE_SKIN)
	@${TRUE}
.else
	@${ECHO} "No skin selected"
	@${FALSE}
.endif

do-install:
# create target directories
	@${MKDIR} ${PREFIX}/${myDATADIR}
.if defined(WITH_SKIN_DEFAULT)
	@${LN} -sf "${PREFIX}/${myDATADIR}/Blue" "${PREFIX}/${myDATADIR}/default"
.endif
# both anotate and create target directories
	@for dir in `cd ${WRKDIR} && ${FIND} . -type d ! -name ".*" | ${SORT} -r` ; do \
		${MKDIR} "${PREFIX}/${myDATADIR}/$${dir#./}" ; \
		LAST_DIR="$${dir#./}"; \
	done && [ "x${WITH_SKIN_DEFAULT}" != "xyes" ] && \
	${LN} -sf "${PREFIX}/${myDATADIR}/$${LAST_DIR#./}" "${PREFIX}/${myDATADIR}/default" || ${TRUE}
# both anotate installed and install files
	@for file in `cd ${WRKDIR} && ${FIND} . -type f ! -name ".*" | ${SORT}` ; do \
		${INSTALL_DATA} "${WRKDIR}/$${file#./}" ${PREFIX}/${myDATADIR}/$${file#./} ; \
	done
# add marker file
	@${CP} /dev/null ${PREFIX}/${myDATADIR}/${PKGNAME}

.include <bsd.port.post.mk>
