# New ports collection makefile for:	mod_h264_streaming
# Date created:			27 Aug 2010
# Whom:				Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_h264_streaming
CATEGORIES=	www multimedia
PKGNAMEPREFIX=	lighttpd-
DISTNAME=	lighttpd-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	H264 streaming module for lighttpd

BUILD_DEPENDS=	${LOCALBASE}/sbin/lighttpd:${PORTSDIR}/www/lighttpd
RUN_DEPENDS=	${LOCALBASE}/sbin/lighttpd:${PORTSDIR}/www/lighttpd

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

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/${LATEST_LINK}
PORTDOCS=	COPYING_H264
.endif

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

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/COPYING_H264 ${DOCSDIR}
.endif

.include "${MASTERDIR}/Makefile"
