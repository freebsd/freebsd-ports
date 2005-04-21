# New ports collection makefile for:	licq-osd
# Date created:				2003-07-15
# Whom:					nm@web.am
#
# $FreeBSD$
#
#

PORTNAME=	osd
PORTVERSION=	${OSD_LICQ_VER}
CATEGORIES=	net

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OnScreenDisplay messages in licq

LIB_DEPENDS=	xosd.4:${PORTSDIR}/misc/xosd
RUN_DEPENDS=${LOCALBASE}/lib/licq/licq_qt-gui.so:${PORTSDIR}/net/licq-qt-gui
# run dependency may be too strict, delete it if you use another
# plugin (gtk+) and wish run osd with it. i've not tested with
# plugins other than qt-gui

USE_LIBTOOL_VER=15

LICQ_PORT?=	net/licq

LOCALES=	de cs es fr pt pt_BR ro ru se
PLIST_FILES=	lib/licq/licq_osd.so \
		${LOCALES:C+^.*$+share/locale/&/LC_MESSAGES/licq_osd_plugin.mo+}
PLIST_DIRS=	share/locale/se/LC_MESSAGES share/locale/se

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/${LICQ_PORT}/Makefile.inc"
.include <bsd.port.post.mk>
