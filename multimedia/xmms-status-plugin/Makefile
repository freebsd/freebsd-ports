# New ports collection makefile for: xmms-status-plugin
# Date created:			Sep 28, 2003
# Whom:				Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$

PORTNAME=	xmms-status-plugin
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.hellion.org.uk/source/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	XMMS control applet for GNOME 2 panel / KDE tray

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=13
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
