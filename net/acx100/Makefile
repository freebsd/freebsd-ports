# New ports collection makefile for:	acx100
# Date created:				2004-07-01
# Whom:					Leonid Zolotarev <leoz.2005@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	acx100
PORTVERSION=	20040701
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://wlan.kewl.org/download/:file_0 \
		ftp://ftp.dlink.co.uk/wireless/dwl-650+/:file_1
DISTFILES=	${DISTFILE_0}:file_0 \
		${DISTFILE_1}:file_1
DIST_SUBDIR=	acx
EXTRACT_ONLY=	${DISTFILE_0}

MAINTAINER=	leoz.2005@gmail.com
COMMENT=	Texas Instruments (TI) ACX100 IEEE 802.11 driver

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_PACKAGE=	This port should be recompiled for a particular FreeBSD kernel
ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN4=		if_acx.4

DISTFILE_0=	${DISTNAME}.tgz
DISTFILE_1=	dwl-650+_drv_v3.06_1007_inc_utility.zip
FIRMWAREDIR=	firmware
INCLUDEDIR=	${PREFIX}/include/acx

pre-fetch:
.if !exists(${SRC_BASE}/sys/Makefile)
	@${ECHO} "This port requires the kernel sources to be available"
.endif

pre-build:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILE_1} ${WRKSRC}/${FIRMWAREDIR} && \
	cd ${WRKSRC}/${FIRMWAREDIR} && \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}

pre-install:
	@${INSTALL_MAN} ${WRKSRC}/if_acx.4 ${PREFIX}/man/man4

	@${MKDIR} ${INCLUDEDIR}
	@${CP} ${WRKSRC}/include/if_acxioctl.h  ${INCLUDEDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 501107
IGNORE=		This port requires newer kernel sources that include /sys/dev/owi/if_ieee80211.h
.endif

.include <bsd.port.post.mk>
