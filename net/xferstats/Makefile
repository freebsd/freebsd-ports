# New ports collection makefile for:	xferstats
# Date created:         19 February 1999
# Whom:                 Dima Sivachenko
#
# $FreeBSD$
#

PORTNAME=	xferstats
PORTVERSION=	2.14
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.wu-ftpd.org/pub/support/	\
		ftp://ftp.gpad.ac.ru/pub/FreeBSD/distfiles/

MAINTAINER=	demon@FreeBSD.org

WRKSRC=		${WRKDIR}/xferstats

USE_GLIB=	yes
GNU_CONFIGURE=	yes

MAN8=		xferstats.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xferstats ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xferstats.8 ${MAN8PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/xferstats.cfg ${PREFIX}/etc/xferstats.cfg.sample

.include <bsd.port.mk>
