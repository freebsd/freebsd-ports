# New ports collection makefile for:    quagga
# Date created:         3 September 2003
# Whom:                 Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quagga
PORTVERSION=	0.99.14
PORTREVISION=	3
CATEGORIES=	net ipv6
MASTER_SITES=	http://quagga.net/download/ \
		http://www.ru.quagga.net/download/ \
		http://www.de.quagga.net/download/ \
		http://www.us.quagga.net/download/ \
		http://www.us2.quagga.net/download/ \
		http://www.au.quagga.net/download/

PATCH_SITES=	http://quagga.net/

MAINTAINER=	boris@tagnet.ru
COMMENT=	Free RIPv1, RIPv2, OSPFv2, BGP4, IS-IS route software

CONFLICTS=	openbgpd-[0-9]* zebra-0*

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=		yes
USE_LDCONFIG=		yes
USE_PERL5_BUILD=	yes
BUILD_DEPENDS+=		gawk:${PORTSDIR}/lang/gawk

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
		DLMALLOC	"Use dlmalloc (makes bgpd much faster)" off

.include <bsd.port.pre.mk>

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=--includedir=${PREFIX}/include --enable-exampledir=${PREFIX}/share/examples/quagga --enable-pidfile-mask=0644
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		LIBTOOL=${LIBTOOL} LIBTOOLIZE=${LIBTOOLIZE} \
		LIBTOOL_VERSION=${LIBTOOL_VERSION}

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
