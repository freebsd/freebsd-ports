# New ports collection makefile for:	apsfilter
# Version required: 	4.9.3
# Date created: 	Tue Nov 14 18:29:48 MET 1995
# Whom: 		Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

DISTNAME=	apsfilter-5.1.3
CATEGORIES=	print
MASTER_SITES=	http://www.FreeBSD.org/~andreas/apsfilter/download/

MAINTAINER=	andreas@FreeBSD.org

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript55 \
		html2ps:${PORTSDIR}/print/html2ps-letter \
		transfig:${PORTSDIR}/print/transfig \
		cjpeg:${PORTSDIR}/graphics/jpeg \
		anytopnm:${PORTSDIR}/graphics/netpbm \
		bunzip2:${PORTSDIR}/archivers/bzip2 \
		recode:${PORTSDIR}/converters/recode \
		a2ps:${PORTSDIR}/print/a2ps-letter \
		psnup:${PORTSDIR}/print/psutils-letter

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/apsfilter

# make a2ps port happy in this early stage
PAPERSIZE?=	letter
.if ${PAPERSIZE} != a4 && ${PAPERSIZE} != letter && ${PAPERSIZE} != letterdj
.BEGIN:
	@${ECHO}
	@${ECHO} "PAPERSIZE incorrect value: ${PAPERSIZE}."
	@${ECHO}
	@${ECHO} "Must specify PAPERSIZE as one of a4, letter, or letterdj."
	@${ECHO} "letterdj allows a slightly larger margins for DeskJets."
	@${FALSE}
.endif

post-install:
	@${MKDIR} ${PREFIX}/apsfilter/filter
	@touch ${PREFIX}/apsfilter/filter/.keep_me
	@${ECHO} ">>>>> Post installation task: <<<<<"
	@${ECHO} "Printer installation:"
	@${ECHO} "    cd ${PREFIX}/apsfilter; ./SETUP"

.include <bsd.port.mk>
