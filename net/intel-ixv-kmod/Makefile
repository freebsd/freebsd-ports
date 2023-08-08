PORTNAME=	ixv
PORTVERSION=	1.5.33
PORTEPOCH=	0
MASTER_SITES?=	https://downloadmirror.intel.com/762491/ \
		https://downloadmirror.intel.com/29626/eng/:man \

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${_MAN_SOURCE}${EXTRACT_SUFX}:man
_MAN_SOURCE=	${PORTNAME}-1.5.17

MAINTAINER=	freebsd@intel.com
COMMENT=	10G FreeBSD Base Driver Virtual Function for Intel(R) NIC

MANPAGENAME=	ixgbe
MANPAGELINKS=	ixv if_ixv if_ixgbevf

MASTERDIR=	${.CURDIR}/../intel-ixl-kmod
PATCHDIR=	${.CURDIR}/files
PKGDIR=		${.CURDIR}
DISTINFO_FILE=	${.CURDIR}/distinfo

pre-install:
	${CP} ${WRKDIR}/${_MAN_SOURCE}/src/${MANPAGENAME}.4 ${WRKSRC}

.include "${MASTERDIR}/Makefile"
