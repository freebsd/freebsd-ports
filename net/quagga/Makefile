# New ports collection makefile for:    quagga
# Date created:         3 September 2003
# Whom:                 Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quagga
PORTVERSION=	0.96.2
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://quagga.net/download/

MAINTAINER=	fuzzball@ipv6peer.net
COMMENT=	Free RIPv1, RIPv2, OSPFv2, BGP4 route software (server/reflector)

CONFLICTS=	zebra-devel-* zebra-0*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WANT_AUTOCONF_VER=	253
WANT_AUTOMAKE_VER=	15
AUTOMAKE_ARGS=	-a

MAN1=		vtysh.1
MAN8=		bgpd.8 ospf6d.8 ospfd.8 ripd.8 ripngd.8 zebra.8

CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc/quagga --enable-vtysh
SCRIPTS_ENV=	WRKDIRPREFIX=${WRKDIRPREFIX}

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.if defined(ENABLE_USER)
CONFIGURE_ARGS+=--enable-user=${ENABLE_USER}
.endif
.if defined(ENABLE_GROUP)
CONFIGURE_ARGS+=--enable-group=${ENABLE_GROUP}
.endif
.if defined(ENABLE_VTY_GROUP)
CONFIGURE_ARGS+=--enable-vty-group=${ENABLE_VTY_GROUP}
.endif

pre-everything::
	@${ECHO} "============================================================="
	@${ECHO}
	@${ECHO} "You can build ${PORTNAME} with the following options:"
	@${ECHO}
	@${ECHO} "ENABLE_USER       Specify user to run Quagga suite as"
	@${ECHO} "ENABLE_GROUP      Specify group to run Quagga suite as"
	@${ECHO} "ENABLE_VTY_GROUP  Specify group for vty socket ownership"
	@${ECHO}
	@${ECHO} "The following options may be configured interactively:"
	@${ECHO} "QUAGGA_OPTIONS    Specify additional switches, including:"
	@${ECHO} "   LIBPAM           PAM authentication for vtysh"
	@${ECHO} "   OSPF_NSSA        NSSA support (RFC1587)"
	@${ECHO} "   OSPF_OPAQUE_LSA  OSPF Opaque-LSA with OSPFAPI support (RFC2370)"
	@${ECHO} "   RTADV            IPv6 Router Advertisements"
	@${ECHO} "   SNMP             SNMP support"
	@${ECHO} "   TCPSOCKETS       Use TCP/IP sockets for protocol daemons"

post-patch:
	@( cd ${PATCH_WRKSRC} && ${MV} configure.ac configure.in )

pre-configure:
.if !defined(BATCH)
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc
.endif
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOMAKE_ENV} ${ACLOCAL} )
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOHEADER_ENV} ${AUTOHEADER} \
		${AUTOHEADER_ARGS})
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOMAKE_ENV} ${AUTOMAKE} \
		${AUTOMAKE_ARGS})
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOCONF_ENV} ${AUTOCONF} \
		${AUTOCONF_ARGS})

post-install:
	@${ECHO} "===>     installing ${PORTNAME} startup file..."
	@${SED} -e "s=!!PREFIX!!=${PREFIX}=" \
		< ${FILESDIR}/zebractl.sh  \
		> ${PREFIX}/sbin/zebractl
	@${CHMOD} 555 ${PREFIX}/sbin/zebractl
	@${ECHO} "Make these entries in /etc/rc.conf to start ${PORTNAME}:"
	@${ECHO} "defaultrouter=\"NO\""
	@${ECHO} "router_enable=\"YES\""
	@${ECHO} "router=\"${PREFIX}/sbin/zebractl\""
	@${ECHO} "router_flags=\"start\""
	@${ECHO} "done."

.if !defined(BATCH)
post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc
.endif

.include <bsd.port.mk>
