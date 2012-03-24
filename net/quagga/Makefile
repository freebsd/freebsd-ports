# New ports collection makefile for:    quagga
# Date created:         3 September 2003
# Whom:                 Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quagga
PORTVERSION=	0.99.20.1
CATEGORIES=	net ipv6
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	quagga

PATCH_SITES=	http://quagga.net/

MAINTAINER=	boris@tagnet.ru
COMMENT=	Free RIPv1, RIPv2, OSPFv2, BGP4, IS-IS route software

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	openbgpd-[0-9]* zebra-0*

USE_AUTOTOOLS=	libtool autoheader aclocal
ACLOCAL_ARGS=	-I${LOCALBASE}/share/aclocal
BUILD_DEPENDS+=	gawk:${PORTSDIR}/lang/gawk
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PERL5_BUILD=yes
FETCH_ARGS=	-Fpr

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
LIB_DEPENDS+=dlmalloc.2:${PORTSDIR}/devel/libdlmalloc
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
	@${MKDIR} ${LOCALSTATE_DIR}
	@${CHOWN} -R ${ENABLE_USER}:${ENABLE_GROUP} ${LOCALSTATE_DIR} \
		${SYSCONF_DIR}
	@${CAT} ${PKGMESSAGE}

.if !defined(BATCH)
post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc
.endif

.include <bsd.port.post.mk>
