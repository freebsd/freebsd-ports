# New ports collection makefile for:	mod_geoip
# Date created:			27 Aug 2010
# Whom:				Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

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
	@${INSTALL_KLD} ${WRKSRC}/src/.libs/${PORTNAME}.so \
		${LOCALBASE}/lib/lighttpd
	@${INSTALL_KLD} ${WRKSRC}/src/.libs/${PORTNAME}.la \
		${LOCALBASE}/lib/lighttpd
	@${INSTALL_DATA} ${WRKSRC}/src/.libs/${PORTNAME}.a \
		${LOCALBASE}/lib/lighttpd

post-install:
	@${INSTALL_DATA} ${WRKSRC}/doc/config/conf.d/geoip.conf \
		${PREFIX}/etc/lighttpd/conf.d/geoip.conf.sample
.if !exists(${PREFIX}/etc/lighttpd/conf.d/geoip.conf)
	@${INSTALL_DATA} ${WRKSRC}/doc/config/conf.d/geoip.conf \
		${PREFIX}/etc/lighttpd/conf.d/geoip.conf.sample
.endif

.include "${MASTERDIR}/Makefile"
