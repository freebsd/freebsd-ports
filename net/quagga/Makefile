# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quagga
PORTVERSION=	0.99.22.4
PORTREVISION=	3
CATEGORIES=	net ipv6
MASTER_SITES=	SAVANNAH
MASTER_SITE_SUBDIR=	quagga

PATCH_SITES=	http://quagga.net/

MAINTAINER=	boris@tagnet.ru
COMMENT=	Free RIPv1, RIPv2, OSPFv2, BGP4, IS-IS route software

LICENSE=	GPLv2

BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk

CONFLICTS=	openbgpd-[0-9]* openospfd-[0-9]* zebra-0* quagga-re-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-exampledir=${PREFIX}/share/examples/quagga
INSTALL_TARGET=	install-strip
USES=		gmake libtool makeinfo perl5 readline
USE_LDCONFIG=	yes
USE_PERL5=	build

INFO=		quagga

OPTIONS_DEFINE=	ISISD PAM OSPF_OPAQUE_LSA RTADV SNMP TCPSOCKETS DLMALLOC \
		NO_BGP_ANNOUNCE OSPF_NEXTHOP

ISISD_DESC=		Enable experimental ISIS daemon
PAM_DESC=		PAM authentication for vtysh
OSPF_OPAQUE_LSA_DESC=	OSPF Opaque-LSA support (RFC2370)
RTADV_DESC=		IPv6 Router Advertisements
TCPSOCKETS_DESC=	Use TCP/IP sockets for protocol daemons
DLMALLOC_DESC=		Use dlmalloc (makes bgpd much faster)
NO_BGP_ANNOUNCE_DESC=	Turn off BGP route announcement
OSPF_NEXTHOP_DESC=	Set ip next-hop in OSPF route maps

ENABLE_USER?=	quagga
ENABLE_GROUP?=	quagga

USERS=		${ENABLE_USER}
GROUPS=		${ENABLE_GROUP}

CONFIGURE_ARGS+=--enable-user=${ENABLE_USER}
CONFIGURE_ARGS+=--enable-group=${ENABLE_GROUP}

SYSCONF_DIR?=	${ETCDIR}
LOCALSTATE_DIR?=/var/run/quagga

CONFIGURE_ARGS+=--sysconfdir=${SYSCONF_DIR}
CONFIGURE_ARGS+=--localstatedir=${LOCALSTATE_DIR}

.if defined(ENABLE_VTY_GROUP)
CONFIGURE_ARGS+=--enable-vty-group=${ENABLE_VTY_GROUP}
.endif

CONFIGURE_ARGS+=--enable-vtysh

SCRIPTS_ENV=	PREFIX=${PREFIX} PKG_PREFIX=${PREFIX} \
		SYSCONF_DIR=${SYSCONF_DIR} SYSSTATE_DIR=${SYSSTATE_DIR} \
		ENABLE_USER=${ENABLE_USER} ENABLE_GROUP=${ENABLE_GROUP}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MISISD}
CONFIGURE_ARGS+=--enable-isisd
MAN8+=		isisd.8
PLIST_SUB+=	ISISD=""
.else
PLIST_SUB+=	ISISD="@comment "
.endif

.if ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=--with-libpam
.endif

.if ${PORT_OPTIONS:MOSPF_OPAQUE_LSA}
CONFIGURE_ARGS+=--enable-opaque-lsa
MAN8+=		ospfclient.8
PLIST_SUB+=	OSPFAPI=""
.else
CONFIGURE_ARGS+=--disable-opaque-lsa
PLIST_SUB+=	OSPFAPI="@comment "
.endif

.if ${PORT_OPTIONS:MRTADV}
CONFIGURE_ARGS+=--enable-rtadv
.endif

.if ${PORT_OPTIONS:MSNMP}
CONFIGURE_ARGS+=--enable-snmp
LIB_DEPENDS+=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp
.endif

.if ${PORT_OPTIONS:MTCPSOCKETS}
CONFIGURE_ARGS+=--enable-tcp-zebra
.endif

.if ${PORT_OPTIONS:MDLMALLOC}
LIB_DEPENDS+=	libdlmalloc.so:${PORTSDIR}/devel/libdlmalloc
LDFLAGS+=	-ldlmalloc
SUB_LIST=	RCLDCONFIG=ldconfig
.else
SUB_LIST=	RCLDCONFIG=
.endif

.if ${PORT_OPTIONS:MNO_BGP_ANNOUNCE}
CONFIGURE_ARGS+=--disable-bgp-announce
.endif

.if ${PORT_OPTIONS:MOSPF_NEXTHOP}
post-patch:
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-ospf-nexthop
.endif

USE_RC_SUBR=	quagga watchquagga

SUB_LIST+=	LOCALSTATE_DIR=${LOCALSTATE_DIR} \
		SYSCONF_DIR=${SYSCONF_DIR}

PLIST_SUB+=	LOCALSTATE_DIR=${LOCALSTATE_DIR} \
		SYSCONF_DIR=${SYSCONF_DIR} \
		ENABLE_USER=${ENABLE_USER} \
		ENABLE_GROUP=${ENABLE_GROUP}

pre-everything::
	@${ECHO} "============================================================="
	@${ECHO}
	@${ECHO} "You can build ${PORTNAME} with the following options:"
	@${ECHO}
	@${ECHO} "ENABLE_USER       Specify user to run Quagga suite as"
	@${ECHO} "ENABLE_GROUP      Specify group to run Quagga suite as"
	@${ECHO} "ENABLE_VTY_GROUP  Specify group for vty socket ownership"
	@${ECHO} "SYSCONF_DIR       Specify directory for Quagga configuration files"
	@${ECHO} "LOCALSTATE_DIR    Specify directory for Quagga runtime files"

post-install:
	${MKDIR} ${STAGEDIR}${LOCALSTATE_DIR}
	${MKDIR} ${STAGEDIR}${SYSCONF_DIR}

.if !defined(BATCH)
post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc
.endif

.include <bsd.port.mk>
