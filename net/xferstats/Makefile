# New ports collection makefile for:	xferstats
# Version required:	2.13
# Date created:         19 February 1999
# Whom:                 Dima Sivachenko
#
# $Id: Makefile,v 1.1.1.1 1999/02/22 22:45:12 billf Exp $
#

DISTNAME=	xferstats-2.13
CATEGORIES=	net
MASTER_SITES=	http://xferstats.off.net/download/xferstats-2.00/ \
		ftp://xferstats.off.net/pub/xferstats/xferstats-2.00/ \
		ftp://ftp.gpad.ac.ru/pub/FreeBSD/distfiles/

MAINTAINER=	dima@Chg.RU

LIB_DEPENDS=	glib11.0:${PORTSDIR}/devel/glib11

WRKSRC=		${WRKDIR}/xferstats
GNU_CONFIGURE=	yes
MAN8=		xferstats.8

do-install:

		@ ${INSTALL_PROGRAM} ${WRKSRC}/xferstats ${PREFIX}/bin
		@ ${INSTALL_MAN} ${WRKSRC}/xferstats.8 ${MAN8PREFIX}/man/man8
		@ ${INSTALL_DATA} ${WRKSRC}/xferstats.cfg ${PREFIX}/etc/xferstats.cfg.sample

.include <bsd.port.mk>
