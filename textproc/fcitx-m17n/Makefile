# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-m17n
PORTVERSION=	0.1.3
CATEGORIES=	textproc
MASTER_SITES=	GOOGLE_CODE
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	The libm17n support for Fcitx

LIB_DEPENDS=	fcitx-config:${PORTSDIR}/chinese/fcitx \
		m17n:${PORTSDIR}/devel/m17n-lib

USE_XZ=		yes
USE_GETTEXT=	yes
USE_CMAKE=	yes
USE_GNOME=	intltool

PROJECTHOST=	fcitx

.include <bsd.port.mk>
