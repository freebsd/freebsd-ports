# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-devel-docs
PORTVERSION=	3.18.1
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Documents targeted for GNOME developers

BUILD_DEPENDS=	itstool:textproc/itstool

PORTSCOUT=	limitw:1,even

USES=		gettext-tools gmake gnome pkgconfig shebangfix tar:xz
SHEBANG_LANG=	gjs
gjs_OLD_CMD=	/usr/bin/gjs
gjs_CMD=	${LOCALBASE}/bin/gjs
SHEBANG_FILES=	platform-demos/C/guitar-tuner/guitar-tuner.js \
		platform-demos/C/guitar-tuner/guitar-tuner.py \
		platform-demos/C/image-viewer/image-viewer.py \
		platform-demos/C/samples/hello-in-js/hello-world \
		platform-demos/C/samples/*.js
GNU_CONFIGURE=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
