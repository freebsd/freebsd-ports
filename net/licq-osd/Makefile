# New ports collection makefile for:	licq-osd
# Date created:				2003-07-15
# Whom:					nm@web.am
#
# $FreeBSD$
#
#

PORTNAME=	licq_osd_plugin
PORTVERSION=	1.2.7.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=/sourceforge/licq-osd
DISTNAME=	licq_osd_plugin-${PORTVERSION}

MAINTAINER=	nm@web.am
COMMENT=	OnScreenDisplay messages in licq (like in SIM and more)

BUILD_DEPENDS=${X11BASE}/lib/libxosd.so.4:${PORTSDIR}/misc/xosd
RUN_DEPENDS=${LOCALBASE}/lib/licq/licq_qt-gui.so:${PORTSDIR}/net/licq-qt-gui
# run dependency may be too strict, delete it if you use another
# plugin (gtk+) and wish run osd with it. i've not tested with
# plugins other than qt-gui

GNU_CONFIGURE=yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" LIBS="-liconv"
USE_LIBTOOL=yes

.include <bsd.port.mk>
