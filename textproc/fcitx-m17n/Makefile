# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-m17n
PORTVERSION=	0.1.4
CATEGORIES=	textproc
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	fcitx
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	Multilingualization support for Fcitx

LIB_DEPENDS=	libfcitx-config.so:${PORTSDIR}/chinese/fcitx \
		libm17n.so:${PORTSDIR}/devel/m17n-lib

USE_XZ=		yes
USES=		cmake gettext pkgconfig
USE_GNOME=	intltool

.include <bsd.port.mk>
