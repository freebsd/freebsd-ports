# New ports collection makefile for:	wpa_supplicant
# Date created:		7 December 2004
# Whom:			sam
#
# $FreeBSD$
#

PORTNAME=	wpa_suplicant
PORTVERSION=	0.3.0
CATEGORIES=	security
MASTER_SITES=	http://hostap.epitest.fi/releases/
DISTNAME=	wpa_supplicant-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Supplicant (client) for WPA/802.1x protocols

BUILD_DEPENDS=	${LOCALBASE}/lib/libdnet.a:${PORTSDIR}/net/libdnet

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_GMAKE=	yes

post-extract:
	@${CP} ${FILESDIR}/config.bsd ${WRKSRC}/.config

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600007
IGNORE=is not supported on FreeBSD < 6.0
.endif

.include <bsd.port.post.mk>
