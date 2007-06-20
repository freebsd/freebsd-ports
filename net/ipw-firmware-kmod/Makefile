# New ports collection makefile for:	ipw-firmware-kmod
# Date created:				Mar 16 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	ipw-firmware
PORTVERSION=	${FWVERSION}
PORTREVISION?=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flz/ipw
PKGNAMESUFFIX=	-kmod
FWNAME?=	ipw2100-fw-${FWVERSION}
FWVERSION?=	1.3
DISTFILES=	${FWNAME}.tgz

MAINTAINER=	flz@FreeBSD.org
COMMENT?=	Intel PRO/Wireless 2100 Firmware Kernel Module

DRIVERNAME?=	ipw
FIRMWARES?=	${FWNAME:C/fw-//}-i.fw:${DRIVERNAME}_ibss \
		${FWNAME:C/fw-//}-p.fw:${DRIVERNAME}_monitor \
		${FWNAME:C/fw-//}.fw:${DRIVERNAME}_bss

WRKSRC=		${WRKDIR}
KMODDIR=	/boot/modules
KMODVERSION=	${FWVERSION:C/^(...)$/\1.0/:S/.//g}
PLIST_SUB=	DRIVERNAME="${DRIVERNAME}" \
		KMODDIR="${KMODDIR}"
CFLAGS+=	-D_KERNEL

NO_PACKAGE=	"this is a modified version of a restricted firmware"

MIN6OSVERSION?=	999999
MAX6OSVERSION=	999999
MIN7OSVERSION?=	700015
MAX7OSVERSION=	700032

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} >= ${MAX7OSVERSION} || \
	( ${OSVERSION} < 700000 && ${OSVERSION} >= ${MAX6OSVERSION} ) )
IGNORE=		is already included in base system
.endif

.if !( ${OSVERSION} > ${MIN7OSVERSION} || \
	( ${OSVERSION} < 700000 && ${OSVERSION} >= ${MIN6OSVERSION} ) )
IGNORE=		needs fresh ${DRIVERNAME}(4), install net/${DRIVERNAME}-firmware instead
.endif

post-patch:
.for i in ${FIRMWARES}
	@${MKDIR} ${WRKSRC}/${i:C/.*://}
	@${MV} ${WRKSRC}/${i:C/:.*//} ${WRKSRC}/${i:C/.*://}/${i:C/.*://:S/$/.fw/}
	@${ECHO_CMD} "KMOD= ${i:C/.*://}" > ${WRKSRC}/${i:C/.*://}/Makefile
	@${ECHO_CMD} "FIRMWS= ${i:C/.*://:S/$/.fw/}:${i:C/.*://}:${KMODVERSION}" >> \
		${WRKSRC}/${i:C/.*://}/Makefile
	@${ECHO_CMD} ".include <bsd.kmod.mk>" >> ${WRKSRC}/${i:C/.*://}/Makefile
.endfor

do-build:
.for i in ${FIRMWARES}
	@cd ${WRKSRC}/${i:C/.*://}; ${SETENV} KMODDIR="${KMODDIR}" make all
.endfor

do-install:
.for i in ${FIRMWARES}
	@cd ${WRKSRC}/${i:C/.*://}; ${SETENV} KMODDIR="${KMODDIR}" make install
.endfor

.include <bsd.port.post.mk>
