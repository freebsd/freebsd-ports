# New ports collection makefile for:	xferstats
# Date created:         19 February 1999
# Whom:                 Dima Sivachenko
#
# $FreeBSD$
#

PORTNAME=	xferstats
PORTVERSION=	2.16
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.wu-ftpd.org/pub/support/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Compiles information about file transfers from logfiles

USE_GNOME=	glib12
GNU_CONFIGURE=	yes

MAN8=		xferstats.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xferstats ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xferstats.8 ${MAN8PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/xferstats.cfg ${PREFIX}/etc/xferstats.cfg.sample

.include <bsd.port.mk>
