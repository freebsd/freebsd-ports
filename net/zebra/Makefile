# New ports collection makefile for:	zebra
# Date created:		So  31 Mai 1998 11:00:30 CEST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	zebra
PORTVERSION=	0.94
PORTREVISION=	2
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.zebra.org/pub/zebra/ \
		ftp://ftp.ripe.net/mirrors/sites/ftp.zebra.org/pub/zebra/ \
		ftp://ftp.sunet.se/pub/network/zebra/ \
		ftp://6bone.informatik.uni-leipzig.de/pub/ftp.zebra.org/pub/zebra/ \
		ftp://ftp.pop-pr.rnp.br/pub/GNU/ftp.zebra.org/zebra/

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=		Free RIPv1, RIPv2, OSPFv2, BGP4 route software (server/reflector)

USE_SUBMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/zebra
SCRIPTS_ENV=	WRKDIRPREFIX=${WRKDIRPREFIX}

MAN1=		vtysh.1
MAN8=		bgpd.8 ospf6d.8 ospfd.8 ripd.8 ripngd.8 zebra.8
INFO=		zebra

.if defined (WITHOUT_IPV6)
CONFIGURE_ARGS+=--disable-ipv6
WITHOUT_OSPF6D=	yes
WITHOUT_RIPNGD=	yes
.endif

.if !defined(WITHOUT_BGPD)
PLIST_SUB+=	BGPD=""
.else
CONFIGURE_ARGS+=--disable-bgpd
PLIST_SUB+=	BGPD="@comment "
.endif

.if !defined(WITHOUT_OSPF6D)
PLIST_SUB+=	OSPF6D=""
.else
CONFIGURE_ARGS+=--disable-ospf6d
PLIST_SUB+=	OSPF6D="@comment "
.endif

.if !defined(WITHOUT_OSPFD)
PLIST_SUB+=	OSPF6D=""
PLIST_SUB+=	OSPFD=""
.else
CONFIGURE_ARGS+=--disable-ospfd
PLIST_SUB+=	OSPFD="@comment "
.endif

.if !defined(WITHOUT_RIPD)
PLIST_SUB+=	RIPD=""
.else
CONFIGURE_ARGS+=--disable-ripd
PLIST_SUB+=	RIPD="@comment "
.endif

.if !defined(WITHOUT_RIPNGD)
PLIST_SUB+=	RIPNGD=""
.else
CONFIGURE_ARGS+=--disable-ripngd
PLIST_SUB+=	RIPNGD="@comment "
.endif

.if !defined(WITHOUT_VTYSH)
PLIST_SUB+=	VTYSH=""
CONFIGURE_ARGS+=--enable-vtysh
.else
PLIST_SUB+=	VTYSH="@comment "
.endif

.if !defined(BATCH)
pre-configure:
	@${RM} -f ${WRKDIR}/Makefile.inc

post-clean:
	@${RM} -f ${WRKDIR}/Makefile.inc

.if exists(${WRKDIR}/Makefile.inc)
.include "${WRKDIR}/Makefile.inc"
.endif
.endif

post-install:
	@( cd ${WRKSRC}/doc; ${RM} -f zebra*info*; ${MAKE} zebra.info install )
	@${ECHO} "===>     installing zebra startup file..."
	@${SED} -e "s=!!PREFIX!!=${PREFIX}=" \
		< ${FILESDIR}/zebractl.sh  \
		> ${PREFIX}/sbin/zebractl
	@${CHMOD} 555 ${PREFIX}/sbin/zebractl
	@${ECHO} "Make these entries in /etc/rc.conf to start zebra:"
	@${ECHO} "defaultrouter=\"NO\""
	@${ECHO} "router_enable=\"YES\""
	@${ECHO} "router=\"${PREFIX}/sbin/zebractl\""
	@${ECHO} "router_flags=\"start\""
	@${ECHO} "done."

.include <bsd.port.mk>
