# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_h264_streaming
CATEGORIES=	www multimedia
PKGNAMEPREFIX=	lighttpd-
DISTNAME=	lighttpd-${PORTVERSION}

COMMENT=	H264 streaming module for lighttpd

BUILD_DEPENDS=	${LOCALBASE}/sbin/lighttpd:www/lighttpd
RUN_DEPENDS=	${LOCALBASE}/sbin/lighttpd:www/lighttpd

LICENSE=	CCPL.BY-NC-SA.30
LICENSE_NAME=	Creative Commons Attribution-NonCommercial-ShareAlike 3.0 \
		Unported License
LICENSE_FILE=	${FILESDIR}/COPYING.mod_h264_streaming
LICENSE_DISTFILES=	${PATCHFILES}
LICENSE_PERMS=	dist-mirror pkg-mirror

MASTERDIR=	${.CURDIR}/../lighttpd
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

MANUAL_PACKAGE_BUILD=	free for non-commercial use only

PATCH_SITES+=	https://raw.githubusercontent.com/pkubaj/lighttpd-mod_h264_streaming/master/
PATCHFILES+=	lighttpd-1.4.26_mod_h264_streaming-2.2.9.patch

BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	${PORTNAME}.la

_BUILDING_LIGHTTPD_MODULE=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/lighttpd
	@${INSTALL_LIB} ${WRKSRC}/src/.libs/${PORTNAME}.so \
		${STAGEDIR}${PREFIX}/lib/lighttpd
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/lighttpd/conf.d
	@${INSTALL_DATA} ${FILESDIR}/h264_streaming.conf \
		${STAGEDIR}${PREFIX}/etc/lighttpd/conf.d/h264_streaming.conf.sample

.include "${MASTERDIR}/Makefile"
