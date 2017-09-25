# Created by: nm@web.am
# $FreeBSD$

PORTNAME=	osd
PORTVERSION=	1.8.2
PORTREVISION=	5
PORTEPOCH=	2
CATEGORIES=	net-im

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	OnScreenDisplay messages in licq

LIB_DEPENDS=	libxosd.so:misc/xosd \
		libboost_regex.so:devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/lib/licq/licq_qt4-gui.so:${LICQ_PORT}-qt-gui

USES=		cmake gettext-tools iconv

LOCALES=	be de cs es fr pt pt_BR ro ru sv sk tr
PLIST_FILES=	lib/licq/licq_osd.so \
		${LOCALES:C+^.*$+share/locale/&/LC_MESSAGES/licq_osd_plugin.mo+}

LICQ_PORT?=	net-im/licq

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/${LICQ_PORT}/Makefile.inc"

.include <bsd.port.post.mk>
