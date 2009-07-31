# New ports collection makefile for:	licq-osd
# Date created:				2003-07-15
# Whom:					nm@web.am
#
# $FreeBSD$
#
#

PORTNAME=	osd
PORTVERSION=	${OSD_LICQ_VER}
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	net-im

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	OnScreenDisplay messages in licq

LIB_DEPENDS=	xosd.4:${PORTSDIR}/misc/xosd \
		boost_regex.4:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/lib/licq/licq_qt-gui.so:${PORTSDIR}/net-im/licq-qt-gui
# run dependency may be too strict, delete it if you use another
# plugin (gtk+) and wish run osd with it. i've not tested with
# plugins other than qt-gui

GNU_CONFIGURE=	yes

LICQ_PORT?=	net-im/licq

LOCALES=	be de cs es fr pt pt_BR ro ru sv sk
PLIST_FILES=	lib/licq/licq_osd.la \
		lib/licq/licq_osd.so \
		${LOCALES:C+^.*$+share/locale/&/LC_MESSAGES/licq_osd_plugin.mo+}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/${LICQ_PORT}/Makefile.inc"
.include <bsd.port.post.mk>
