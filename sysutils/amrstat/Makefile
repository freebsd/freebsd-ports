# Ports collection makefile for:  amrstat
# Date created:                   2006-04-11
# Whom:                           "Bjoern A. Zeeb" <bzeeb+freebsd+ports@zabbadoz.net>
#
# $FreeBSD$
#

PORTNAME=	amrstat
PORTVERSION=	20070216
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freebsd.org/~jkim/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Utility for LSI Logic's MegaRAID RAID controllers

OPTIONS=	MEGARC "Also install LSI megarc binary port.." off

.include <bsd.port.pre.mk>

# We may want this for periodic script and to actually be able
# to fix something in case amrstat reports degraded RAID.
.if defined(WITH_MEGARC)
RUN_DEPENDS=	${LOCALBASE}/sbin/megarc:${PORTSDIR}/sysutils/megarc
.endif

ALL_TARGET=	${PORTNAME}

LOCALSRCDIR=	${.CURDIR}/files
PERIODICSCRIPT=	407.status-amr-raid

NO_WRKSUBDIR=	yes

SUB_FILES+=	${PERIODICSCRIPT}

post-extract:
	${RM} -f ${WRKSRC}/amrstat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amrstat ${PREFIX}/sbin
	${INSTALL_SCRIPT} -d ${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/${PERIODICSCRIPT} ${PREFIX}/etc/periodic/daily

.include <bsd.port.post.mk>
