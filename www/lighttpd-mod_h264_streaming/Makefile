# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_h264_streaming
CATEGORIES=	www multimedia
PKGNAMEPREFIX=	lighttpd-
DISTNAME=	lighttpd-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	H264 streaming module for lighttpd

BUILD_DEPENDS=	${LOCALBASE}/sbin/lighttpd:${PORTSDIR}/www/lighttpd
RUN_DEPENDS=	${LOCALBASE}/sbin/lighttpd:${PORTSDIR}/www/lighttpd

LICENSE=	CCPL.BY-NC-SA.30
LICENSE_NAME=	Creative Commons Attribution-NonCommercial-ShareAlike 3.0 \
		Unported License
LICENSE_FILE=	${FILESDIR}/COPYING.mod_h264_streaming
LICENSE_DISTFILES=	${PATCHFILES}
LICENSE_PERMS=	dist-mirror pkg-mirror

MASTERDIR=	${.CURDIR}/../lighttpd
PLIST=		${FILESDIR}/pkg-plist.${PORTNAME}
DESCR=		${FILESDIR}/pkg-descr.${PORTNAME}
LATEST_LINK=	lighttpd-${PORTNAME}

MANUAL_PACKAGE_BUILD=	free for non-commercial use only

PATCH_SITES+=	${MASTER_SITE_LOCAL}
PATCHFILES+=	lighttpd-1.4.26_mod_h264_streaming-2.2.9.patch.gz
PATCH_SITE_SUBDIR+=	mm

BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	${PORTNAME}.la

_BUILDING_LIGHTTPD_MODULE=	yes

NO_STAGE=	yes
do-install:
	@${INSTALL_KLD} ${WRKSRC}/src/.libs/${PORTNAME}.so \
		${LOCALBASE}/lib/lighttpd
	@${INSTALL_KLD} ${WRKSRC}/src/.libs/${PORTNAME}.la \
		${LOCALBASE}/lib/lighttpd
	@${INSTALL_DATA} ${WRKSRC}/src/.libs/${PORTNAME}.a \
		${LOCALBASE}/lib/lighttpd

post-install:
	@${INSTALL_DATA} ${FILESDIR}/h264_streaming.conf \
		${PREFIX}/etc/lighttpd/conf.d/h264_streaming.conf.sample
.if !exists(${PREFIX}/etc/lighttpd/conf.d/h264_streaming.conf)
	@${INSTALL_DATA} ${FILESDIR}/h264_streaming.conf \
		${PREFIX}/etc/lighttpd/conf.d/h264_streaming.conf
.endif

.include "${MASTERDIR}/Makefile"
