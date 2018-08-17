# Created by: Craig Leres <leres@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hostapd
PORTVERSION=	2.6
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://w1.fi/releases/
PATCH_SITES=	https://w1.fi/security/2017-1/:2017_1 \
		https://w1.fi/security/2018-1/:2018_1

PATCHFILES=	rebased-v2.6-0001-hostapd-Avoid-key-reinstallation-in-FT-handshake.patch:2017_1 \
	rebased-v2.6-0002-Prevent-reinstallation-of-an-already-in-use-group-ke.patch:2017_1 \
	rebased-v2.6-0003-Extend-protection-of-GTK-IGTK-reinstallation-of-WNM-.patch:2017_1 \
	rebased-v2.6-0004-Prevent-installation-of-an-all-zero-TK.patch:2017_1 \
	rebased-v2.6-0005-Fix-PTK-rekeying-to-generate-a-new-ANonce.patch:2017_1 \
	rebased-v2.6-0006-TDLS-Reject-TPK-TK-reconfiguration.patch:2017_1 \
	rebased-v2.6-0008-FT-Do-not-allow-multiple-Reassociation-Response-fram.patch:2017_1 \
	rebased-v2.6-0001-WPA-Ignore-unauthenticated-encrypted-EAPOL-Key-data.patch:2018_1
PATCH_DIST_STRIP=	-p1

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
