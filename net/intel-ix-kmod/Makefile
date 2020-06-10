# Created by: Sergey Kozlov <skozlov@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ix
PORTVERSION=	3.3.14
PORTREVISION=	0
PORTEPOCH=	0
MASTER_SITE_SUBDIR=	14688/eng

MAINTAINER=	freebsd@intel.com
COMMENT=	10 gigabit FreeBSD Base Driver for Intel(R) Network Connections

MANPAGEEXISTS=	0

MAX_NETMAP_OSVERSION=	9999999

MASTERDIR=	${.CURDIR}/../intel-ixl-kmod
PKGDIR=		${.CURDIR}
DISTINFO_FILE=	${.CURDIR}/distinfo

OPTIONS_DEFINE=	SRIOV
SRIOV_DESC=	Enable SR-IOV support (experimental)

post-patch-SRIOV-on:
	@${SED} -i '' 's|SRIOV_ENABLE = 0|SRIOV_ENABLE = 1|g' ${WRKSRC}/Makefile

.include "${MASTERDIR}/Makefile"
