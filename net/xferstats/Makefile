# New ports collection makefile for:	xferstats
# Version required:	2.13
# Date created:         19 February 1999
# Whom:                 Dima Sivachenko
#
# $Id: Makefile,v 1.3 1999/03/08 16:57:45 foxfair Exp $
#

DISTNAME=	xferstats-2.14
CATEGORIES=	net
MASTER_SITES=	http://xferstats.off.net/download/xferstats-2.00/ \
		ftp://xferstats.off.net/pub/xferstats/xferstats-2.00/ \
		ftp://ftp.gpad.ac.ru/pub/FreeBSD/distfiles/

MAINTAINER=	dima@Chg.RU

LIB_DEPENDS=	glib12.2:${PORTSDIR}/devel/glib12

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

WRKSRC=		${WRKDIR}/xferstats
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}"

MAN8=		xferstats.8

do-install:
		@ ${INSTALL_PROGRAM} ${WRKSRC}/xferstats ${PREFIX}/bin
		@ ${INSTALL_MAN} ${WRKSRC}/xferstats.8 ${MAN8PREFIX}/man/man8
		@ ${INSTALL_DATA} ${WRKSRC}/xferstats.cfg ${PREFIX}/etc/xferstats.cfg.sample

.include <bsd.port.mk>
