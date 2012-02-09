# New ports collection makefile for:	fcitx-keyboard
# Date created:				6 Feb 2012
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fcitx-keyboard
PORTVERSION=	0.1.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	X Keyboard Integration wtih Fcitx

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	fcitx-config.4:${PORTSDIR}/chinese/fcitx \
		enchant.1:${PORTSDIR}/textproc/enchant \
		icuuc.48:${PORTSDIR}/devel/icu

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_CMAKE=	yes
USE_GNOME=	intltool libxml2
USE_XORG=	x11 xkbfile

PROJECTHOST=	fcitx

.include <bsd.port.mk>
