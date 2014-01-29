# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_geoip
CATEGORIES=	www geography
PKGNAMEPREFIX=	lighttpd-
DISTNAME=	lighttpd-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	GeoIP module for lighttpd

LIB_DEPENDS=	GeoIP.5:${PORTSDIR}/net/GeoIP
BUILD_DEPENDS=	${LOCALBASE}/sbin/lighttpd:${PORTSDIR}/www/lighttpd
RUN_DEPENDS=	${LOCALBASE}/sbin/lighttpd:${PORTSDIR}/www/lighttpd

MASTERDIR=	${.CURDIR}/../lighttpd
DESCR=		${FILESDIR}/pkg-descr.${PORTNAME}
PLIST=		${FILESDIR}/pkg-plist.${PORTNAME}
LATEST_LINK=	lighttpd-${PORTNAME}

PATCH_SITES+=	${MASTER_SITE_LOCAL}
PATCHFILES+=	lighttpd-1.4.26_mod_geoip.patch.gz
PATCH_SITE_SUBDIR+=	mm

BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	${PORTNAME}.la

_BUILDING_LIGHTTPD_MODULE=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/lighttpd
	@${INSTALL_KLD} ${WRKSRC}/src/.libs/${PORTNAME}.so \
		${STAGEDIR}${PREFIX}/lib/lighttpd
	@${INSTALL_KLD} ${WRKSRC}/src/.libs/${PORTNAME}.la \
		${STAGEDIR}${PREFIX}/lib/lighttpd
	@${INSTALL_DATA} ${WRKSRC}/src/.libs/${PORTNAME}.a \
		${STAGEDIR}${PREFIX}/lib/lighttpd

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/lighttpd/conf.d
	@${INSTALL_DATA} ${WRKSRC}/doc/config/conf.d/geoip.conf \
		${STAGEDIR}${PREFIX}/etc/lighttpd/conf.d/geoip.conf.sample
.if !exists(${STAGEDIR}${PREFIX}/etc/lighttpd/conf.d/geoip.conf)
	@${INSTALL_DATA} ${WRKSRC}/doc/config/conf.d/geoip.conf \
		${STAGEDIR}${PREFIX}/etc/lighttpd/conf.d/geoip.conf.sample
.endif

.include "${MASTERDIR}/Makefile"
