# New ports collection makefile for:	xmps-opendivx-plugin
# Date created:		03 Feb 20001
# Whom:			Mario S F Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmps-opendivx-plugin
PORTVERSION=	0.0.1
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	xmps plugin using OpenDivX decoding engine from Project Mayo

LIB_DEPENDS=	divxdecore.0:${PORTSDIR}/multimedia/libdivxdecore \
		xmps.0:${PORTSDIR}/multimedia/xmps

DEPRECATED=	mastersite disappeared, Project Mayo is now part of DivX.com
EXPIRATION_DATE=	2006-05-28

WRKSRC=		${WRKDIR}/${PORTNAME}-0.0.2
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
PLIST_FILES=	lib/xmps/codecs/video/libopendivx.a \
		lib/xmps/codecs/video/libopendivx.la \
		lib/xmps/codecs/video/libopendivx.so \
		lib/xmps/codecs/video/libopendivx.so.${LIB_VERSION}

LIB_VERSION=	0

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

post-install:
	@${LN} -sf libopendivx.so ${PREFIX}/lib/xmps/codecs/video/libopendivx.so.${LIB_VERSION}

.include <bsd.port.mk>
