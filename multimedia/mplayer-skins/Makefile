# New ports collection makefile for:	mplayer gui skins
# Date created:				Sat Jan 12 10:59:45 BRST 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mplayer
PORTVERSION=	1.0.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.mplayerhq.hu/MPlayer/Skin/ \
		http://ftp.mplayerhq.hu/MPlayer/Skin/ \
		http://www2.mplayerhq.hu/MPlayer/Skin/ \
		http://ftp2.mplayerhq.hu/MPlayer/Skin/
PKGNAMESUFFIX=	-skins
DISTFILES=
EXTRACT_ONLY=
DIST_SUBDIR=	mplayer

MAINTAINER=	riggs@rrr.de

USE_BZIP2=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}"
PLIST_SUB=	myDATADIR="${myDATADIR}" \
		TOP_myDATADIR="${myDATADIR:S!Skin/$!!}" \
		PKGNAME="${PKGNAME}"

INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755
SORT?=		/usr/bin/sort

myDATADIR=	share/${PORTNAME}/Skin/
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
pre-fetch:
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
WITH_SKIN_AVIFILE=yes
WITH_SKIN_BLUEHEART=yes
WITH_SKIN_CYRUS=yes
WITH_SKIN_MENTALIC=yes
WITH_SKIN_MIDNIGHTLOVE=yes
WITH_SKIN_NEUTRON=yes
WITH_SKIN_PHONY=yes
WITH_SKIN_PLASTIC=yes
WITH_SKIN_WINDOWSMEDIAPLAYER6=yes
WITH_SKIN_XANIM=yes
WITH_SKIN_XINE_LCD=yes
. endif # WITH_SKIN_ALL

#
# files to fetch
#
DISTFILES+=	default.tar.bz2
.ifdef(WITH_SKIN_DEFAULT)
EXTRACT_ONLY+=	default.tar.bz2

PLIST_SUB+=	DEFAULT=""
.else
PLIST_SUB+=	DEFAULT="@comment "
.endif

DISTFILES+=	avifile.tar.bz2
.ifdef(WITH_SKIN_AVIFILE)
EXTRACT_ONLY+=	avifile.tar.bz2

PLIST_SUB+=	AVIFILE=""
.else
PLIST_SUB+=	AVIFILE="@comment "
.endif

DISTFILES+=	BlueHeart.tar.bz2
.ifdef(WITH_SKIN_BLUEHEART)
EXTRACT_ONLY+=	BlueHeart.tar.bz2

PLIST_SUB+=	BLUEHEART=""
.else
PLIST_SUB+=	BLUEHEART="@comment "
.endif

DISTFILES+=	Cyrus.tar.bz2
.ifdef(WITH_SKIN_CYRUS)
EXTRACT_ONLY+=	Cyrus.tar.bz2

PLIST_SUB+=	CYRUS=""
.else
PLIST_SUB+=	CYRUS="@comment "
.endif

DISTFILES+=	mentalic.tar.bz2
.ifdef(WITH_SKIN_MENTALIC)
EXTRACT_ONLY+=	mentalic.tar.bz2

PLIST_SUB+=	MENTALIC=""
.else
PLIST_SUB+=	MENTALIC="@comment "
.endif

DISTFILES+=	MidnightLove.tar.bz2
.ifdef(WITH_SKIN_MIDNIGHTLOVE)
EXTRACT_ONLY+=	MidnightLove.tar.bz2

PLIST_SUB+=	MIDNIGHTLOVE=""
.else
PLIST_SUB+=	MIDNIGHTLOVE="@comment "
.endif

DISTFILES+=	neutron.tar.bz2
.ifdef(WITH_SKIN_NEUTRON)
EXTRACT_ONLY+=	neutron.tar.bz2

PLIST_SUB+=	NEUTRON=""
.else
PLIST_SUB+=	NEUTRON="@comment "
.endif

DISTFILES+=	phony.tar.bz2
.ifdef(WITH_SKIN_PHONY)
EXTRACT_ONLY+=	phony.tar.bz2

PLIST_SUB+=	PHONY=""
.else
PLIST_SUB+=	PHONY="@comment "
.endif

DISTFILES+=	plastic.tar.bz2
.ifdef(WITH_SKIN_PLASTIC)
EXTRACT_ONLY+=	plastic.tar.bz2

PLIST_SUB+=	PLASTIC=""
.else
PLIST_SUB+=	PLASTIC="@comment "
.endif

DISTFILES+=	WindowsMediaPlayer6.tar.bz2
.ifdef(WITH_SKIN_WINDOWSMEDIAPLAYER6)
EXTRACT_ONLY+=	WindowsMediaPlayer6.tar.bz2

PLIST_SUB+=	WINDOWSMEDIAPLAYER6=""
.else
PLIST_SUB+=	WINDOWSMEDIAPLAYER6="@comment "
.endif

DISTFILES+=	xanim.tar.bz2
.ifdef(WITH_SKIN_XANIM)
EXTRACT_ONLY+=	xanim.tar.bz2

PLIST_SUB+=	XANIM=""
.else
PLIST_SUB+=	XANIM="@comment "
.endif

DISTFILES+=	xine-lcd.tar.bz2
.ifdef(WITH_SKIN_XINE_LCD)
EXTRACT_ONLY+=	xine-lcd.tar.bz2

PLIST_SUB+=	XINE_LCD=""
.else
PLIST_SUB+=	XINE_LCD="@comment "
.endif

pre-install:
# marker file
	@${CP} /dev/null ${WRKSRC}/${PKGNAME}

# Following idea borrowed from halflifeserver port

# Parses PLIST
# creates dirs from @dirrm entries
# copies files from non ^@ entries
do-install: install-parse-plist install-run-scripts

# kaboom, ashes to ashes, .... The problem is dead :)
# Contributed by <lioux@FreeBSD.org>
install-parse-plist: generate-plist
	@${PERL} -e 'open(FHANDLER,"${TMPPLIST}");' \
		-e 'open(FDIR,">${WRKDIR}/dirs.sh.tmp");' \
		-e 'open(FFILES,">${WRKDIR}/files.sh");' \
		-e 'while (!eof(FHANDLER)) {' \
			-e 'chop($$file = <FHANDLER>);' \
			-e '$$dir = $$file_partial = $$file;' \
			-e '$$file_partial =~ s!^${myDATADIR}!!;' \
			-e 'print FDIR "${INSTALL_DIR}", \
				" ", "\"${PREFIX}/$$dir\"", \
				"\n" if $$dir =~ s!(^\@dirrm\s+)!!;' \
			-e 'print FFILES "${INSTALL_DATA}", \
				" ", "\"${WRKDIR}/$$file_partial\"", \
				" ", "\"${PREFIX}/$$file\"", \
				"\n" if ($$file !~ m!^\@!);' \
		-e '}' \
		-e 'close(FFILES);' \
		-e 'close(FDIR);' \
		-e 'close(FHANDLER);'
# we want it sorted
	@${SORT} ${WRKDIR}/dirs.sh.tmp > ${WRKDIR}/dirs.sh

install-run-scripts:
.for script in dirs files
	@${SH} ${WRKDIR}/${script}.sh
.endfor

.include <bsd.port.mk>
