# New ports collection makefile for:	zebra-devel
# Date created:		Fri  20 Jun 2003 15:57:48 EEST
# Whom:			Alexandr Kovalenko <never@nevermind.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	zebra
PORTVERSION=	${ZEBRAVERSION}.${ZEBRADATE}
PORTREVISION?=	0
CATEGORIES=	net ipv6
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp7.ua.freebsd.org/pub/local-distfiles/ \
		http://uafug.org.ua/~never/zebra-devel/
MASTER_SITE_SUBDIR=	osa

MAINTAINER=	never@nevermind.kiev.ua
COMMENT=	Free RIPv1, RIPv2, OSPFv2, BGP4 route software (server/reflector)

ZEBRAVERSION=	0.94
ZEBRADATE=	20030620

WRKSRC=		${WRKDIR}/${PORTNAME}-${ZEBRAVERSION}

USE_SUBMAKE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc/zebra
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

.if !defined(BATCH)
pre-configure:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
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
