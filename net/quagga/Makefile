# New ports collection makefile for:    quagga
# Date created:         3 September 2003
# Whom:                 Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quagga
PORTVERSION=	0.99.21
CATEGORIES=	net ipv6
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	quagga

PATCH_SITES=	http://quagga.net/

MAINTAINER=	boris@tagnet.ru
COMMENT=	Free RIPv1, RIPv2, OSPFv2, BGP4, IS-IS route software

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	openbgpd-[0-9]* openospfd-[0-9]* zebra-0* quagga-re-[0-9]*

USE_AUTOTOOLS=	libtool autoheader aclocal
ACLOCAL_ARGS=	-I${LOCALBASE}/share/aclocal
BUILD_DEPENDS+=	gawk:${PORTSDIR}/lang/gawk
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PERL5_BUILD=yes
FETCH_ARGS=	-Fpr

MAN1=		vtysh.1
MAN8=		bgpd.8 ospf6d.8 ospfd.8 ripd.8 ripngd.8 zebra.8 watchquagga.8
INFO=		quagga

OPTIONS_DEFINE=	ISISD PAM OSPF_OPAQUE_LSA RTADV SNMP TCPSOCKETS DLMALLOC \
		NO_BGP_ANNOUNCE

ISISD_DESC=		Enable experimental ISIS daemon
PAM_DESC=		PAM authentication for vtysh
OSPF_OPAQUE_LSA_DESC=	OSPF Opaque-LSA support (RFC2370)
RTADV_DESC=		IPv6 Router Advertisements
TCPSOCKETS_DESC=	Use TCP/IP sockets for protocol daemons
DLMALLOC_DESC=		Use dlmalloc (makes bgpd much faster)
NO_BGP_ANNOUNCE_DESC=	Turn off BGP route announcement

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

CFLAGS+=	-I${LOCALBASE}/include
.if ${OSVERSION} >= 800000
LDFLAGS+=	-fstack-protector
.endif
CONFIGURE_ARGS+=--includedir=${PREFIX}/include --enable-exampledir=${PREFIX}/share/examples/quagga
CONFIGURE_ENV+=	LIBTOOL=${LIBTOOL} LIBTOOLIZE=${LIBTOOLIZE} \
		LIBTOOL_VERSION=${LIBTOOL_VERSION}
LDFLAGS+=	-L${LOCALBASE}/lib

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
LIB_DEPENDS+=	netsnmp:${PORTSDIR}/net-mgmt/net-snmp
.endif

.if ${PORT_OPTIONS:MTCPSOCKETS}
CONFIGURE_ARGS+=--enable-tcp-zebra
.endif

.if ${PORT_OPTIONS:MDLMALLOC}
LIB_DEPENDS+=	dlmalloc:${PORTSDIR}/devel/libdlmalloc
LDFLAGS+=	-ldlmalloc
SUB_LIST=	RCLDCONFIG=ldconfig
.else
SUB_LIST=	RCLDCONFIG=
.endif

.if ${PORT_OPTIONS:MNO_BGP_ANNOUNCE}
CONFIGURE_ARGS+=--disable-bgp-announce
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
	@${MKDIR} ${LOCALSTATE_DIR}
	@${MKDIR} ${SYSCONF_DIR}
	@${CHOWN} -R ${ENABLE_USER}:${ENABLE_GROUP} ${LOCALSTATE_DIR} \
		${SYSCONF_DIR}
	@${CAT} ${PKGMESSAGE}

.if !defined(BATCH)
post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc
.endif

.include <bsd.port.post.mk>
