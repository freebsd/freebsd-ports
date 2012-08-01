# New ports collection makefile for:    quagga-re
# Date created:         25 Nov 2011
# Whom:                 Sergey Matveychuk <sem@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quagga
PORTVERSION=	0.99.17.11
CATEGORIES=	net ipv6
MASTER_SITES=	http://cloud.github.com/downloads/Quagga-RE/quagga-RE/
PKGNAMESUFFIX=	-re

MAINTAINER=	sem@FreeBSD.org
COMMENT=	A branch of popular quagga software pointed at stability

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

OPTIONS=	ISISD		"Enable experimental ISIS daemon"	off \
		PAM		"PAM authentication for vtysh"	off \
		OSPF_NSSA	"NSSA support (RFC1587)"	off \
		OSPF_OPAQUE_LSA	"OSPF Opaque-LSA support (RFC2370)" off \
		RTADV		"IPv6 Router Advertisements"	off \
		SNMP		"SNMP support"			off \
		TCPSOCKETS	"Use TCP/IP sockets for protocol daemons" off \
		DLMALLOC	"Use dlmalloc (makes bgpd much faster)" off \
		NO_BGP_ANNOUNCE	"Turn off BGP route announcement" off

.include <bsd.port.pre.mk>

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

.if defined(WITH_ISISD)
CONFIGURE_ARGS+=--enable-isisd
PLIST_SUB+=	ISISD=""
.else
PLIST_SUB+=	ISISD="@comment "
.endif
MAN8+=		isisd.8

.if defined(WITH_PAM)
CONFIGURE_ARGS+=--with-libpam
.endif

.if defined(WITH_OSPFNSSA)
CONFIGURE_ARGS+=--enable-nssa
.endif

.if defined(WITH_OSPF_OPAQUE_LSA)
CONFIGURE_ARGS+=--enable-opaque-lsa
PLIST_SUB+=	OSPFAPI=""
.else
CONFIGURE_ARGS+=--disable-opaque-lsa
PLIST_SUB+=	OSPFAPI="@comment "
.endif

.if defined(WITH_RTADV)
CONFIGURE_ARGS+=--enable-rtadv
.endif

.if defined(WITH_SNMP)
CONFIGURE_ARGS+=--enable-snmp
LIB_DEPENDS+=netsnmp:${PORTSDIR}/net-mgmt/net-snmp
.endif

.if defined(WITH_TCPSOCKETS)
CONFIGURE_ARGS+=--enable-tcp-zebra
.endif

.if defined(WITH_DLMALLOC)
LIB_DEPENDS+=dlmalloc:${PORTSDIR}/devel/libdlmalloc
LDFLAGS+=-ldlmalloc
SUB_LIST=	RCLDCONFIG=ldconfig
.else
SUB_LIST=	RCLDCONFIG=
.endif

.if defined(WITH_NO_BGP_ANNOUNCE)
CONFIGURE_ARGS+=--disable-bgp-announce
.endif

USE_RC_SUBR=	quagga.sh watchquagga.sh

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
	@${ECHO}
	@${ECHO} "The following options may be configured interactively:"
	@${ECHO} "   WITH_PAM              PAM authentication for vtysh"
	@${ECHO} "   WITH_OSPF_NSSA        NSSA support (RFC1587)"
	@${ECHO} "   WITH_OSPF_OPAQUE_LSA  OSPF Opaque-LSA with OSPFAPI support (RFC2370)"
	@${ECHO} "   WITH_RTADV            IPv6 Router Advertisements"
	@${ECHO} "   WITH_SNMP             SNMP support"
	@${ECHO} "   WITH_TCPSOCKETS       Use TCP/IP sockets for protocol daemons"
	@${ECHO} "   WITH_DLMALLOC         Use dlmalloc (makes bgpd much faster)"
	@${ECHO} "   WITH_NO_BGP_ANNOUNCE  Turn off BGP route announcement"

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

.include <bsd.port.post.mk>
