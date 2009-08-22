# New ports collection makefile for:	ipcad
# Date created:				15 April 2001
# Whom:					Lev Walkin <vlm@lionet.info>
#
# $FreeBSD$
#

PORTNAME=	ipcad
PORTVERSION=	3.7.3
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		http://ipcad.sourceforge.net/ \
		http://lionet.info/soft/

MAINTAINER=	vlm@lionet.info
COMMENT=	IP accounting daemon with Cisco-like RSH and NetFlow export

USE_RC_SUBR=	ipcad
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

MANCOMPRESSED=	no
MAN5=		ipcad.conf.5
MAN8=		ipcad.8

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g ; \
		s|/usr/local|${PREFIX}|g; s|pthread_detach|pthread_create|g'\
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/ipcad
	${INSTALL_MAN} ${WRKSRC}/ipcad.8 ${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/ipcad.conf.5 ${MANPREFIX}/man/man5
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
