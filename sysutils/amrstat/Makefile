# Ports collection makefile for:  amrstat
# Date created:                   2006-04-11
# Whom:                           "Bjoern A. Zeeb" <bzeeb+freebsd+ports@zabbadoz.net>
#
# $FreeBSD$
#

PORTNAME=	amrstat
PORTVERSION=	20060414
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freebsd.org/~jkim/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	bzeeb+freebsd+ports@zabbadoz.net
COMMENT=	Utility for LSI Logic's MegaRAID RAID controllers

OPTIONS=	MEGARC "Also install LSI megarc binary port.." off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600105
IGNORE=	does not build on FreeBSD 6.0 or earlier
.endif

# We may want this for periodic script and to actually be able
# to fix something in case amrstat reports degraded RAID.
.if defined(WITH_MEGARC)
RUN_DEPENDS=	${LOCALBASE}/sbin/megarc:${PORTSDIR}/sysutils/megarc
.endif

USRSRC?=	/usr/src
SYSDIR=		${USRSRC}/sys
AMRSRC=		${SYSDIR}/dev/amr

MAKE_ENV=	SYSDIR=${SYSDIR}
ALL_TARGET=	${PORTNAME}

LOCALSRCDIR=	${.CURDIR}/files
PERIODICSCRIPT=	407.status-amr-raid

NO_WRKSUBDIR=	yes

SUB_FILES+=	${PERIODICSCRIPT}

post-extract:
	@if [ ! -d ${AMRSRC} ]; then \
		${ECHO} "=================================================="; \
		${ECHO} "You need amr(4) sources in"; \
		${ECHO} "    ${AMRSRC}"; \
		${ECHO} "to build this port."; \
		${ECHO} "If your sources are not in ${USRSRC} set USRSRC."; \
		${ECHO} "=================================================="; \
		exit 1; \
	fi
	${RM} -f ${WRKSRC}/amrstat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amrstat ${PREFIX}/sbin
	${INSTALL_SCRIPT} -d ${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/${PERIODICSCRIPT} ${PREFIX}/etc/periodic/daily

.include <bsd.port.post.mk>
