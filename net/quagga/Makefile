# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quagga
PORTVERSION=	0.99.23.1
PORTREVISION=	2
CATEGORIES=	net ipv6
MASTER_SITES=	SAVANNAH

MAINTAINER=	mat@FreeBSD.org
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
OPTIONS_SUB=	yes

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
PAM_CONFIGURE_WITH=	libpam
OSPF_OPAQUE_LSA_CONFIGURE_ENABLE=	opaque-lsa
RTADV_CONFIGURE_ENABLE=	rtadv
SNMP_CONFIGURE_ENABLE=	snmp
SNMP_LIB_DEPENDS=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp
TCPSOCKETS_CONFIGURE_ENABLE=	tcp-zebra
DLMALLOC_LIB_DEPENDS=	libdlmalloc.so:${PORTSDIR}/devel/libdlmalloc
DLMALLOC_LIBS=		-L${LOCALBASE}/lib -ldlmalloc
NO_BGP_ANNOUNCE_CONFIGURE_ARGS+=--disable-bgp-announce
OSPF_NEXTHOP_EXTRA_PATCH=	${PATCHDIR}/extra-patch-ospf-nexthop

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
	@${MV} ${STAGEDIR}${ETCDIR}/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
