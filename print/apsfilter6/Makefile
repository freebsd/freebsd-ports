# New ports collection makefile for:	apsfilter
# Date created: 	Tue Nov 14 18:29:48 MET 1995
# Whom: 		Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	apsfilter
PORTVERSION=	5.4.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	andreas/apsfilter

MAINTAINER=	andreas@FreeBSD.org

RUN_DEPENDS=	recode:${PORTSDIR}/converters/recode
.if defined(BATCH)
RUN_DEPENDS+=	gs:${PORTSDIR}/print/ghostscript6
RUN_DEPENDS+=	html2ps:${PORTSDIR}/print/html2ps-letter
RUN_DEPENDS+=	transfig:${PORTSDIR}/print/transfig
RUN_DEPENDS+=	cjpeg:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS+=	anytopnm:${PORTSDIR}/graphics/netpbm
RUN_DEPENDS+=	bunzip2:${PORTSDIR}/archivers/bzip2
RUN_DEPENDS+=	a2ps:${PORTSDIR}/print/a2ps-letter
RUN_DEPENDS+=	psnup:${PORTSDIR}/print/psutils-letter
RUN_DEPENDS+=	smbclient:${PORTSDIR}/net/samba
RUN_DEPENDS+=	pap:${PORTSDIR}/net/netatalk
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
