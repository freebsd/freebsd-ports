# New ports collection makefile for:	xbms
# Date created:				Thu Dec 19 23:38:50 CET 2002
# Whom:					king@v2project.com
#
# $FreeBSD$
#

PORTNAME=	xbms
PORTVERSION=	0.30.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.xboxmediaplayer.de/downloads/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Xbms, the unix streaming server for xbox mediaplayer

USE_RC_SUBR=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|@@PREFIX@@|${PREFIX}|g' ${WRKSRC}/server.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xbms ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/xbms.conf ${PREFIX}/etc/xbms.conf.sample
	@if ! [ -f ${PREFIX}/etc/xbms.conf ]; then \
		${INSTALL_DATA} ${WRKSRC}/xbms.conf ${PREFIX}/etc/ ; \
	fi

.include <bsd.port.mk>
