# New ports collection makefile for:    quagga
# Date created:         3 September 2003
# Whom:                 Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quagga
PORTVERSION=	0.98.2
PORTREVISION=	2
CATEGORIES=	net ipv6
MASTER_SITES=	http://quagga.net/download/

PATCH_SITES=	http://quagga.net/

MAINTAINER=	boris@tagnet.ru
COMMENT=	Free RIPv1, RIPv2, OSPFv2, BGP4, IS-IS route software

CONFLICTS=	zebra-devel-[0-9]* zebra-0*

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_REINPLACE=		yes
INSTALLS_SHLIB=		yes
USE_AUTOCONF_VER=	259
USE_LIBTOOL_VER=	15
USE_PERL5_BUILD=	yes

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
		TCPMD5		"Use experimental MD5 patch for BGP" off

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=--includedir=${PREFIX}/include --enable-exampledir=${PREFIX}/share/examples/quagga
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

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

.if defined(WITH_ISISD) && !defined(WITHOUT_ISISD)
CONFIGURE_ARGS+=--enable-isisd
PLIST_SUB+=	ISISD_SBIN=sbin/isisd
PLIST_SUB+=	ISISD_CONF=%%EXAMPLESDIR%%/isisd.conf.sample
.else
PLIST_SUB+=	ISISD_SBIN="@comment"
PLIST_SUB+=	ISISD_CONF="@comment"
.endif
MAN8+=		isisd.8

.if defined(WITH_PAM) && !defined(WITHOUT_PAM)
CONFIGURE_ARGS+=--with-libpam
.endif

.if defined(WITH_OSPFNSSA) && !defined(WITHOUT_OSPF_NSSA)
CONFIGURE_ARGS+=--enable-nssa
.endif

.if defined(WITH_OSPF_OPAQUE_LSA) && !defined(WITHOUT_OSPF_OPAQUE_LSA)
CONFIGURE_ARGS+=--enable-opaque-lsa
PLIST_SUB+=	OSPFAPI_HEADER="include/quagga/ospfapi/ospf_apiclient.h"
PLIST_SUB+=	OSPFAPI_PATH="@dirrm include/quagga/ospfapi"
PLIST_SUB+=	OSPFAPI_LIBA="lib/libospfapiclient.a"
PLIST_SUB+=	OSPFAPI_LIBSO="lib/libospfapiclient.so"
PLIST_SUB+=	OSPFAPI_LIBSO0="lib/libospfapiclient.so.0"
PLIST_SUB+=	OSPFAPI_SBIN="sbin/ospfclient"
.else
PLIST_SUB+=	OSPFAPI_HEADER="@comment"
PLIST_SUB+=	OSPFAPI_PATH="@comment"
PLIST_SUB+=	OSPFAPI_LIBA="@comment"
PLIST_SUB+=	OSPFAPI_LIBSO="@comment"
PLIST_SUB+=	OSPFAPI_LIBSO0="@comment"
PLIST_SUB+=	OSPFAPI_SBIN="@comment"
.endif

.if defined(WITH_RTADV) && !defined(WITHOUT_RTADV)
CONFIGURE_ARGS+=--enable-rtadv
.endif

.if defined(WITH_SNMP) && !defined(WITHOUT_SNMP)
CONFIGURE_ARGS+=--enable-snmp
.if defined(WITH_SNMP_4)
LIB_DEPENDS+=snmp.4:${PORTSDIR}/net-mgmt/net-snmp4:install
.else
LIB_DEPENDS+=netsnmp.7:${PORTSDIR}/net-mgmt/net-snmp:install
.endif
.endif

.if defined(WITH_TCPMD5) && !defined(WITHOUT_TCPMD5)
.if ${OSVERSION} < 491000
BROKEN=	This version of FreeBSD does not have TCP MD5 signature support
.endif
CONFIGURE_ARGS+=--enable-tcp-signature
EXTRA_PATCHES+=${PATCHDIR}/extra-tcpmd5-patch-bgpd::bgp_network.c ${PATCHDIR}/extra-tcpmd5-patch-bgpd::bgp_vty.c ${PATCHDIR}/extra-tcpmd5-patch-bgpd::bgpd.c ${PATCHDIR}/extra-tcpmd5-patch-bgpd::bgpd.h ${PATCHDIR}/extra-tcpmd5-patch-configure.ac ${PATCHDIR}/extra-tcpmd5-patch-lib::sockopt.c ${PATCHDIR}/extra-tcpmd5-patch-lib::sockopt.h
.endif

