# Created by: Sergey Kozlov <sergey.kozlov@intel.com>
# $FreeBSD$

PORTNAME?=	ixl
PORTVERSION?=	1.10.4
CATEGORIES=	net
MASTER_SITES=	https://downloadmirror.intel.com/${MASTER_SITE_SUBDIR}/ \
		http://downloadmirror.intel.com/${MASTER_SITE_SUBDIR}/
MASTER_SITE_SUBDIR?=	25160/eng
PKGNAMEPREFIX=	intel-
PKGNAMESUFFIX=	-kmod

MAINTAINER?=	freebsd@intel.com
COMMENT?=	40 gigabit FreeBSD Base Driver for Intel(R) Network Connections

LICENSE=	BSD2CLAUSE

USES=		kmod

# Present version of net/intel-em-kmod has issues building with netmap(4)
# support on 11+. Narrowing netmap(4) support to this port only
OPTIONS_SINGLE=		NETMAP
OPTIONS_SINGLE_NETMAP=	NETMAP_AUTO NETMAP_ON NETMAP_OFF
OPTIONS_DEFAULT=	NETMAP_AUTO

NETMAP_AUTO_DESC=	Enable netmap(4) support on FreeBSD 11.0+
NETMAP_ON_DESC=		Enable netmap(4) support unconditionally
NETMAP_OFF_DESC=	Disable netmap(4) support unconditionally

NETMAP_ON_CFLAGS=	-DDEV_NETMAP
NETMAP_OFF_CFLAGS=	-UDEV_NETMAP

WRKSRC_SUBDIR=	src

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}
MANPAGENAME?=	${PORTNAME}
MANPAGELINKS?=	if_${PORTNAME}
PLIST_FILES=	${KMODDIR}/if_${PORTNAME}_updated.ko \
		man/man4/${MANPAGENAME}.4.gz
MAKE_ENV+=	WERROR=""

.for link in ${MANPAGELINKS}
PLIST_FILES+=	man/man4/${link}.4.gz
.endfor

MAX_NETMAP_OSVERSION?=	9900000  # Maximum OSVERSION for which NETMAP support works

.include <bsd.port.pre.mk>

# Fixup for slave ports that use this as a master port. sbruno
.if ${PORTNAME} == ixl
ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	Not supported on other architectures, amd64 only.
.endif

.if ${PORT_OPTIONS:MNETMAP_AUTO} && ${OSVERSION} <= ${MAX_NETMAP_OSVERSION}
CFLAGS+=	-DDEV_NETMAP
.endif

do-install:
	${INSTALL_KLD} ${WRKSRC}/if_${PORTNAME}.ko ${STAGEDIR}${KMODDIR}/if_${PORTNAME}_updated.ko
	${INSTALL_MAN} ${WRKSRC}/${MANPAGENAME}.4 ${STAGEDIR}${MAN4PREFIX}/man/man4/

.for link in ${MANPAGELINKS}
	${LN} ${STAGEDIR}${MAN4PREFIX}/man/man4/${MANPAGENAME}.4 ${STAGEDIR}${MAN4PREFIX}/man/man4/${link}.4
.endfor

.include <bsd.port.post.mk>
