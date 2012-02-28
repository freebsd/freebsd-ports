# New ports collection makefile for:	ipmitool
# Date created:				25/Oct/2004
# Whom:					Dmitry Frolov <frol@nov.net>
#
# $FreeBSD$
#

PORTNAME=	ipmitool
PORTVERSION=	1.8.11
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	spolyack@collaborativefusion.com
COMMENT=	CLI to manage IPMI systems

USE_BZIP2=	yes
DOS2UNIX=	ipmi_fwum.c
USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-intf-lan --enable-intf-lanplus \
		--disable-intf-imb --disable-intf-lipmi --disable-intf-bmc
PLIST_FILES=	bin/ipmitool sbin/ipmievd share/ipmitool/oem_ibm_sel_map \
		${PERIODIC_DIR}/400.status-ipmi
PLIST_DIRS=	share/ipmitool
PLIST_DIRSTRY=	${PERIODIC_DIR}
SUB_FILES=	status-ipmi.sh
PORTDOCS=	AUTHORS COPYING ChangeLog README

MAN1+=		${PORTNAME}.1
MAN8+=		ipmievd.8

PERIODIC_DIR=	etc/periodic/daily

.if defined(WITH_DEBUG)
CFLAGS+=	-ggdb -Wall
.endif

.include <bsd.port.pre.mk>

post-install:
	@${MKDIR} ${PREFIX}/${PERIODIC_DIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/status-ipmi.sh ${PREFIX}/${PERIODIC_DIR}/400.status-ipmi

.if exists(/usr/include/sys/ipmi.h)
CONFIGURE_ARGS+=	--enable-intf-open
.else
CONFIGURE_ARGS+=	--disable-intf-open
.endif

.if defined(WITH_FREEIPMI) || \
	(exists(${LOCALBASE}/include/freeipmi/freeipmi.h) && \
		!defined(WITHOUT_FREEIPMI))
LIB_DEPENDS+=	freeipmi:${PORTSDIR}/sysutils/freeipmi
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--enable-intf-free
.else
CONFIGURE_ARGS+=	--disable-intf-free
.endif

.if defined(NOPORTDOCS)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-Makefile.in
.endif

.include <bsd.port.post.mk>
