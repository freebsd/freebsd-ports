# New ports collection makefile for:	mplayer gui skins
# Date created:				Sat Jan 12 10:59:45 BRST 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mplayer
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.mplayerhq.hu/MPlayer/Skin/ \
		http://ftp.lug.udel.edu/MPlayer/Skin/ \
		ftp://ftp.mplayerhq.hu/MPlayer/Skin/ \
		ftp://ftp.lug.udel.edu/MPlayer/Skin/
PKGNAMESUFFIX=	-skins
DISTFILES=	Blue-1.4.tar.bz2 \
		AlienMind-1.2.tar.bz2 \
		avifile-1.6.tar.bz2 \
		BlueHeart-1.5.tar.bz2 \
		CornerMP-1.2.tar.bz2 \
		CornerMP-aqua-1.4.tar.bz2 \
		Cyrus-1.2.tar.bz2 \
		gnome-1.1.tar.bz2 \
		hayraphon-1.0.tar.bz2 \
		hwswskin-1.1.tar.bz2 \
		mentalic-1.2.tar.bz2 \
		MidnightLove-1.6.tar.bz2 \
		neutron-1.5.tar.bz2 \
		phony-1.1.tar.bz2 \
		plastic-1.2.tar.bz2 \
		proton-1.2.tar.bz2 \
		slim-1.2.tar.bz2 \
		trium-1.3.tar.bz2 \
		WMP6-2.2.tar.bz2 \
		xanim-1.6.tar.bz2 \
		xine-lcd-1.2.tar.bz2 \
		Orange-1.3.tar.bz2 \
		mini-0.1.tar.bz2
EXTRACT_ONLY=
DIST_SUBDIR=	mplayer

MAINTAINER=	riggs@rrr.de
COMMENT=	Skins for MPlayer's Graphical User Interface (GUI)

USE_SUBMAKE=	yes
USE_BZIP2=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST=		${WRKSRC}/pkg-plist
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}"

INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755

myDATADIR=	share/${PORTNAME}/Skin
# Used by other ports to detect if this is installed
SKIN_DETECTION_FILE=	${LOCALBASE}/${myDATADIR}/${PKGNAME}

# port style based on apsfilter by Andreas Klemm <andreas@FreeBSD.org>
#
# XXX - needs improvement
# We could fetch only those skins chosen for installation.
# However, this breaks both checksum and makesum targets.
# Ideas?

.if defined(BATCH)
WITH_SKIN_DEFAULT=yes
.endif	# BATCH

.if !defined(BATCH)
pre-everything::
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/choice

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif
.endif

# hint: you can now draw the following decisions for batch mode
# - WITH_SKIN_ALL	install all skins
#
# Build and install all skins (rather expensive)
#
.if defined(WITH_SKIN_ALL)
WITH_SKIN_DEFAULT=yes
WITH_SKIN_ALIENMIND=yes
WITH_SKIN_AVIFILE=yes
WITH_SKIN_BLUEHEART=yes
WITH_SKIN_CORNERMP=yes
WITH_SKIN_CORNERMP_AGUA=yes
WITH_SKIN_CYRUS=yes
WITH_SKIN_GNOME=yes
WITH_SKIN_HAYRAPHON=yes
WITH_SKIN_HWSW_SKIN=yes
WITH_SKIN_MENTALIC=yes
WITH_SKIN_MIDNIGHTLOVE=yes
WITH_SKIN_NEUTRON=yes
WITH_SKIN_PHONY=yes
WITH_SKIN_PLASTIC=yes
WITH_SKIN_PROTON=yes
WITH_SKIN_SLIM=yes
WITH_SKIN_TRIUM=yes
WITH_SKIN_WINDOWSMEDIAPLAYER6=yes
WITH_SKIN_XANIM=yes
WITH_SKIN_XINE_LCD=yes
WITH_SKIN_ORANGE=yes
WITH_SKIN_MINI=yes
. endif # WITH_SKIN_ALL

#
# files to extract
#
.ifdef(WITH_SKIN_DEFAULT)
EXTRACT_ONLY+=	Blue-1.4.tar.bz2
.endif

.ifdef(WITH_SKIN_ALIENMIND)
EXTRACT_ONLY+=	AlienMind-1.2.tar.bz2
.endif

.ifdef(WITH_SKIN_AVIFILE)
EXTRACT_ONLY+=	avifile-1.6.tar.bz2
.endif

.ifdef(WITH_SKIN_BLUEHEART)
EXTRACT_ONLY+=	BlueHeart-1.5.tar.bz2
.endif

.ifdef(WITH_SKIN_CORNERMP)
EXTRACT_ONLY+=	CornerMP-1.2.tar.bz2
.endif

