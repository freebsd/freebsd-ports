# New ports collection makefile for:	apsfilter
# Date created: 	Tue Nov 14 18:29:48 MET 1995
# Whom: 		Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	apsfilter
PORTVERSION=	6.1.1
CATEGORIES=	print
MASTER_SITES=	http://www.apsfilter.org/download/

MAINTAINER=	andreas@FreeBSD.org

# special arrangement for package building, build stuff without X11
# to make memory footprint of apsfilter package smaller
.if defined(BATCH) && defined(PACKAGE_BUILDING)
NO_X=		yes
.endif

.if defined(NO_X)
# XXX Hack.  If you've done something like "-DNO_X" on the command line
# (instead of NO_X=true, or similar) gmake won't pick it up.  So make sure
# that NO_X is defined *and* has a value.
MAKE_ENV+=      NO_X=true
.endif

#
# hint: for batch mode you can now draw the following decisions
# - <default>		build and install most important filter utilities
#			that don't require X
# - APSFILTER_ALL	build and install all supported filter utilities
# - NO_X		toggles not to build tools that need X11, even if
#			APSFILTER_ALL is set
#
.if defined(BATCH) && defined(APSFILTER_ALL)
#
# Build and install all filter apsfilter knows about (rather expensive)
#
# ps emulator
.if defined(NO_X)
RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript6-nox11
.else
RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript6
.endif
# all needed decompression utilities
RUN_DEPENDS+=	bunzip2:${PORTSDIR}/archivers/bzip2
RUN_DEPENDS+=	melt:${PORTSDIR}/archivers/freeze
# all needed "xxx to ps" filter utilities
RUN_DEPENDS+=	a2ps:${PORTSDIR}/print/a2ps-letter
RUN_DEPENDS+=	psnup:${PORTSDIR}/print/psutils-letter
.if !defined(NO_X)
# "xxx to ps" filter utilities that require X
RUN_DEPENDS+=	acroread4:${PORTSDIR}/print/acroread4
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS+=	dvips:${PORTSDIR}/print/teTeX
RUN_DEPENDS+=	html2ps:${PORTSDIR}/print/html2ps-letter
RUN_DEPENDS+=	transfig:${PORTSDIR}/print/transfig
.else
# "xxx to ps" filter utilities that don't require X
# XXX needs more work
.endif
# all possible remote printing support
RUN_DEPENDS+=	pap:${PORTSDIR}/net/netatalk
RUN_DEPENDS+=	smbclient:${PORTSDIR}/net/samba
.elif defined(BATCH)
#
# in normal batch/portbuilding mode (without building all)
# don't build too many dependencies
# since apsfilter should fit easily on installation CD 1...
#
# ps emulator
.if defined(NO_X)
RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript6-nox11
.else
RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript6
.endif
# most important "xxx to ps" filter utilities
RUN_DEPENDS+=	a2ps:${PORTSDIR}/print/a2ps-letter
RUN_DEPENDS+=	psnup:${PORTSDIR}/print/psutils-letter
.endif

MAN1=		apsfilter.1
MAN5=		apsfilterrc.5

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/apsfilter
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}"

# make a2ps port happy in this early stage
PAPERSIZE?=letter

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
.if defined(OSVERSION) && ${OSVERSION} < 400012
	@${ECHO} "********************************************************"
	@${ECHO} "* Please Note:                                         *"
	@${ECHO} "********************************************************"
	@${ECHO} "You have FreeBSD version <= 4.0. If you want to print   "
	@${ECHO} "troff files then you have to install the grog utility   "
	@${ECHO} "from groff sources:                                     "
	@${ECHO} "    cp /usr/src/contrib/groff/grog/grog.sh /usr/bin/grog"
	@${ECHO} "    chmod 555 /usr/bin/grog                             "
	@${ECHO} "--------------------------------------------------------"
.endif
	@${CAT} ${.CURDIR}/pkg-message

.include <bsd.port.mk>
