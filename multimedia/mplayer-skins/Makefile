# New ports collection makefile for:	mplayer gui skins
# Date created:				Sat Jan 12 10:59:45 BRST 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mplayer
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.mplayerhq.hu/MPlayer/Skin/ \
		http://ftp.lug.udel.edu/MPlayer/Skin/ \
		ftp://ftp.mplayerhq.hu/MPlayer/Skin/ \
		ftp://ftp.lug.udel.edu/MPlayer/Skin/
PKGNAMESUFFIX=	-skins
DISTFILES=	# filled in later after options
DIST_SUBDIR=	mplayer

MAINTAINER=	riggs@rrr.de
COMMENT=	Skins for MPlayer's Graphical User Interface (GUI)

#
# When adding a new skin, please make sure to add it after the following
# comment sections:
# - Filenames
# - Options
# - Allskins
#
# Then do "make config", select "All Skins" and run "make makesum".
#

USE_BZIP2=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

#
# Filenames
#
ABYSS_FILE=		Abyss-1.1.tar.bz2
ALIENMIND_FILE=		AlienMind-1.2.tar.bz2
AVIFILE_FILE=		avifile-1.6.tar.bz2
BLUECURVE_FILE=		bluecurve-1.3.tar.bz2
BLUEHEART_FILE=		BlueHeart-1.5.tar.bz2
CANARY_FILE=		Canary-1.2.tar.bz2
CORELIAN_FILE=		Corelian-1.1.tar.bz2
CORNERMP_AQUA_FILE=	CornerMP-aqua-1.4.tar.bz2
CORNERMP_FILE=		CornerMP-1.2.tar.bz2
CUBICPLAYER_FILE=	CubicPlayer-1.1.tar.bz2
CYRUS_FILE=		Cyrus-1.2.tar.bz2
DEFAULT_FILE=		Blue-1.4.tar.bz2
DEFAULT_SMALL_FILE=	Blue-small-1.2.tar.bz2
DISAPPEARER_FILE=	disappearer-1.1.tar.bz2
DIVXPLAYER_FILE=	divxplayer-1.3.tar.bz2
DUSHKU_FILE=		Dushku-1.2.tar.bz2
DVDPLAYER_FILE=		DVDPlayer-1.1.tar.bz2
GNOME_FILE=		gnome-1.1.tar.bz2
HANDHELD_FILE=		handheld-1.0.tar.bz2
HAYRAPHON_FILE=		hayraphon-1.0.tar.bz2
HWSW_FILE=		hwswskin-1.1.tar.bz2
INDUSTRIAL_FILE=	Industrial-1.0.tar.bz2
ITUNES_FILE=		iTunes-1.1.tar.bz2
ITUNES_MINI_FILE=	iTunes-mini-1.1.tar.bz2
JIMPLAYER_FILE=		JiMPlayer-1.4.tar.bz2
KDE_FILE=		KDE-0.3.tar.bz2
KRYSTAL_FILE=		krystal-1.1.tar.bz2
MENTALIC_FILE=		mentalic-1.2.tar.bz2
MIDNIGHTLOVE_FILE=	MidnightLove-1.6.tar.bz2
MINI_FILE=		mini-0.1.tar.bz2
MOONPHASE_FILE=		moonphase-1.0.tar.bz2
MPLAYER_RED_FILE=	mplayer_red-1.0.tar.bz2
NETSCAPE4_FILE=		netscape4-1.0.tar.bz2
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
QUICKSILVER_FILE=	QuickSilver-1.0.tar.bz2
SESSENE_FILE=		sessene-1.0.tar.bz2
SLIM_FILE=		slim-1.2.tar.bz2
SOFTGRIP_FILE=		softgrip-1.1.tar.bz2
TERMINATOR3_FILE=	Terminator3-1.1.tar.bz2
TRIUM_FILE=		trium-1.3.tar.bz2
TVISOR_FILE=		tvisor-1.1.tar.bz2
ULTRAFINA_FILE=		ultrafina-1.1.tar.bz2
WEBBY_FILE=		webby-1.2.tar.bz2
WINDOWSMEDIAPLAYER6_FILE= WMP6-2.2.tar.bz2
XANIM_FILE=		xanim-1.6.tar.bz2
XFCE4_FILE=		XFce4-1.0.tar.bz2
XINE_LCD_FILE=		xine-lcd-1.2.tar.bz2
XMMPLAYER_FILE=		xmmplayer-1.5.tar.bz2

