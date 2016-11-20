# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quagga
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	net ipv6
MASTER_SITES=	SAVANNAH

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Free RIPv1, RIPv2, OSPFv2, BGP4, IS-IS route software

LICENSE=	GPLv2

BUILD_DEPENDS=	gawk:lang/gawk

CONFLICTS=	openbgpd-[0-9]* openospfd-[0-9]* zebra-0* quagga-re-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-exampledir=${PREFIX}/share/examples/quagga
INSTALL_TARGET=	install-strip
USES=		gmake libtool makeinfo perl5 readline compiler:c11 cpe
USE_LDCONFIG=	yes
USE_PERL5=	build

INFO=		quagga

OPTIONS_DEFINE=	ISISD PIMD PAM RTADV SNMP TCPSOCKETS DLMALLOC \
		NO_BGP_ANNOUNCE OSPF_NEXTHOP ISIS_TOPOLOGY
# IRDP needs something freebsd does not seem to have:
# configure: error: 'IRDP requires in_pktinfo at the moment!'
OPTIONS_DEFAULT=	ISISD PIMD RTADV
OPTIONS_SUB=	yes

PIMD_DESC=		PIM-SSM multicast routing
IRDP_DESC=		Enable IRDP server support
ISISD_DESC=		Enable ISIS daemon (beta)
ISIS_TOPOLOGY_DESC=	Enable IS-IS topology generator
PAM_DESC=		PAM authentication for vtysh
RTADV_DESC=		IPv6 Router Advertisements
TCPSOCKETS_DESC=	Use TCP/IP sockets for protocol daemons
DLMALLOC_DESC=		Use dlmalloc (makes bgpd much faster)
NO_BGP_ANNOUNCE_DESC=	Turn off BGP route announcement
OSPF_NEXTHOP_DESC=	Set ip next-hop in OSPF route maps

ENABLE_USER?=	quagga
ENABLE_GROUP?=	quagga

USERS=		${ENABLE_USER}
GROUPS=		${ENABLE_GROUP}

SYSCONF_DIR?=	${ETCDIR}
LOCALSTATE_DIR?=/var/run/quagga

CONFIGURE_ARGS=	--enable-user=${ENABLE_USER} \
		--enable-group=${ENABLE_GROUP} \
		--sysconfdir=${SYSCONF_DIR} \
		--localstatedir=${LOCALSTATE_DIR} \
		--enable-vtysh

.if defined(ENABLE_VTY_GROUP)
CONFIGURE_ARGS+=--enable-vty-group=${ENABLE_VTY_GROUP}
.endif

ISISD_CONFIGURE_ENABLE=	isisd
ISIS_TOPOLOGY_CONFIGURE_ENABLE=	isis-topology
PIMD_CONFIGURE_ENABLE=	pimd
IRDP_CONFIGURE_ENABLE=	irdp
PAM_CONFIGURE_WITH=	libpam
RTADV_CONFIGURE_ENABLE=	rtadv
SNMP_CONFIGURE_ENABLE=	snmp
SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
TCPSOCKETS_CONFIGURE_ENABLE=	tcp-zebra
DLMALLOC_LIB_DEPENDS=	libdlmalloc.so:devel/libdlmalloc
DLMALLOC_LIBS=		-L${LOCALBASE}/lib -ldlmalloc
OSPF_NEXTHOP_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-ospf-nexthop
# inverse option.
NO_BGP_ANNOUNCE_CONFIGURE_ON=	--disable-bgp-announce
NO_BGP_ANNOUNCE_CONFIGURE_OFF=	--enable-bgp-announce

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
	${MKDIR} ${STAGEDIR}${LOCALSTATE_DIR} ${STAGEDIR}${SYSCONF_DIR} \
		${STAGEDIR}${EXAMPLESDIR}
	@${MV} ${STAGEDIR}${SYSCONF_DIR}/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
