# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	pcmanfm
PORTVERSION=	1.2.5
CATEGORIES=	x11-fm
MASTER_SITES=	SF/${PORTNAME}/PCManFM%20%2B%20Libfm%20%28tarball%20release%29/PCManFM/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PCMan File Manager

LICENSE=	GPLv2

LIB_DEPENDS=	libfm-gtk.so:x11/libfm \
	libfontconfig.so:x11-fonts/fontconfig \
	libfreetype.so:print/freetype2

USES=		desktop-file-utils gettext gmake libtool localbase pkgconfig \
		tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk20 cairo pango gdkpixbuf2 intltool intlhack
USE_XORG=	x11

CONFIGURE_ARGS=--with-gtk=2

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_CONFIGURE_ENABLE=	nls
NLS_USES_OFF=	gettext-tools

post-extract:
	${MV} ${WRKSRC}/data/pcmanfm.conf \
		${WRKSRC}/data/pcmanfm.conf.sample

post-patch:
	${REINPLACE_CMD} -e 's|pcmanfm.conf|pcmanfm.conf.sample|' \
		${WRKSRC}/data/Makefile.in

.include <bsd.port.mk>
