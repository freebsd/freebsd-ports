# New ports collection makefile for:	zebra
# Date created:		So  31 Mai 1998 11:00:30 CEST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	zebra
PORTVERSION=	0.84b
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.zebra.org/pub/zebra/
# you might need debugging, it's a developer release !
#CFLAGS+=	-g

MAINTAINER=	andreas@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc/zebra

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
PLIST:=         ${WRKDIR}/PLIST
pre-install:
	@${CAT} ${PKGDIR}/PLIST.v6 > ${PLIST}
	@${CAT} ${PKGDIR}/PLIST >> ${PLIST}
.else
CONFIGURE_ARGS+=--disable-ospf6d --disable-ripngd
.endif

post-install:
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
