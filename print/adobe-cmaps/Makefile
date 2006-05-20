# New ports collection makefile for:    adobe-cmaps
# Date created:         Wed, 10 Apr 2002 02:22:30 +0900
# Whom:                 KATO Tsuguru <tkato@prontomail.com>
#
# $FreeBSD$
#

PORTNAME=	adobe-cmaps
PORTVERSION=	20051217
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	hrs/adobe
DISTFILES=	ac15.tar.gz ag15.tar.gz \
		ai0.tar.gz aj16.tar.gz \
		aj20.tar.gz ak12.tar.gz rksj-cmaps.tar.gz
DIST_SUBDIR=	adobe

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Adobe CMap collection

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_SUB=	CMAPDIR=${CMAPDIR}
INSTDIRS=	ac15 ag15 ai0 aj16 aj20 ak12 rksj-cmaps
CMAPDIR=	share/fonts/${PORTNAME}

post-extract:
	${RM} -f ${WRKDIR}/ag15/.nfsFA55

do-install:
	${MKDIR} ${PREFIX}/${CMAPDIR}
	cd ${WRKDIR} && \
		${TAR} cf - ${INSTDIRS} | \
		(cd ${PREFIX}/${CMAPDIR} && ${TAR} xf - )

.include <bsd.port.mk>
