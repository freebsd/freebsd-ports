# New ports collection makefile for:	iwi-firmware
# Date created:				Jun 11 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iwi-firmware
RELNAME=	ipw2200
PORTVERSION=	2.3
PORTREVISION=	0
CATEGORIES=	net sysutils

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Intel PRO/Wireless 2200 Driver Firmware

MASTERDIR=	${.CURDIR}/../ipw-firmware
MD5_FILE=	${.CURDIR}/distinfo
PLIST=		${.CURDIR}/pkg-plist
FILESDIR=	${.CURDIR}/files

DRIVERNAME=	iwi
DRIVERVERSION=	1.3.4
FIRMWARES=	ipw-${PORTVERSION}-boot.fw		\
		ipw-${PORTVERSION}-bss.fw		\
		ipw-${PORTVERSION}-bss_ucode.fw		\
		ipw-${PORTVERSION}-ibss.fw		\
		ipw-${PORTVERSION}-ibss_ucode.fw	\
		ipw-${PORTVERSION}-sniffer.fw		\
		ipw-${PORTVERSION}-sniffer_ucode.fw

.include "${MASTERDIR}/Makefile"
