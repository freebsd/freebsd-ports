# New ports collection makefile for:	plugger
# Date created:		11 Februrary 1999
# Whom:			Jay Sachs <sachs@cs.williams.edu>
#
# $FreeBSD$
#

PORTNAME=	plugger
PORTVERSION=	4.0
PORTREVISION=	4
CATEGORIES=	www audio graphics multimedia
MASTER_SITES=	http://fredrik.hubbe.net/plugger/ \
		${MASTER_SITE_NETSCAPE}
MASTER_SITE_SUBDIR=	sdk/plugin/unix
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} unix-sdk-3.0b5.tar.Z

MAINTAINER=	coop9211@uidaho.edu
COMMENT=	A multimedia front-end plugin for Mozilla or Opera

RUN_DEPENDS=	${LOCALBASE}/bin/nspptview:${PORTSDIR}/textproc/xlhtml \
		${LOCALBASE}/bin/mpg123:${PORTSDIR}/audio/mpg123 \
		${LOCALBASE}/bin/sidplay:${PORTSDIR}/audio/sidplay \
		${LOCALBASE}/bin/wavplay:${PORTSDIR}/audio/wavplay \
		${LOCALBASE}/bin/xmp:${PORTSDIR}/audio/xmp \
		${X11BASE}/bin/gqview:${PORTSDIR}/graphics/gqview \
		${LOCALBASE}/bin/display:${PORTSDIR}/graphics/ImageMagick \
		${LOCALBASE}/bin/timidity:${PORTSDIR}/audio/timidity++ \
		${X11BASE}/bin/gv:${PORTSDIR}/print/gv \
		${X11BASE}/bin/xanim:${PORTSDIR}/multimedia/xanim \
		${LOCALBASE}/bin/acroread5:${PORTSDIR}/print/acroread5

USE_X_PREFIX=	yes
USE_REINPLACE=	yes

MAN7=		plugger.7
MANCOMPRESSED=	no
ALL_TARGET=	freebsd-elf

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/mplayer)
WITH_MPLAYER =	yes
.endif

.if exists(${LOCALBASE}/bin/mtvp)
WITH_MTV =	yes
.endif

.if exists(${X11BASE}/lib/libgnomeprintui-2-2.so.0)
WITH_GNOME2 =	yes
.endif

.if defined(WITH_MPLAYER)
RUN_DEPENDS+=	${LOCALBASE}/bin/mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if defined(WITH_MTV)
RUN_DEPENDS+=	${LOCALBASE}/bin/mtvp:${PORTSDIR}/multimedia/mtv
.endif

.if defined(WITH_GNOME2)
RUN_DEPENDS+=	${X11BASE}/bin/gnumeric:${PORTSDIR}/math/gnumeric2 \
		${X11BASE}/bin/abiword:${PORTSDIR}/editors/AbiWord2
.else
RUN_DEPENDS+=	${X11BASE}/bin/gnumeric:${PORTSDIR}/math/gnumeric
.endif

pre-extract:
.if !defined(WITH_MPLAYER)
	@${ECHO_MSG} "Enable mplayer for AVI video by defining WITH_MPLAYER."
.endif

.if !defined(WITH_MTV)
	@${ECHO_MSG} "Enable mtvp for MPEG video by defining WITH_MTV."
.endif

.if !defined(WITH_GNOME2)
	@${ECHO_MSG} "Enable Gnome/2 AbiWord and Gnumeric by defining"
	@${ECHO_MSG} "WITH_GNOME2."
.endif

post-patch:
	@${MV} ${WRKSRC}/plugger.c ${WRKSRC}/plugger.c.orig
	@${SED} \
	  -e 's#/usr/local/#${PREFIX}/#' \
	  ${WRKSRC}/plugger.c.orig > ${WRKSRC}/plugger.c
# CC safeness
	@${REINPLACE_CMD} -e 's|CC=gcc|CC=${CC}|' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/plugger-${PORTVERSION} \
		${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/browser_plugins
	@${INSTALL_PROGRAM} ${WRKSRC}/plugger.so \
		${PREFIX}/lib/browser_plugins/npplugger.so
	@${INSTALL_MAN} ${WRKSRC}/plugger.7 ${MANPREFIX}/man/man7
	@${INSTALL_DATA} ${WRKSRC}/pluggerrc ${PREFIX}/etc/pluggerrc.sample
	@${INSTALL_DATA} -b ${WRKSRC}/pluggerrc ${PREFIX}/etc

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g'
.if defined(WITH_MPLAYER)
	@${CAT} ${PKGMESSAGE}-mplayer
.endif

.include <bsd.port.post.mk>