#
# Options
#
OPTIONS=	SKIN_ALL "all skins" off
OPTIONS+=	SKIN_DEFAULT "the defaul MPlayer skin" on
OPTIONS+=	SKIN_DEFAULT_SMALL "compact version of the default skin" off
OPTIONS+=	SKIN_ABYSS "beautiful MPlayer skin" off
OPTIONS+=	SKIN_ALIENMIND "AlienMind XMMS" off
OPTIONS+=	SKIN_AVIFILE "aviplay look" off
OPTIONS+=	SKIN_BLUECURVE "bluecurve" off
OPTIONS+=	SKIN_BLUEHEART "BlueHeart XMMS" off
OPTIONS+=	SKIN_CANARY "small, compact" off
OPTIONS+=	SKIN_CORELIAN "plain look" off
OPTIONS+=	SKIN_CORNERMP "WinAMP corner" off
OPTIONS+=	SKIN_CORNERMP_AQUA "WinAMP corner aqua" off
OPTIONS+=	SKIN_CUBICPLAYER "CubicPlayer" off
OPTIONS+=	SKIN_CYRUS "Cyrus XMMS" off
OPTIONS+=	SKIN_DISAPPEARER "very slim" off
OPTIONS+=	SKIN_DIVXPLAYER "Divx" off
OPTIONS+=	SKIN_DUSHKU "Eliza Dushku" off
OPTIONS+=	SKIN_DVDPLAYER "hardware player lookalike" off
OPTIONS+=	SKIN_GNOME "based on the GNOME logo" off
OPTIONS+=	SKIN_HANDHELD "remote control look" off
OPTIONS+=	SKIN_HAYRAPHON "Hayraphon" off
OPTIONS+=	SKIN_HWSW "simplistic" off
OPTIONS+=	SKIN_INDUSTRIAL "Industrial GTK theme" off
OPTIONS+=	SKIN_ITUNES "iTunes" off
OPTIONS+=	SKIN_ITUNES_MINI "iTunes mini" off
OPTIONS+=	SKIN_JIMPLAYER "round and colorful" off
OPTIONS+=	SKIN_KDE "uses KDE images" off
OPTIONS+=	SKIN_KRYSTAL "very colorful" off
OPTIONS+=	SKIN_MENTALIC "sharp and shiny" off
OPTIONS+=	SKIN_MIDNIGHTLOVE "XMMS skin of Rei Ayanami" off
OPTIONS+=	SKIN_MINI "MPlayer-plugin for mozilla" off
OPTIONS+=	SKIN_MOONPHASE "MoonPhase" off
OPTIONS+=	SKIN_MPLAYER_RED "MPlayer RED" off
OPTIONS+=	SKIN_NETSCAPE4 "Netscape \"unatkozok\"" off
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
OPTIONS+=	SKIN_QUICKSILVER "QuickSilver" off
OPTIONS+=	SKIN_SESSENE "Sessene" off
OPTIONS+=	SKIN_SLIM "small and cute" off
OPTIONS+=	SKIN_SOFTGRIP "strange design" off
OPTIONS+=	SKIN_TERMINATOR3 "inspired by Terminator 3" off
OPTIONS+=	SKIN_TRIUM "based on a mobile phone" off
OPTIONS+=	SKIN_TVISOR "simple, well-designed" off
OPTIONS+=	SKIN_ULTRAFINA "XMMS ultrafina" off
OPTIONS+=	SKIN_WEBBY "Webby" off
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

#
# Allskins
#
ALLSKINS=	ABYSS ALIENMIND AVIFILE BLUECURVE BLUEHEART CANARY \
		CORELIAN CORNERMP CORNERMP_AQUA CUBICPLAYER CYRUS \
		DISAPPEARER DIVXPLAYER DUSHKU DVDPLAYER GNOME HANDHELD \
		HAYRAPHON HWSW INDUSTRIAL ITUNES ITUNES_MINI JIMPLAYER \
		KDE KRYSTAL MENTALIC MIDNIGHTLOVE MINI MOONPHASE \
		MPLAYER_RED NETSCAPE4 NEUTRON NEWAGE ORANGE OSXBRUSHED \
		OSXMOD PHONY PLASTIC POWERPLAYER PROTON QPLAYER \
		QUICKSILVER SESSENE SLIM SOFTGRIP TERMINATOR3 TRIUM \
		TVISOR ULTRAFINA WEBBY WINDOWSMEDIAPLAYER6 XANIM XFCE4 \
		XINE_LCD XMMPLAYER \
		DEFAULT DEFAULT_SMALL

# Build and install all skins (rather expensive)
.if defined(WITH_SKIN_ALL)
.for f in ${ALLSKINS}
WITH_SKIN_${f}=	yes
.endfor
.endif # WITH_SKIN_ALL

#
# files to extract
#
.for f in ${ALLSKINS}
.ifdef(WITH_SKIN_${f})
PLIST_SUB+=	${f}="" WITHOUT_SKIN_${f}="@comment "
HAVE_SKIN=	true
DISTFILES+=	${${f}_FILE}
.else
PLIST_SUB+=	${f}="@comment " WITHOUT_SKIN_${f}=""
.endif
.endfor

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
#.if defined(WITH_SKIN_DEFAULT)
#	@${LN} -sf "${PREFIX}/${myDATADIR}/Blue" "${PREFIX}/${myDATADIR}/default"
#.endif
# both anotate and create target directories
	@for dir in `cd ${WRKDIR} && ${FIND} . -type d ! -name ".*" | ${SORT} -r` ; do \
		${MKDIR} "${PREFIX}/${myDATADIR}/$${dir#./}" ; \
		LAST_DIR="$${dir#./}"; \
	done && \
	${LN} -sfh "${PREFIX}/${myDATADIR}/$${LAST_DIR#./}" "${PREFIX}/${myDATADIR}/default"
.ifdef(WITH_SKIN_DEFAULT)
	@${LN} -sfh "${PREFIX}/${myDATADIR}/Blue" "${PREFIX}/${myDATADIR}/default"
.endif
# both anotate installed and install files
	@for f in `cd ${WRKDIR} && ${FIND} . -type f ! -name ".*" | ${SORT}` ; do \
		${INSTALL_DATA} "${WRKDIR}/$${f#./}" ${PREFIX}/${myDATADIR}/$${f#./} ; \
	done
# add marker file
	@${TOUCH} ${PREFIX}/${myDATADIR}/${PKGNAME}

.include <bsd.port.post.mk>
