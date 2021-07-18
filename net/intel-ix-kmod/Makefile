# Created by: Sergey Kozlov <skozlov@FreeBSD.org>

PORTNAME=	ix
PORTVERSION=	3.3.24
PORTEPOCH=	0
MASTER_SITES?=	https://downloadmirror.intel.com/14688/eng/ \
		http://downloadmirror.intel.com/14688/eng/ \
		https://downloadmirror.intel.com/29625/eng/:man \
		http://downloadmirror.intel.com/29625/eng/:man

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${_MAN_SOURCE}${EXTRACT_SUFX}:man
_MAN_SOURCE=	${PORTNAME}-3.3.10

MAINTAINER=	freebsd@intel.com
COMMENT=	10 gigabit FreeBSD Base Driver for Intel(R) Network Connections

MANPAGENAME=	ixgbe
MANPAGELINKS=	ix if_ix if_ixgbe

MAX_NETMAP_OSVERSION=	9999999

MASTERDIR=	${.CURDIR}/../intel-ixl-kmod
PKGDIR=		${.CURDIR}
DISTINFO_FILE=	${.CURDIR}/distinfo

OPTIONS_DEFINE=	SRIOV
SRIOV_DESC=	Enable SR-IOV support (experimental)

post-patch-SRIOV-on:
	@${SED} -i '' 's|SRIOV_ENABLE = 0|SRIOV_ENABLE = 1|g' ${WRKSRC}/Makefile

pre-install:
	${CP} ${WRKDIR}/${_MAN_SOURCE}/src/${MANPAGENAME}.4 ${WRKSRC}

.include "${MASTERDIR}/Makefile"
