# New ports collection makefile for:	zebra-pj
# Date created:		Tue May 13 12:12:11 CEST 2003
# Whom:			sumikawa
#
# $FreeBSD$
#

PORTNAME=	zebra-pj
PORTVERSION=	20030722
CATEGORIES=	net ipv6
MASTER_SITES=	http://zebra.dishone.st/snapshots/cvs/
DISTNAME=	${PORTNAME}-${ZEBRAVER}-${PORTVERSION}

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=		Patched Zebra

BUILD_DEPENDS=	automake:${PORTSDIR}/devel/automake \
		autoheader:${PORTSDIR}/devel/autoconf253

USE_SUBMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc/zebra --enable-vtysh
SCRIPTS_ENV=	WRKDIRPREFIX=${WRKDIRPREFIX}
WRKSRC=		${WRKDIR}/zebra-${ZEBRAVER}

ZEBRAVER=	0.94

MAN1=		vtysh.1
MAN8=		bgpd.8 ospf6d.8 ospfd.8 ripd.8 ripngd.8 zebra.8

pre-configure:
	@( cd ${WRKSRC}; ${SH} update-autotools )
.if !defined(BATCH)
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif
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

.include <bsd.port.mk>
