# New ports collection makefile for:	xmps-win32-plugin
# Date created:		03 Feb 20001
# Whom:			Mario S F Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmps-win32-plugin
PORTVERSION=	0.0.4
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	http://ftp.vin.bg.ac.yu/linux/mmedia/xmps/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	xmps plugin for Win32 (TM) Codecs

LIB_DEPENDS=	xmps.0:${PORTSDIR}/multimedia/xmps
RUN_DEPENDS=	${CODEC_DETECTION_FILE}:${CODEC_PORT}

USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes

#CODEC_PORT=	${PORTSDIR}/multimedia/win32-codecs
CODEC_PORT=	${.CURDIR}/../win32-codecs
CODEC_DETECTION_FILE!=	${MAKE} -f ${CODEC_PORT}/Makefile -V CODEC_DETECTION_FILE
LIB_VERSION=	0
PLIST_FILES=	lib/xmps/codecs/video/libwin32.a \
		lib/xmps/codecs/video/libwin32.la \
		lib/xmps/codecs/video/libwin32.so \
		lib/xmps/codecs/video/libwin32.so.${LIB_VERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|/usr/lib/win32|${LOCALBASE}/lib/win32|" \
		${WRKSRC}/src/win32_codec.c
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' ${WRKSRC}/src/*

post-install:
	@${LN} -sf libwin32.so ${PREFIX}/lib/xmps/codecs/video/libwin32.so.${LIB_VERSION}

.include <bsd.port.mk>
