# New ports collection makefile for:	hostapd
# Date created:		7 December 2004
# Whom:			sam
#
# $FreeBSD$
#

PORTNAME=	hostapd
PORTVERSION=	0.3.0
CATEGORIES=	security
MASTER_SITES=	http://hostap.epitest.fi/releases/
DISTNAME=	hostapd-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Authenticator (server) for WPA/802.1x protocols

BUILD_DEPENDS=	${LOCALBASE}/lib/libdnet.a:${PORTSDIR}/net/libdnet

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_GMAKE=	yes

post-extract:
	@${CP} ${FILESDIR}/config.bsd ${WRKSRC}/.config

.include <bsd.port.mk>
