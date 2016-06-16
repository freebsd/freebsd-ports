# Created by: Craig Leres <leres@ee.lbl.gov>
# $FreeBSD$

PORTNAME=	hostapd
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://w1.fi/releases/

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	IEEE 802.11 AP, IEEE 802.1X/WPA/WPA2/EAP/RADIUS Authenticator

LICENSE=	BSD3CLAUSE

USES=		cpe gmake
CPE_VENDOR=	w1.f1
USE_OPENSSL=	yes
BUILD_WRKSRC=	${WRKSRC}/hostapd

PLIST_FILES=	sbin/hostapd sbin/hostapd_cli man/man1/hostapd_cli.1.gz \
		man/man8/hostapd.8.gz

OPTIONS_DEFINE=	PORTS_SSL

PORTS_SSL_DESC= Build with OpenSSL from ports (instead of base system)

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPORTS_SSL}
.if ${SSL_DEFAULT} == base
IGNORE=		the PORTS_SSL option not allowed when using SSL from base
.endif
CONFIGURE_ARGS+= --with-ssl-dir=${PREFIX}
.else
.if ${SSL_DEFAULT} != base
IGNORE=		the PORTS_SSL option is required when using SSL from ports
.endif
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

.include <bsd.port.post.mk>
