# New ports collection makefile for:    adobe-cmaps
# Date created:         Wed, 10 Apr 2002 02:22:30 +0900
# Whom:                 KATO Tsuguru <tkato@prontomail.com>
#
# $FreeBSD$
#

PORTNAME=	adobe-cmaps
PORTVERSION=	20051217
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.oreilly.com/pub/examples/nutshell/cjkv/adobe/
DISTFILES=	ac15.tar.Z ag15.tar.Z \
		ai0.tar.Z aj16.tar.Z \
		aj20.tar.Z ak12.tar.Z rksj-cmaps.tar.Z \
		tounicode.tar.Z
DIST_SUBDIR=	adobe

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Adobe CMap collection

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_SUB=	CMAPDIR=${CMAPDIR}
INSTDIRS=	ac15 ag15 ai0 aj16 aj20 ak12 rksj-cmaps tounicode
CMAPDIR=	share/fonts/${PORTNAME}

post-extract:
	${RM} -f ${WRKDIR}/ag15/.nfsFA55

do-install:
	${MKDIR} ${PREFIX}/${CMAPDIR}
	cd ${WRKDIR} && \
		${TAR} cf - ${INSTDIRS} | \
		(cd ${PREFIX}/${CMAPDIR} && ${TAR} xf - )

.include <bsd.port.mk>