.ifdef(WITH_SKIN_CORNERMP_AGUA)
EXTRACT_ONLY+=	CornerMP-aqua-1.4.tar.bz2
.endif

.ifdef(WITH_SKIN_CYRUS)
EXTRACT_ONLY+=	Cyrus-1.2.tar.bz2
.endif

.ifdef(WITH_SKIN_CYRUS)
EXTRACT_ONLY+=	gnome-1.1.tar.bz2
.endif

.ifdef(WITH_SKIN_CYRUS)
EXTRACT_ONLY+=	hayraphon-1.0.tar.bz2
.endif

.ifdef(WITH_SKIN_HWSW_SKIN)
EXTRACT_ONLY+=	hwswskin-1.1.tar.bz2
.endif

.ifdef(WITH_SKIN_MENTALIC)
EXTRACT_ONLY+=	mentalic-1.2.tar.bz2
.endif

.ifdef(WITH_SKIN_MIDNIGHTLOVE)
EXTRACT_ONLY+=	MidnightLove-1.6.tar.bz2
.endif

.ifdef(WITH_SKIN_NEUTRON)
EXTRACT_ONLY+=	neutron-1.5.tar.bz2
.endif

.ifdef(WITH_SKIN_PHONY)
EXTRACT_ONLY+=	phony-1.1.tar.bz2
.endif

.ifdef(WITH_SKIN_PLASTIC)
EXTRACT_ONLY+=	plastic-1.2.tar.bz2
.endif

.ifdef(WITH_SKIN_PROTON)
EXTRACT_ONLY+=	proton-1.2.tar.bz2
.endif

.ifdef(WITH_SKIN_SLIM)
EXTRACT_ONLY+=	slim-1.2.tar.bz2
.endif

.ifdef(WITH_SKIN_TRIUM)
EXTRACT_ONLY+=	trium-1.3.tar.bz2
.endif

.ifdef(WITH_SKIN_WINDOWSMEDIAPLAYER6)
EXTRACT_ONLY+=	WMP6-2.2.tar.bz2
.endif

.ifdef(WITH_SKIN_XANIM)
EXTRACT_ONLY+=	xanim-1.6.tar.bz2
.endif

.ifdef(WITH_SKIN_XINE_LCD)
EXTRACT_ONLY+=	xine-lcd-1.2.tar.bz2
.endif

.ifdef(WITH_SKIN_ORANGE)
EXTRACT_ONLY+=	Orange-1.3.tar.bz2
.endif

.ifdef(WITH_SKIN_MINI)
EXTRACT_ONLY+=	mini-0.1.tar.bz2
.endif

pre-install:
	@${TOUCH} ${PLIST}
# Automatically create PLIST
# creates @dirrm entries
# copies file entries
do-install: generate-plist
# remove temporary dirs' file
	@${RM} -f ${WRKDIR}/dirs.plist
# create target directories
	@${MKDIR} ${PREFIX}/${myDATADIR}
# both anotate and create target directories
	@for dir in `cd ${WRKDIR} && ${FIND} . -type d ! -name ".*" | ${SORT} -r` ; do \
		${ECHO_CMD} "@dirrm ${myDATADIR}/$${dir#./}" >> ${WRKDIR}/dirs.plist ; \
		${MKDIR} "${PREFIX}/${myDATADIR}/$${dir#./}" ; \
	done
# anotate holding dir
	@${ECHO_CMD} '@dirrm ${myDATADIR}' >> ${WRKDIR}/dirs.plist
# anotate super dir
	@${ECHO_CMD} '@unexec rmdir ${myDATADIR:S!Skin$!!} 2>/dev/null || true' >> ${WRKDIR}/dirs.plist
# remove temporary files' file
	@${RM} -f ${WRKDIR}/files.plist
# both anotate installed and install files
	@for file in `cd ${WRKDIR} && ${FIND} . -type f ! -name ".*" | ${SORT}` ; do \
		${ECHO_CMD} "${myDATADIR}/$${file#./}" >> ${WRKDIR}/files.plist ; \
		${INSTALL_DATA} "${WRKDIR}/$${file#./}" ${PREFIX}/${myDATADIR}/$${file#./} ; \
	done
# add marker file
	@${CP} /dev/null ${PREFIX}/${myDATADIR}/${PKGNAME}
	@${ECHO_CMD} '${myDATADIR}/${PKGNAME}' >> ${WRKDIR}/files.plist
# add anotations to temporary plist file
	@${CAT} ${WRKDIR}/files.plist ${WRKDIR}/dirs.plist > ${TMPPLIST}

.include <bsd.port.mk>
