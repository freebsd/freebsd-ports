PORTNAME=	igb
PORTVERSION=	2.5.28
PORTREVISION=	0
PORTEPOCH=	0
MASTER_SITE_SUBDIR=	786099

MAINTAINER=	freebsd@intel.com
COMMENT=	NIC Driver for Intel(R) 82575/6 and 82580-Based cards

BROKEN_armv6=		fails to compile: implicit declaration of function 'cp15_pmccntr_get' is invalid in C99

MASTERDIR=	${.CURDIR}/../intel-ixl-kmod
PKGDIR=		${.CURDIR}
DISTINFO_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/files

.include "${MASTERDIR}/Makefile"
