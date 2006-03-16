# New ports collection makefile for:	iwi-firmware-kmod
# Date created:				Mar 16 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iwi-firmware
PORTREVISION=	0
CATEGORIES=	net sysutils

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Intel PRO/Wireless 2200 Firmware Kernel Module

MASTERDIR=	${.CURDIR}/../ipw-firmware-kmod
MD5_FILE=	${.CURDIR}/distinfo
PLIST=		${.CURDIR}/pkg-plist
DESCR=		${.CURDIR}/pkg-descr

DRIVERNAME=	iwi
FWVERSION=	3.0
FWNAME=		ipw2200-fw-${FWVERSION}
FIRMWARES=	${FWNAME}/ipw2200-bss.fw:${DRIVERNAME}_bss \
		${FWNAME}/ipw2200-ibss.fw:${DRIVERNAME}_ibss \
		${FWNAME}/ipw2200-sniffer.fw:${DRIVERNAME}_monitor \

.include "${MASTERDIR}/Makefile"
