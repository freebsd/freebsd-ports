# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-m17n
PORTVERSION=	0.2.3
CATEGORIES=	textproc
MASTER_SITES=	http://download.fcitx-im.org/${PORTNAME}/
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	Multilingualization support for Fcitx

LICENSE=	LGPL21

LIB_DEPENDS=	libfcitx-config.so:chinese/fcitx \
		libm17n.so:devel/m17n-lib

USES=		cmake gettext pkgconfig tar:xz

.include <bsd.port.mk>