USE_RC_SUBR=	watchquagga.sh
.if ${OSVERSION} < 500000
USE_RC_SUBR+=	quagga.sh
.else
USE_RCORDER=	quagga.sh
.endif

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
	@${ECHO} "WITH_SNMP_4       Force net-snmp 4.x to be used"
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
	@${ECHO} "   WITH_TCPMD5           Use experimental MD5 patch for BGP"

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
	@${ECHO} "Note!!! Since 0.96.4_5 port uses new id for quagga user and group."
	@${ECHO} "        So, You need to manually chown files:"
	@${ECHO} "        in ${SYSCONF_DIR}"
	@${ECHO} "        and ${LOCALSTATE_DIR}"
	@${ECHO} "        if You had never do this before. Or run"
	@${ECHO} "        make changeuser"
	@${ECHO} ""
.if defined(WITH_TCPMD5) && !defined(WITHOUT_TCPMD5)
	@${ECHO} "Note!!! To use MD5 passwords on BGP sessions, your kernel must"
	@${ECHO} "be built with the following options:"
	@${ECHO} "  options TCP_SIGNATURE"
	@${ECHO} "  options FAST_IPSEC"
	@${ECHO} "  device crypto"
	@${ECHO} "  device cryptodev"
	@${ECHO} ""
.endif
.if ${OSVERSION} < 500000
	@${ECHO} "Warning: You are running 4.x version of FreeBSD. To properly start"
	@${ECHO} "         quagga on your system please rename"
	@${ECHO} "         ${PREFIX}/etc/rc.d/quagga.sh to something like"
	@${ECHO} "         ${PREFIX}/etc/rc.d/010.quagga.sh or even You"
	@${ECHO} "         should write your own startup script and use it with"
	@${ECHO} "         router_enable=\"YES\""
	@${ECHO} "         router=\"your_startup_script_here\" in your rc.conf"
	@${ECHO} ""
.endif

.if !defined(BATCH)
post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc
.endif

changeuser:
# Recover from the problem that earlier versions of this port created the
# quagga pseudo-user with an id of 90 which is used by FireBird database
# engine. The port now uses id 101:101.
# NOTE:
# This target assumes that ENABLE_GROUP is the primary group of ENABLE_USER. If you
# have a different setup, do not run this target!
	@if [ `${ID} -u` -ne 0 ]; \
	then ${ECHO_CMD} "Sorry, you must be root to use this target."; exit 1; fi; \
	current_uid=`id -u ${ENABLE_USER}`; \
	current_gid=`pw groupshow ${ENABLE_GROUP}|cut -f 3 -d :`; \
	${ECHO_CMD} "I will remove this user:"; \
	${ID} -P $${current_uid}; \
	${ECHO_CMD} "and this group:"; \
	pw groupshow ${ENABLE_GROUP}; \
	${ECHO_CMD} "I will then re-create them with a user and group id of 101."; \
	${ECHO_CMD} "Then all files and directories under ${PREFIX} and /var that"; \
	${ECHO_CMD} "are owned by uid $${current_uid} will be chown(1)'ed."; \
	${ECHO_CMD} "After that, all files and directories that were accessible"; \
	${ECHO_CMD} "by group $${current_gid} will chgrp(1)'ed respectively."; \
	${ECHO_CMD} "Note that this assumes group '${ENABLE_GROUP}' to be the primary"; \
	${ECHO_CMD} "group of user '${ENABLE_USER}'. If you have a different setup"; \
	${ECHO_CMD} "please abort this target now. Also don't forget to write your"; \
	${ECHO_CMD} "Quagga configs right now!"; \
	read -p "Press RETURN to continue or CTRL-C to abort:" dummy ; \
	${ECHO_CMD} "OK, here we go:"; \
	${ECHO_CMD} "deleting user $${current_uid} and his primary group..."; \
	pw userdel -u $${current_uid}; \
	${ECHO_CMD} "adding user ${ENABLE_USER} with id 101..."; \
	pw groupadd -n ${ENABLE_USER} -g 101; \
	pw useradd -n ${ENABLE_GROUP} -u 101 -c "quagga route daemon pseudo-user" \
	    -d ${SYSCONF_DIR} -s /sbin/nologin -h - ; \
	${ECHO_CMD} "chown(1)'ing everything under ${PREFIX} from $${current_uid} to 101..."; \
	${FIND} -H ${PREFIX} -user $${current_uid} -exec ${CHOWN} 101 {} \; ; \
	${ECHO_CMD} "chgrp(1)'ing everything under ${PREFIX} from $${current_gid} to 100..."; \
	${FIND} -H ${PREFIX} -group $${current_gid} -exec ${CHOWN} :101 {} \; ; \
	${ECHO_CMD} "chown(1)'ing everything under /var from $${current_uid} to 101..."; \
	${FIND} -H /var -user $${current_uid} -exec ${CHOWN} 101 {} \; ; \
	${ECHO_CMD} "chgrp(1)'ing everything under /var from $${current_gid} to 101..."; \
	${FIND} -H /var -group $${current_gid} -exec ${CHOWN} :101 {} \; ; \
	${ECHO_CMD} "Finished. You must stop and then start Quagga now."

.include <bsd.port.post.mk>
