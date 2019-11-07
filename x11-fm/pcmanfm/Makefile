# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	pcmanfm
PORTVERSION=	1.3.1
CATEGORIES=	x11-fm
MASTER_SITES=	SF/${PORTNAME}/PCManFM%20%2B%20Libfm%20%28tarball%20release%29/PCManFM/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	PCMan File Manager

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

FLAVORS=	gtk2 gtk3
FLAVOR?=	${FLAVORS:[1]}

gtk3_PKGNAMESUFFIX=	-gtk3

gtk2_LIB_DEPENDS=	libfm-gtk.so:x11/libfm@gtk2
gtk3_LIB_DEPENDS=	libfm-gtk3.so:x11/libfm@gtk3

gtk2_CONFLICTS_INSTALL=	pcmanfm-gtk3
gtk3_CONFLICTS_INSTALL=	pcmanfm

USES=		desktop-file-utils gmake gnome gettext libtool localbase \
		pkgconfig tar:xz xorg
USE_GNOME=	cairo gdkpixbuf2 intltool
USE_XORG=	x11
GNU_CONFIGURE=	yes

.if ${FLAVOR:Mgtk2}
USE_GNOME+=	gtk20
CONFIGURE_ARGS=	--with-gtk=2
.elif ${FLAVOR:Mgtk3}
USE_GNOME+=	gtk30
CONFIGURE_ARGS=	--with-gtk=3
.endif

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-tools:build
NLS_CONFIGURE_ENABLE=	nls

post-extract:
	@${MV} ${WRKSRC}/data/pcmanfm.conf \
		${WRKSRC}/data/pcmanfm.conf.sample

post-patch:
	${REINPLACE_CMD} -e 's|pcmanfm.conf|pcmanfm.conf.sample|' \
		${WRKSRC}/data/Makefile.in

.include <bsd.port.mk>
