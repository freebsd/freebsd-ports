# New ports collection makefile for:	plugger
# Date created:		11 Februrary 1999
# Whom:			Jay Sachs <sachs@cs.williams.edu>
#
# $FreeBSD$
#

PORTNAME=	plugger
PORTVERSION=	3.3
PORTREVISION=	2
CATEGORIES=	www audio graphics
MASTER_SITES=	http://fredrik.hubbe.net/plugger/ \
		ftp://ftp.netscape.com/pub/sdk/plugin/unix/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} unix-sdk-3.0b5.tar.Z

MAINTAINER=	jmcoopr@webmail.bmi.net

RUN_DEPENDS=	${X11BASE}/bin/mozilla:${PORTSDIR}/www/mozilla \
		${LOCALBASE}/bin/mpg123:${PORTSDIR}/audio/mpg123 \
		${LOCALBASE}/bin/nspmod:${PORTSDIR}/audio/nspmod \
		${LOCALBASE}/bin/sidplay:${PORTSDIR}/audio/sidplay \
		${LOCALBASE}/bin/splay:${PORTSDIR}/audio/splay \
		${LOCALBASE}/bin/timidity:${PORTSDIR}/audio/timidity++ \
		${LOCALBASE}/bin/wavplay:${PORTSDIR}/audio/wavplay \
		${LOCALBASE}/bin/mtvp:${PORTSDIR}/graphics/mtv \
		${X11BASE}/bin/xanim:${PORTSDIR}/graphics/xanim \
		${LOCALBASE}/bin/xloadimage:${PORTSDIR}/x11/xloadimage

USE_X_PREFIX=	yes

MAN7=		plugger.7
MANCOMPRESSED=	no
ALL_TARGET=	freebsd-elf

post-patch:
	@${MV} ${WRKSRC}/plugger.c ${WRKSRC}/plugger.c.orig
	@${SED} \
	  -e 's#/usr/local/#${PREFIX}/#' \
	  ${WRKSRC}/plugger.c.orig > ${WRKSRC}/plugger.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/plugger.so \
		${PREFIX}/lib/mozilla/plugins/npplugger.so
	@${INSTALL_MAN} ${WRKSRC}/plugger.7 ${MANPREFIX}/man/man7
	@${INSTALL_DATA} ${WRKSRC}/pluggerrc ${PREFIX}/etc/pluggerrc.sample
	@${INSTALL_DATA} -b ${WRKSRC}/pluggerrc ${PREFIX}/etc

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's:/usr/X11R6:${PREFIX}:'

.include <bsd.port.mk>
