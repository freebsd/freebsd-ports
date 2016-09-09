# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ipcalc
PORTVERSION=	0.1.8
CATEGORIES=	net-mgmt
PKGNAMEPREFIX=	gnu-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Modern network address calculation tool for IPv4 and IPv6

LICENSE=	GPLv2

CONFLICTS_INSTALL=	ipcalc-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	nmav

OPTIONS_DEFINE=	GEOIP
OPTIONS_DEFAULT=GEOIP

GEOIP_LIB_DEPENDS=	libGeoIP.so:net/GeoIP

CFLAGS+=	-I${LOCALBASE}/include \
		-DLIBPATH="\"${LOCALBASE}/lib\"" \
		-DVERSION="\"${PORTVERSION}\""

GEOIP_CFLAGS+=	-DUSE_DYN_GEOIP -DUSE_GEOIP

PLIST_FILES=	bin/ipcalc man/man1/ipcalc.1.gz

do-build:
	${CC} ${CFLAGS} \
		${WRKSRC}/ipcalc.c \
		${WRKSRC}/ipcalc-geoip.c \
		${WRKSRC}/ipcalc-reverse.c \
			-o ${WRKSRC}/ipcalc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
