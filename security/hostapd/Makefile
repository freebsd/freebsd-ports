# New ports collection makefile for:	hostapd
# Date created:		7 December 2004
# Whom:			sam
#
# $FreeBSD$
#

PORTNAME=	hostapd
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://hostap.epitest.fi/releases/
DISTNAME=	hostapd-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Authenticator (server) for WPA/802.1x protocols

LIB_DEPENDS=	dnet.1:${PORTSDIR}/net/libdnet

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_GMAKE=	yes

post-extract:
	@${CP} ${FILESDIR}/config.bsd ${WRKSRC}/.config

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600007
IGNORE=is not supported on FreeBSD < 6.0
.endif

.include <bsd.port.post.mk>
