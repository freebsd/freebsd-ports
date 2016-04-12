# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_geoip
CATEGORIES=	www geography
PKGNAMEPREFIX=	lighttpd-
DISTNAME=	lighttpd-${PORTVERSION}

COMMENT=	GeoIP module for lighttpd

LIB_DEPENDS=	libGeoIP.so:net/GeoIP
BUILD_DEPENDS=	${LOCALBASE}/sbin/lighttpd:www/lighttpd
RUN_DEPENDS=	${LOCALBASE}/sbin/lighttpd:www/lighttpd

MASTERDIR=	${.CURDIR}/../lighttpd
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

PATCH_SITES+=	https://raw.githubusercontent.com/pkubaj/lighttpd-mod_geoip/master/
PATCHFILES+=	lighttpd-1.4.26_mod_geoip.patch

BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	${PORTNAME}.la

_BUILDING_LIGHTTPD_MODULE=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/lighttpd
	@${INSTALL_LIB} ${WRKSRC}/src/.libs/${PORTNAME}.so \
		${STAGEDIR}${PREFIX}/lib/lighttpd
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/lighttpd/conf.d
	@${INSTALL_DATA} ${WRKSRC}/doc/config/conf.d/geoip.conf \
		${STAGEDIR}${PREFIX}/etc/lighttpd/conf.d/geoip.conf.sample

.include "${MASTERDIR}/Makefile"
