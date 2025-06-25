PORTNAME=	hostapd
PORTVERSION=	${COMMIT_DATE}
CATEGORIES=	net
PKGNAMESUFFIX=	-devel

MAINTAINER=	cy@FreeBSD.org
COMMENT=	IEEE 802.11 AP, IEEE 802.1X/WPA/WPA2/EAP/RADIUS Authenticator
WWW=		https://w1.fi/hostapd/

USE_GITHUB=	yes
GH_ACCOUNT=	cschuber
GH_PROJECT=	hostap
GH_TAGNAME=	0b60826a6
COMMIT_DATE=	2025.06.25

LICENSE=	BSD3CLAUSE

USES=		cpe gmake ssl
CPE_VENDOR=	w1.fi
BUILD_WRKSRC=	${WRKSRC}/hostapd
CFLAGS+=	-Wno-incompatible-function-pointer-types
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

PLIST_FILES=	sbin/hostapd sbin/hostapd_cli share/man/man1/hostapd_cli.1.gz \
		share/man/man8/hostapd.8.gz
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
		${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/hostapd/hostapd.8 \
		${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
