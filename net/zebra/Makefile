# New ports collection makefile for:	zebra
# Date created:		So  31 Mai 1998 11:00:30 CEST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	zebra
PORTVERSION=	0.91a
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.zebra.org/pub/zebra/

MAINTAINER=	andreas@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc/zebra

MAN1=		vtysh.1
MAN8=		bgpd.8 ospf6d.8 ospfd.8 ripd.8 ripngd.8 zebra.8

.if !defined(BATCH)
pre-configure:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
PLIST:=		${WRKDIR}/PLIST
pre-install:
	@${CAT} ${PKGDIR}/pkg-plist.v6 ${PKGDIR}/pkg-plist > ${PLIST}
.else
CONFIGURE_ARGS+=--disable-ospf6d --disable-ripngd
.endif

post-install:
	@( cd ${WRKSRC}/doc; rm -f zebra*info*; ${MAKE} zebra.info install )
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

.include <bsd.port.post.mk>
