# New ports collection makefile for:	acx100
# Date created:				2004-07-01
# Whom:					Leonid Zolotarev <leoz.2005@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	acx
PORTVERSION=	6.1
PORTEPOCH=	1
CATEGORIES=	net kld
MASTER_SITES=	http://dev.kewl.org/acx100+111/:file_0 \
		ftp://ftp.dlink.co.uk/wireless/dwl-650+/:file_1 \
		http://freebsd.csie.nctu.edu.tw/pub/distfiles/acx/:file_1 \
		http://download.tdc.dk/pub/tdconline/kundeservice/firmware/netkort/:file_2 \
		ftp://downloads.netgear.com/files/:file_2
DISTFILES=	${DISTFILE_0}:file_0 \
		${DISTFILE_1}:file_1 \
		${DISTFILE_2}:file_2
DIST_SUBDIR=	acx
EXTRACT_ONLY=	${DISTFILE_0}

MAINTAINER=	shuvaev@physik.uni-wuerzburg.de
COMMENT=	Texas Instruments (TI) ACX100 and ACX111 IEEE 802.11 driver

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_PACKAGE=	This port should be recompiled for a particular FreeBSD kernel
ONLY_FOR_ARCHS=	amd64 i386

MAN4=		if_acx.4

DISTFILE_0=	${DISTNAME}.tgz
DISTFILE_1=	dwl-650+_drv_v3.06_1007_inc_utility.zip
DISTFILE_2=	wg311v2_v2_0_0_7.zip
FIRMWAREDIR=	firmware
KMODDIR?=	/boot/modules

MAKE_ENV+=	KMODDIR="${KMODDIR}"
PLIST_SUB+=	KMODDIR=${KMODDIR}

.include <bsd.port.pre.mk>

pre-fetch:
.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires the kernel sources to be available
.endif

post-patch:
.if ${OSVERSION} >= 800049
	@${REINPLACE_CMD} -e 's/suser(thred)/priv_check(thred, PRIV_DRIVER)/' \
		${WRKSRC}/acx/if_acxifnet.c
.endif

pre-build:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILE_1} ${WRKSRC}/${FIRMWAREDIR}/acx100 && \
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILE_2} ${WRKSRC}/${FIRMWAREDIR}/acx111 && \
	cd ${BUILD_WRKSRC}/${FIRMWAREDIR} && \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}

# Prevent auxiliary bin2h programm from being installed
pre-install:
	@${REINPLACE_CMD} -e 's/bin2h //' ${WRKSRC}/Makefile

do-install:
	@cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET}
	${INSTALL_MAN} ${WRKSRC}/acx/if_acx.4 ${PREFIX}/man/man4

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
