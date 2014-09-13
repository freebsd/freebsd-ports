# Created by: Dima Sivachenko
# $FreeBSD$

PORTNAME=	xferstats
PORTVERSION=	2.16
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.wu-ftpd.org/pub/support/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Compiles information about file transfers from logfiles

USE_GNOME=	glib12
GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xferstats ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xferstats.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/xferstats.cfg \
		${STAGEDIR}${PREFIX}/etc/xferstats.cfg.sample

.include <bsd.port.mk>
