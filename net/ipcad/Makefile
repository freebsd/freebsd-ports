# New ports collection makefile for:	ipcad
# Date created:				15 April 2001
# Whom:					Lev Walkin <vlm@spelio.net.ru>
#
# $FreeBSD$
#

PORTNAME=	ipcad
PORTVERSION=	2.8.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.spelio.net.ru/soft/

MAINTAINER=	vlm@spelio.net.ru
COMMENT=	IP accounting daemon with Cisco-like ip accounting export

MANCOMPRESSED=	no
MAN5=	ipcad.conf.5
MAN8=	ipcad.8

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/ipcad
	@${SED} -e "s=!!PREFIX!!=${PREFIX}=g" \
		< ${FILESDIR}/ipcad.sh.tmpl \
		> ${PREFIX}/etc/rc.d/ipcad.sh
	@${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/etc/rc.d/ipcad.sh
	${INSTALL_MAN} ${WRKSRC}/ipcad.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/ipcad.conf.5 ${PREFIX}/man/man5
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
