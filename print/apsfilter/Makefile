# New ports collection makefile for:	apsfilter
# Date created: 	Tue Nov 14 18:29:48 MET 1995
# Whom: 		Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	apsfilter
PORTVERSION=	7.2.8
PORTREVISION=	9
CATEGORIES=	print
MASTER_SITES=	http://www.apsfilter.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Magic print filter with print preview, duplex printing, and more

DIST_SUBDIR=	apsfilter

USE_SUBMAKE=	yes

SUB_FILES+=	pkg-message

SAMBA_PORT?=	net/samba34

# special arrangement for package building, build stuff without X11
# to make memory footprint of apsfilter package smaller
.if defined(BATCH) && defined(PACKAGE_BUILDING)
NO_X=		yes
.endif

.if defined(WITHOUT_X11)
# XXX Hack.  If you've done something like "-DWITHOUT_X11" on the command line
# (instead of WITHOUT_X11=true, or similar) gmake won't pick it up.  So make
# sure that NO_X is defined *and* has a value.
MAKE_ENV+=	NO_X=true
.endif

USE_GHOSTSCRIPT_RUN=	yes

#
# hint: for batch mode you can now draw the following decisions
# - <default>		build and install most important filter utilities
#			that don't require X
# - APSFILTER_ALL	build and install all supported filter utilities
# - WITHOUT_X11		toggles not to build tools that need X11, even if
#			APSFILTER_ALL is set
# - PAPERSIZE		Use PAPERSIZE as in a2ps port, default to letter.
PAPERSIZE?=	letter

.if ${PAPERSIZE} != a4 && ${PAPERSIZE} != letter && ${PAPERSIZE} != letterdj
.BEGIN:
	@${ECHO_CMD}
	@${ECHO_CMD} "PAPERSIZE incorrect value: ${PAPERSIZE}."
	@${ECHO_CMD}
	@${ECHO_CMD} "Must specify PAPERSIZE as one of a4, letter, or letterdj."
	@${ECHO_CMD} "letterdj allows a slightly larger margins for DeskJets."
	@${FALSE}
.endif

.if defined(BATCH) && defined(APSFILTER_ALL)
#
# Build and install all filter apsfilter knows about (rather expensive)
#
# all needed decompression utilities
RUN_DEPENDS+=	melt:${PORTSDIR}/archivers/freeze
RUN_DEPENDS+=	lzop:${PORTSDIR}/archivers/lzop
# all needed "ASCII to ps" filter utilities
RUN_DEPENDS+=	a2ps:${PORTSDIR}/print/a2ps-${PAPERSIZE}
RUN_DEPENDS+=	enscript:${PORTSDIR}/print/enscript-${PAPERSIZE}
RUN_DEPENDS+=	mpage:${PORTSDIR}/print/mpage
RUN_DEPENDS+=	recode:${PORTSDIR}/converters/recode
# all needed "ARCHIVE" extraction utilities
RUN_DEPENDS+=	arc:${PORTSDIR}/archivers/arc
RUN_DEPENDS+=	cabextract:${PORTSDIR}/archivers/cabextract
RUN_DEPENDS+=	lha:${PORTSDIR}/archivers/lha
RUN_DEPENDS+=	rar:${PORTSDIR}/archivers/rar
RUN_DEPENDS+=	rpm:${PORTSDIR}/archivers/rpm
RUN_DEPENDS+=	unarj:${PORTSDIR}/archivers/unarj
RUN_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS+=	zoo:${PORTSDIR}/archivers/zoo
# all needed "xxx to ps" filter utilities
RUN_DEPENDS+=	fitstopnm:${PORTSDIR}/graphics/netpbm
RUN_DEPENDS+=	htmldoc:${PORTSDIR}/textproc/htmldoc
RUN_DEPENDS+=	psnup:${PORTSDIR}/print/psutils-${PAPERSIZE}
.if !defined(WITHOUT_X11)
# "xxx to ps" filter utilities that require X
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS+=	dvips:${PORTSDIR}/print/dvipsk-tetex
RUN_DEPENDS+=	wmf2eps:${PORTSDIR}/graphics/libwmf
RUN_DEPENDS+=	sk2ps:${PORTSDIR}/graphics/skencil
RUN_DEPENDS+=	tgif:${PORTSDIR}/graphics/tgif
RUN_DEPENDS+=	transfig:${PORTSDIR}/print/transfig
# filter utilities for playing audio files via line printer scheduler
RUN_DEPENDS+=	mpg321:${PORTSDIR}/audio/mpg321
RUN_DEPENDS+=	ogg123:${PORTSDIR}/audio/vorbis-tools
RUN_DEPENDS+=	wavplay:${PORTSDIR}/audio/wavplay
.else
# "xxx to ps" filter utilities that don't require X
# XXX needs more work
.endif
# all possible remote printing support
RUN_DEPENDS+=	pap:${PORTSDIR}/net/netatalk
RUN_DEPENDS+=	smbclient:${PORTSDIR}/${SAMBA_PORT}
.elif defined(BATCH)
#
# in normal batch/portbuilding mode (without building all)
# don't build too many dependencies
# since apsfilter should fit easily on installation CD 1...
#
# most important "xxx to ps" filter utilities
RUN_DEPENDS+=	a2ps:${PORTSDIR}/print/a2ps-${PAPERSIZE}
RUN_DEPENDS+=	psnup:${PORTSDIR}/print/psutils-${PAPERSIZE}
.endif

# needed for aps2file
RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash

# HP IJS driver is not automatically part of ghostscript port anymore
RUN_DEPENDS+=	hpijs:${PORTSDIR}/print/hpijs

MAN1=		apsfilter.1 aps2file.1 apsfilter-bug.1 apspreview.1
MAN5=		apsfilterrc.5

HAS_CONFIGURE=	yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/apsfilter
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" GHOSTSCRIPT_PORT="${GHOSTSCRIPT_PORT}"
CONFIGURE_ARGS=	--prefix=${PREFIX}

.if !defined(BATCH)
pre-configure:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
