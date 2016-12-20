# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lxterminal
PORTVERSION=	0.3.0
CATEGORIES=	sysutils
MASTER_SITES=	SF/lxde/LXTerminal%20%28terminal%20emulator%29/LXTerminal%20${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight terminal emulator from the LXDE project

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
	libfreetype.so:print/freetype2

USES=		gmake localbase pkgconfig tar:xz
USE_GNOME=	gtk20 glib20 cairo vte intltool
USE_XORG=	x11 xext
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INSTALLS_ICONS=	YES

CONFIGURE_ARGS=	--enable-gtk3=no

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_USES_OFF=	gettext-tools

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|src po|src|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
