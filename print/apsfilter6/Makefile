# New ports collection makefile for:	apsfilter
# Date created: 	Tue Nov 14 18:29:48 MET 1995
# Whom: 		Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	apsfilter
PORTVERSION=	6.0.0
CATEGORIES=	print
MASTER_SITES=	http://www.apsfilter.org/download/
DISTFILES=	apsfilter-current-09.09.2000.tar.bz2

MAINTAINER=	andreas@FreeBSD.org

.if defined(BATCH) && defined(APSFILTER_ALL)
# Please note: this might be needed only in rare cases or for testing
# all of apsfilters capabilities
# ps emulator
RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript6
# all needed decompression utilities
RUN_DEPENDS+=	bunzip2:${PORTSDIR}/archivers/bzip2
RUN_DEPENDS+=	melt:${PORTSDIR}/archivers/freeze
# all needed "xxx to ps" filter utilities
RUN_DEPENDS+=	a2ps:${PORTSDIR}/print/a2ps-letter
RUN_DEPENDS+=	acroread4:${PORTSDIR}/print/acroread4
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS+=	dvips:${PORTSDIR}/print/teTeX
RUN_DEPENDS+=	html2ps:${PORTSDIR}/print/html2ps-letter
RUN_DEPENDS+=	psnup:${PORTSDIR}/print/psutils-letter
RUN_DEPENDS+=	transfig:${PORTSDIR}/print/transfig
# all possible remote printing support
RUN_DEPENDS+=	pap:${PORTSDIR}/net/netatalk
RUN_DEPENDS+=	smbclient:${PORTSDIR}/net/samba
.elif defined(BATCH)
# ps emulator
RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript6
# most important "xxx to ps" filter utilities
RUN_DEPENDS+=	a2ps:${PORTSDIR}/print/a2ps-letter
RUN_DEPENDS+=	psnup:${PORTSDIR}/print/psutils-letter
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif

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
.else
post-install:
	@${MKDIR} ${PREFIX}/apsfilter/filter
	@${TOUCH} ${PREFIX}/apsfilter/filter/.keep_me
.endif

.include <bsd.port.mk>
