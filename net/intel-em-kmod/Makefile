# Created by: Franco Fichtner <franco@opnsense.org>
# $FreeBSD$

PORTNAME=	em
PORTVERSION=	7.7.4
PORTREVISION=	1
PORTEPOCH=	0
MASTER_SITE_SUBDIR=	17509/eng

MAINTAINER=	freebsd@intel.com
COMMENT=	Gigabit FreeBSD Base Drivers for Intel(R) Ethernet

BROKEN_armv6=		fails to compile: implicit declaration of function 'cp15_pmccntr_get' is invalid in C99

MAX_NETMAP_OSVERSION=	1199999  # Doesn't build w/NETMAP on 12

MASTERDIR=	${.CURDIR}/../intel-ixl-kmod
PKGDIR=		${.CURDIR}
DISTINFO_FILE=	${.CURDIR}/distinfo

.include "${MASTERDIR}/Makefile"
