# Created by: nm@web.am
# $FreeBSD$

PORTNAME=	osd
PORTVERSION=	1.9.0
PORTREVISION=	4
PORTEPOCH=	2
CATEGORIES=	net-im
PKGNAMEPREFIX=	licq-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OnScreenDisplay messages in licq

BUILD_DEPENDS=	licq:${LICQ_PORT}
LIB_DEPENDS=	libxosd.so:misc/xosd \
		libboost_regex.so:devel/boost-libs
RUN_DEPENDS=	licq:${LICQ_PORT} \
		${LOCALBASE}/lib/licq/licq_qt-gui.so:${LICQ_PORT}-qt-gui

USES=		cmake gettext-tools iconv
USE_GITHUB=	yes
GH_ACCOUNT=	licq-im
GH_PROJECT=	licq
GH_TAGNAME=	f271d55
WRKSRC_SUBDIR=	${PORTNAME}

LOCALES=	be de cs es fr pt pt_BR ro ru sv sk tr
PLIST_FILES=	lib/licq/licq_osd.so \
		${LOCALES:C+^.*$+share/locale/&/LC_MESSAGES/licq_osd_plugin.mo+}

LICQ_PORT?=	net-im/licq

.include <bsd.port.mk>
