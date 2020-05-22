# Created by: Craig Leres <leres@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hostapd
PORTVERSION=	2.9
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://w1.fi/releases/

PATCH_SITES=	https://w1.fi/security/2018-1/:2018_1

MAINTAINER=	cy@FreeBSD.org
COMMENT=	IEEE 802.11 AP, IEEE 802.1X/WPA/WPA2/EAP/RADIUS Authenticator

LICENSE=	BSD3CLAUSE

USES=		cpe gmake ssl
CPE_VENDOR=	w1.f1
BUILD_WRKSRC=	${WRKSRC}/hostapd
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

PLIST_FILES=	sbin/hostapd sbin/hostapd_cli man/man1/hostapd_cli.1.gz \
		man/man8/hostapd.8.gz
.if !exists(/etc/rc.d/hostapd)
USE_RC_SUBR=	hostapd
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|@$$(E) "  CC " $$<|@$$(E) "  $$(CC) " $$<|' \
		${BUILD_WRKSRC}/Makefile
	@${SED} -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/config \
		>> ${WRKSRC}/hostapd/.config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hostapd/hostapd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/hostapd/hostapd_cli \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/hostapd/hostapd_cli.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/hostapd/hostapd.8 \
		${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
