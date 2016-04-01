# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	zebra
PORTVERSION=	0.95a
PORTREVISION=	5
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.pop-pr.rnp.br/pub/GNU/ftp.zebra.org/zebra/ \
		ftp://ftp.ripe.net/mirrors/sites/ftp.zebra.org/pub/zebra/ \
		http://ftp.sunet.se/pub/network/zebra/

MAINTAINER=	bdrewery@FreeBSD.org
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
USES=		cpe readline
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/zebra
CPU_VENDOR=	gnu

PORTSCOUT=	ignore:1

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}"

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
OPTIONS_SUB=	yes
NO_OPTIONS_SORT=	yes

PAM_CONFIGURE_WITH=		pam
OSPFNSSA_CONFIGURE_ENABLE=	nssa
SNMP_CONFIGURE_ENABLE=		snmp
SNMP_LIB_DEPENDS+=		libnetsnmp.so:net-mgmt/net-snmp
TCPZEBRA_CONFIGURE_ENABLE=	tcp-zebra
BGPD_CONFIGURE_ENABLE=		bgpd
OSPF6D_CONFIGURE_ENABLE=	ospf6d
OSPFD_CONFIGURE_ENABLE=		ospfd
RIPD_CONFIGURE_ENABLE=		ripd
RIPNGD_CONFIGURE_ENABLE=	ripngd
VTYSH_CONFIGURE_ENABLE=		vtysh
IPV6_CONFIGURE_ENABLE=		ipv6

INFO=		zebra

BGPDARGS?=	-d
OSPFDARGS?=	-d
OSPF6DARGS?=	-d
RIPDARGS?=	-d
RIPNGDARGS?=	-d
ZEBRAARGS?=	-d

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MIPV6} && ${PORT_OPTIONS:MOSPF6D}
IGNORE=		OSPF6D requires IPV6 option
.endif
.if !${PORT_OPTIONS:MIPV6} && ${PORT_OPTIONS:MRIPNGD}
IGNORE=		RIPNGD requires IPV6 option
.endif

post-install:
	@( cd ${WRKSRC}/doc; ${RM} -f zebra*info*; \
	   ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} zebra.info install )
	@${ECHO_MSG} "===>     installing zebra startup file..."
	${INSTALL_SCRIPT} ${WRKDIR}/zebractl ${STAGEDIR}${PREFIX}/sbin/zebractl
	@${ECHO_MSG} "done."

.include <bsd.port.mk>
