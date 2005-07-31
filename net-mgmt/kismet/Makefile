# New ports collection makefile for:	kismet
# Date created:			3 May 2004
# Whom:					Thomas Spreng <spreng@socket.ch>
#
# $FreeBSD$
#

PORTNAME=	kismet
PORTVERSION=	200507.r1a
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.kismetwireless.net/code/
DISTNAME=	kismet-2005-07-R1a

MAINTAINER=	eol1@yahoo.com
COMMENT=	802.11 layer2 wireless network detector, sniffer, and IDS

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+=	--enable-syspcap

.ifdef DISABLE_CURSES
CONFIGURE_ARGS+=	--disable-curses
.endif

.ifdef DISABLE_PANEL
CONFIGURE_ARGS+=	--disable-panel
.endif

.ifdef DISABLE_SETUID
CONFIGURE_ARGS+=	--disable-setuid
.endif

MAN1=		kismet.1 kismet_drone.1
MAN5=		kismet.conf.5 kismet_drone.conf.5 kismet_ui.conf.5

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502000
BROKEN=		"Does not compile on FreeBSD ${OSVERSION}"
.endif

pre-fetch:
	@${ECHO_MSG} ""
.ifndef DISABLE_CURSES
	@${ECHO_MSG} " define DISABLE_CURSES to build without ncurses interface"
.endif
.ifndef DISABLE_PANEL
	@${ECHO_MSG} " define DISABLE_PANEL to build without libpanel interface"
.endif
.ifndef DISABLE_SETUID
	@${ECHO_MSG} " define DISABLE_SETUID to disable setuid/privdrop ability (not reccomended)"
.endif
	@${ECHO_MSG} ""
	@${TRUE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/kismet.conf ${PREFIX}/etc/kismet.conf.sample
	${INSTALL_DATA} ${WRKSRC}/conf/kismet_drone.conf ${PREFIX}/etc/kismet_drone.conf.sample
	${INSTALL_DATA} ${WRKSRC}/conf/kismet_ui.conf ${PREFIX}/etc/kismet_ui.conf.sample

.include <bsd.port.post.mk>
