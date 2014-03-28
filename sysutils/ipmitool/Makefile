# Created by: Dmitry Frolov <frol@nov.net>
# $FreeBSD$

PORTNAME=	ipmitool
PORTVERSION=	1.8.12
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	spolyack@collaborativefusion.com
COMMENT=	CLI to manage IPMI systems

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-intf-lan --enable-intf-lanplus \
		--disable-intf-imb --disable-intf-lipmi --disable-intf-bmc
PLIST_FILES=	bin/ipmitool man/man1/ipmitool.1.gz man/man8/ipmievd.8.gz \
		sbin/ipmievd share/ipmitool/oem_ibm_sel_map \
		${PERIODIC_DIR}/400.status-ipmi
PLIST_DIRS=	share/ipmitool
PLIST_DIRSTRY=	${PERIODIC_DIR} etc/periodic
SUB_FILES=	status-ipmi.sh
PORTDOCS=	AUTHORS COPYING ChangeLog README

PERIODIC_DIR=	etc/periodic/daily

OPTIONS_DEFINE=	FREEIPMI
FREEIPMI_DESC=	Enable support for freeipmi

.if defined(WITH_DEBUG)
CFLAGS+=	-ggdb -Wall
.endif

.if exists(/usr/include/sys/ipmi.h)
CONFIGURE_ARGS+=	--enable-intf-open
.else
CONFIGURE_ARGS+=	--disable-intf-open
.endif

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MDOCS)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-Makefile.in
.endif

.if ${PORT_OPTIONS:MFREEIPMI}
LIB_DEPENDS+=	libfreeipmi.so:${PORTSDIR}/sysutils/freeipmi
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--enable-intf-free
.else
CONFIGURE_ARGS+=	--disable-intf-free
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PERIODIC_DIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/status-ipmi.sh ${STAGEDIR}${PREFIX}/${PERIODIC_DIR}/400.status-ipmi

.include <bsd.port.mk>
