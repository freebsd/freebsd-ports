# Created by: Sergey Kozlov <sergey.kozlov@intel.com>
# $FreeBSD$

PORTNAME?=	ixl
PORTVERSION?=	1.4.27
CATEGORIES=	net
MASTER_SITES=	https://downloadmirror.intel.com/${MASTER_SITE_SUBDIR}/ \
		http://downloadmirror.intel.com/${MASTER_SITE_SUBDIR}/
MASTER_SITE_SUBDIR?=	25160/eng
PKGNAMEPREFIX=	intel-
PKGNAMESUFFIX=	-kmod

MAINTAINER=	freebsd@intel.com
COMMENT?=	40 gigabit FreeBSD Base Driver for Intel(R) Network Connections

LICENSE=	BSD2CLAUSE

USES=		kmod
WRKSRC_SUBDIR=	src

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}
MANPAGENAME?=	${PORTNAME}
PLIST_FILES=	${KMODDIR}/if_${PORTNAME}_updated.ko \
		man/man4/${MANPAGENAME}.4.gz

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	Not supported on other architectures, amd64 only.

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1001000
IGNORE=		is not supported on FreeBSD 10.0 and older
.endif

.if ${OSVERSION} >= 1100000
BROKEN=		does not build
.endif

do-install:
	${INSTALL_KLD} ${WRKSRC}/if_${PORTNAME}.ko ${STAGEDIR}${KMODDIR}/if_${PORTNAME}_updated.ko
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.4 ${STAGEDIR}${MAN4PREFIX}/man/man4/

.include <bsd.port.post.mk>
