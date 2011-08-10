# New ports collection makefile for:	hostapd
# Date created:		05 February 2011
# Whom:			leres@ee.lbl.gov
#
# $FreeBSD$
#

PORTNAME=	hostapd
PORTVERSION=	0.7.3
CATEGORIES=	net
MASTER_SITES=	http://hostap.epitest.fi/releases/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	IEEE 802.11 AP, IEEE 802.1X/WPA/WPA2/EAP/RADIUS Authenticator

USE_GMAKE=	yes

MAN1=		hostapd_cli.1
MAN8=		hostapd.8

do-configure:
	${CP} ${FILESDIR}/config ${WRKSRC}/hostapd/.config

do-build:
	(cd ${WRKSRC}/hostapd && ${GMAKE})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hostapd/hostapd ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/hostapd/hostapd_cli ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/hostapd/${MAN1} ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/hostapd/${MAN8} ${PREFIX}/man/man8

PLIST_FILES=	sbin/hostapd \
		sbin/hostapd_cli

#MAKE_JOBS_SAFE= yes
#MANCOMPRESSED=	yes

LICENSE=	GPLv1 BSD
LICENSE_COMB=	dual

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
