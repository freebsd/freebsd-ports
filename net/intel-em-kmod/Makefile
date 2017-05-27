# Created by: Franco Fichtner <franco@opnsense.org>
# $FreeBSD$

PORTNAME=	em
PORTVERSION=	7.6.2
MASTER_SITE_SUBDIR=	17509/eng

MAINTAINER=	franco@opnsense.org
COMMENT=	Gigabit FreeBSD Base Drivers for Intel(R) Ethernet

BROKEN_armv6=		fails to compile: implicit declaration of function 'cp15_pmccntr_get' is invalid in C99
BROKEN_powerpc64=	fails to compile: pcpu.h: size of array '__assert_0' is negative

MASTERDIR=	${.CURDIR}/../intel-ixl-kmod
PKGDIR=		${.CURDIR}
DISTINFO_FILE=	${.CURDIR}/distinfo

.include "${MASTERDIR}/Makefile"
