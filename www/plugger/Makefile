# New ports collection makefile for:	plugger
# Date created:		11 Februrary 1999
# Whom:			Jay Sachs <sachs@cs.williams.edu>
#
# $FreeBSD$
#

PORTNAME=	plugger
PORTVERSION=	4.0
PORTREVISION=	1
CATEGORIES=	www audio graphics
MASTER_SITES=	http://fredrik.hubbe.net/plugger/ \
		${MASTER_SITE_NETSCAPE}
MASTER_SITE_SUBDIR=	sdk/plugin/unix
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} unix-sdk-3.0b5.tar.Z

MAINTAINER=	coop9211@uidaho.edu

RUN_DEPENDS=	${X11BASE}/bin/mozilla:${PORTSDIR}/www/mozilla \
		${X11BASE}/bin/xanim:${PORTSDIR}/graphics/xanim \
		${LOCALBASE}/bin/timidity:${PORTSDIR}/audio/timidity++ \
		${LOCALBASE}/bin/mpg123:${PORTSDIR}/audio/mpg123 \
		${LOCALBASE}/bin/wavplay:${PORTSDIR}/audio/wavplay \
		${LOCALBASE}/bin/xmp:${PORTSDIR}/audio/xmp \
		${LOCALBASE}/bin/sidplay:${PORTSDIR}/audio/sidplay \
		${LOCALBASE}/bin/display:${PORTSDIR}/graphics/ImageMagick \
		${X11BASE}/bin/gqview:${PORTSDIR}/graphics/gqview \
		${X11BASE}/bin/gv:${PORTSDIR}/print/gv \
		${X11BASE}/bin/abiword:${PORTSDIR}/editors/AbiWord \
		${X11BASE}/bin/gnumeric:${PORTSDIR}/math/gnumeric \
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

.if defined(WITH_MPLAYER)
RUN_DEPENDS+=	${LOCALBASE}/bin/mplayer:${PORTSDIR}/graphics/mplayer
.endif

.if defined(WITH_MTV)
RUN_DEPENDS+=	${LOCALBASE}/bin/mtvp:${PORTSDIR}/graphics/mtv
.endif

pre-extract:
.if !defined(WITH_MPLAYER)
	@${ECHO_MSG} "Enable mplayer for AVI video by defining WITH_MPLAYER."
.endif

.if !defined(WITH_MTV)
	@${ECHO_MSG} "Enable mtvp for MPEG video by defining WITH_MTV."
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
	@${INSTALL_PROGRAM} ${WRKSRC}/plugger.so \
		${PREFIX}/lib/mozilla/plugins/npplugger.so
	@${INSTALL_MAN} ${WRKSRC}/plugger.7 ${MANPREFIX}/man/man7
	@${INSTALL_DATA} ${WRKSRC}/pluggerrc ${PREFIX}/etc/pluggerrc.sample
	@${INSTALL_DATA} -b ${WRKSRC}/pluggerrc ${PREFIX}/etc

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g'

.include <bsd.port.post.mk>
