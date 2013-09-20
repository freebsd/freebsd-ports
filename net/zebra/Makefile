# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	zebra
PORTVERSION=	0.95a
PORTREVISION=	2
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.pop-pr.rnp.br/pub/GNU/ftp.zebra.org/zebra/ \
		ftp://ftp.ripe.net/mirrors/sites/ftp.zebra.org/pub/zebra/ \
		http://ftp.sunet.se/pub/network/zebra/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free RIPv1, RIPv2, OSPFv2, BGP4 route software (server/reflector)

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

CONFLICTS=	openbgpd-[0-9]* quagga-[0-9]* quagga-re-[0-9]* openospfd-[0-9]*

SUB_FILES=	pkg-message zebractl
SUB_LIST=	BGPDARGS=${BGPDARGS} \
		OSPFDARGS=${OSPFDARGS} \
		OSPF6DARGS=${OSPFDARGS} \
		RIPDARGS=${RIPDARGS} \
		RIPNGDARGS=${RIPNGDARGS} \
		ZEBRAARGS=${ZEBRAARGS}
USE_SUBMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/zebra

SCRIPTS_ENV=	WRKDIRPREFIX=${WRKDIRPREFIX}

OPTIONS_DEFINE=	IPV6 PAM OSPFNSSA SNMP TCPZEBRA BGPD OSPF6D OSPFD RIPD RIPNGD VTYSH

PAM_DESC=	PAM authentication for vtysh
OSPFNSSA_DESC=	undergoing NSSA feature
TCPZEBRA_DESC=	TCP/IP socket connection
BGPD_DESC=	BGPD support
OSPF6D_DESC=	OSPF6D support
OSPFD_DESC=	OSPFD support
RIPD_DESC=	RIPD support
RIPNGD_DESC=	RIPNGD support
VTYSH_DESC=	VTYSH support

OPTIONS_DEFAULT=	IPV6 BGPD OSPF6D OSPFD RIPD RIPNGD VTYSH
NO_OPTIONS_SORT=	yes

MAN1=		vtysh.1
MAN8=		bgpd.8 ospf6d.8 ospfd.8 ripd.8 ripngd.8 zebra.8
INFO=		zebra

BGPDARGS?=	-d
OSPFDARGS?=	-d
OSPF6DARGS?=	-d
RIPDARGS?=	-d
RIPNGDARGS?=	-d
ZEBRAARGS?=	-d

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MIPV6)
CONFIGURE_ARGS+=--disable-ipv6
WITHOUT_OSPF6D=	yes
WITHOUT_RIPNGD=	yes
.endif

.if ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=--with-libpam
.endif

.if ${PORT_OPTIONS:MOSPFNSSA}
CONFIGURE_ARGS+=--enable-nssa
.endif

.if ${PORT_OPTIONS:MSNMP}
CONFIGURE_ARGS+=--enable-snmp
LIB_DEPENDS+=	snmp:${PORTSDIR}/net-mgmt/net-snmp
.endif

.if ${PORT_OPTIONS:MTCPZEBRA}
CONFIGURE_ARGS+=--enable-tcp-zebra
.endif

.if ${PORT_OPTIONS:MBGPD}
PLIST_SUB+=	BGPD=""
.else
CONFIGURE_ARGS+=--disable-bgpd
PLIST_SUB+=	BGPD="@comment "
.endif

.if ${PORT_OPTIONS:MOSPF6D}
PLIST_SUB+=	OSPF6D=""
.else
CONFIGURE_ARGS+=--disable-ospf6d
PLIST_SUB+=	OSPF6D="@comment "
.endif

.if ${PORT_OPTIONS:MOSPFD}
PLIST_SUB+=	OSPF6D=""
PLIST_SUB+=	OSPFD=""
.else
CONFIGURE_ARGS+=--disable-ospfd
PLIST_SUB+=	OSPFD="@comment "
.endif

.if ${PORT_OPTIONS:MRIPD}
PLIST_SUB+=	RIPD=""
.else
CONFIGURE_ARGS+=--disable-ripd
PLIST_SUB+=	RIPD="@comment "
.endif

.if ${PORT_OPTIONS:MRIPNGD}
PLIST_SUB+=	RIPNGD=""
.else
CONFIGURE_ARGS+=--disable-ripngd
PLIST_SUB+=	RIPNGD="@comment "
.endif

.if ${PORT_OPTIONS:MVTYSH}
PLIST_SUB+=	VTYSH=""
CONFIGURE_ARGS+=--enable-vtysh
.else
PLIST_SUB+=	VTYSH="@comment "
.endif

post-install:
	@( cd ${WRKSRC}/doc; ${RM} -f zebra*info*; ${MAKE} zebra.info install )
	@${ECHO_MSG} "===>     installing zebra startup file..."
	${INSTALL_SCRIPT} ${WRKDIR}/zebractl ${PREFIX}/sbin/zebractl
	@${ECHO_MSG} "done."
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
