# Created by: Lev Walkin <vlm@lionet.info>
# $FreeBSD$

PORTNAME=	ipcad
PORTVERSION=	3.7.3
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		http://ipcad.sourceforge.net/ \
		http://lionet.info/soft/

MAINTAINER=	vlm@lionet.info
COMMENT=	IP accounting daemon with Cisco-like RSH and NetFlow export

USE_RC_SUBR=	ipcad
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g; \
		s|pthread_detach|pthread_create|g'\
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ipcad
	${INSTALL_MAN} ${WRKSRC}/ipcad.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/ipcad.conf.5 ${STAGEDIR}${MANPREFIX}/man/man5

.include <bsd.port.mk>
