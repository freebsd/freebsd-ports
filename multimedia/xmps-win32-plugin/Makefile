# New ports collection makefile for:	xmps-win32-plugin
# Date created:		03 Feb 20001
# Whom:			Mario S F Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmps-win32-plugin
PORTVERSION=	0.0.4
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://xmps.sourceforge.net/sources/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	xmps plugin for Win32 (TM) Codecs

LIB_DEPENDS=	xmps.0:${PORTSDIR}/multimedia/xmps \
		intl.5:${PORTSDIR}/devel/gettext-old
RUN_DEPENDS=	${CODEC_DETECTION_FILE}:${CODEC_PORT}

USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
PLIST_SUB=	LIB_VERSION="${LIB_VERSION}"

#CODEC_PORT=	${PORTSDIR}/multimedia/win32-codecs
CODEC_PORT=	${.CURDIR}/../win32-codecs
CODEC_DETECTION_FILE!=	${MAKE} -f ${CODEC_PORT}/Makefile -V CODEC_DETECTION_FILE
LIB_VERSION=	0

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/lib/win32|${LOCALBASE}/lib/win32|" \
		${WRKSRC}/src/win32_codec.c
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' ${WRKSRC}/src/*

post-install:
	@${LN} -sf libwin32.so ${PREFIX}/lib/xmps/codecs/video/libwin32.so.${LIB_VERSION}

.include <bsd.port.mk>
