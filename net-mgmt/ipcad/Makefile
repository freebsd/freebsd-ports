# New ports collection makefile for:	ipcad
# Date created:				15 April 2001
# Whom:					Lev Walkin <vlm@spelio.net.ru>
#
# $FreeBSD$
#

PORTNAME=	ipcad
PORTVERSION=	3.6.3
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} 	\
		http://ipcad.sourceforge.net/	\
		http://lionet.info/soft/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	vlm@lionet.info
COMMENT=	IP accounting daemon with Cisco-like RSH and NetFlow export modes

MANCOMPRESSED=	no
MAN5=	ipcad.conf.5
MAN8=	ipcad.8
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g ; \
		s|/usr/local|${PREFIX}|g' ${WRKSRC}/configure

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
