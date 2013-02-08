# Created by:                 Sergey Matveychuk <sem@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quagga
PORTVERSION=	0.99.17.12
CATEGORIES=	net ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	quagga-re
PKGNAMESUFFIX=	-re

MAINTAINER=	sem@FreeBSD.org
COMMENT=	A branch of popular quagga software pointed at stability

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	openbgpd-[0-9]* openospfd-[0-9]* zebra-0* quagga-[0-9]*

USE_AUTOTOOLS=		libtool autoheader
USE_GMAKE=		yes
USE_LDCONFIG=		yes
USE_PERL5_BUILD=	yes
BUILD_DEPENDS+=		gawk:${PORTSDIR}/lang/gawk
LIB_DEPENDS+=		gcrypt:${PORTSDIR}/security/libgcrypt
CONFIGURE_ARGS+=	--with-libgcrypt

MAN1=		vtysh.1
MAN8=		bgpd.8 ospf6d.8 ospfd.8 ripd.8 ripngd.8 zebra.8
INFO=		quagga

OPTIONS_DEFINE=	ISISD PAM OSPF_NSSA OSPF_OPAQUE_LSA RTADV SNMP TCPSOCKETS \
		DLMALLOC NO_BGP_ANNOUNCE

ISISD_DESC=		Enable experimental ISIS daemon
PAM_DESC=		PAM authentication for vtysh
OSPF_NSSA_DESC=		NSSA support (RFC1587)
OSPF_OPAQUE_LSA_DESC=	OSPF Opaque-LSA support (RFC2370)
RTADV_DESC=		IPv6 Router Advertisements
SNMP_DESC=		SNMP support
TCPSOCKETS_DESC=	Use TCP/IP sockets for protocol daemons
DLMALLOC_DESC=		Use dlmalloc (makes bgpd much faster)
NO_BGP_ANNOUNCE_DESC=	Turn off BGP route announcement

.include <bsd.port.options.mk>

CFLAGS+=	-I${LOCALBASE}/include
.if ${OSVERSION} >= 800000
LDFLAGS+=	-fstack-protector
.endif
CONFIGURE_ARGS+=--includedir=${PREFIX}/include --enable-exampledir=${PREFIX}/share/examples/quagga
CONFIGURE_ENV+=	LIBTOOL=${LIBTOOL} LIBTOOLIZE=${LIBTOOLIZE} \
		LIBTOOL_VERSION=${LIBTOOL_VERSION}
LDFLAGS+=	-L${LOCALBASE}/lib

.if !defined(ENABLE_USER)
ENABLE_USER=quagga
.endif
.if !defined(ENABLE_GROUP)
ENABLE_GROUP=quagga
.endif

CONFIGURE_ARGS+=--enable-user=${ENABLE_USER}
CONFIGURE_ARGS+=--enable-group=${ENABLE_GROUP}

.if !defined(SYSCONF_DIR)
SYSCONF_DIR=${PREFIX}/etc/quagga
.endif
.if !defined(LOCALSTATE_DIR)
LOCALSTATE_DIR=/var/run/quagga
.endif

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
PLIST_SUB+=	ISISD=""
.else
PLIST_SUB+=	ISISD="@comment "
.endif
MAN8+=		isisd.8

.if ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=--with-libpam
.endif

.if ${PORT_OPTIONS:MOSPFNSSA}
CONFIGURE_ARGS+=--enable-nssa
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
LIB_DEPENDS+=netsnmp:${PORTSDIR}/net-mgmt/net-snmp
.endif

.if ${PORT_OPTIONS:MTCPSOCKETS}
CONFIGURE_ARGS+=--enable-tcp-zebra
.endif

.if ${PORT_OPTIONS:MDLMALLOC}
LIB_DEPENDS+=dlmalloc:${PORTSDIR}/devel/libdlmalloc
LDFLAGS+=-ldlmalloc
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
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO} "===>     installing ${PORTNAME} startup file..."
	@${ECHO} "Add the following lines to /etc/rc.conf to enable quagga:"
	@${ECHO} ""
	@${ECHO} "defaultrouter=\"NO\""
	@${ECHO} "quagga_enable=\"YES\""
	@${ECHO} ""
	@${ECHO} "Also, you may wish to set the following options:"
	@${ECHO} "quagga_daemons=\"zebra bgpd etc...\""
	@${ECHO} "quagga_flags=\"....\""
	@${ECHO} "quagga_extralibs_path=\"/path1 /path2\""
	@${ECHO} "router_enable=\"NO\""
	@${ECHO} "watchquagga_enable=\"YES\""
	@${ECHO} "watchquagga_flags=\"...\""
	@${ECHO} ""

.if !defined(BATCH)
post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc
.endif

.include <bsd.port.mk>
