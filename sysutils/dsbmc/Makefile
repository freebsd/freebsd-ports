# Created by: Marcel Kaiser <mk@nic-nac-project.org>
# $FreeBSD$

PORTNAME=	dsbmc
DISTVERSION=	0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://freeshell.de/~mk/download/

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	GTK+ client for DSBMD that lets you mount media, and more

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	dsbmd>=0.3:sysutils/dsbmd

USES=		desktop-file-utils gnome pkgconfig tar:tgz
USE_GNOME=	cairo gdkpixbuf2

OPTIONS_DEFINE=	GTK3 NLS
OPTIONS_DEFAULT=GTK3
OPTIONS_SUB=	yes

GTK3_MAKE_ARGS=	GTKVER=3.0
GTK3_USE=	GNOME=gtk30
GTK3_USE_OFF=	GNOME=gtk20

NLS_USES=	gettext
NLS_MAKE_ARGS_OFF=	-DWITHOUT_GETTEXT

.include <bsd.port.mk>
