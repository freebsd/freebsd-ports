# New ports collection makefile for:	xmps-opendivx-plugin
# Date created:		03 Feb 20001
# Whom:			Mario S F Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmps-opendivx-plugin
PORTVERSION=	0.0.1
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	http://download.projectmayo.com/dnload/divx4linux/xmps/ \
		http://ftp.vin.bg.ac.yu/linux/mmedia/xmps/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	xmps plugin using OpenDivX decoding engine from Project Mayo

LIB_DEPENDS=	divxdecore.0:${PORTSDIR}/multimedia/libdivxdecore \
		xmps.0:${PORTSDIR}/multimedia/xmps

WRKSRC=		${WRKDIR}/${PORTNAME}-0.0.2
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=13
USE_GNOME=	gtk12
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
PLIST_FILES=	lib/xmps/codecs/video/libopendivx.so \
		lib/xmps/codecs/video/libopendivx.so.${LIB_VERSION}

LIB_VERSION=	0

post-install:
	@${LN} -sf libopendivx.so ${PREFIX}/lib/xmps/codecs/video/libopendivx.so.${LIB_VERSION}

.include <bsd.port.mk>
