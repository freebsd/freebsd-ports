# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/www/gtkhtml3/Makefile,v 1.184 2012/08/17 19:06:47 kwm Exp $

PORTNAME=	gtkhtml3
PORTVERSION=	3.32.1
PORTREVISION=	5
CATEGORIES=	www gnome
MASTER_SITES=	GNOME/sources/${PORTNAME:S/3$//}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	${PORTNAME:S/3$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Lightweight HTML rendering/printing/editing engine

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:misc/gnome-icon-theme
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libenchant.so:textproc/enchant
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:misc/gnome-icon-theme

PORTSCOUT=	ignore:1

USES=		gettext gnome libtool pathfix pkgconfig gmake tar:bzip2 xorg
USE_XORG=	xinerama xi xrandr xcursor xcomposite xdamage
USE_GNOME=	gnomeprefix intlhack gconf2 gtk20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION="3.14"

post-patch:
	@${REINPLACE_CMD} -e 's|@INTLTOOL_LIBDIR@|${LOCALBASE}/libdata|' \
		${WRKSRC}/intltool-merge.in
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g ; \
		s|-DGTK_DISABLE_DEPRECATED||g ; \
		s|-DG_DISABLE_DEPRECATED||g ; \
		s|-DGDK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|gtkhtml-editor-test[$$]|gtkhtml3-editor-test$$|' \
		${WRKSRC}/components/editor/Makefile.in
	@${REINPLACE_CMD} '/g_thread_init/d' ${WRKSRC}/components/editor/main.c
	@${REINPLACE_CMD} -e 's|G_CONST_RETURN||g' \
		${WRKSRC}/a11y/*.[ch]

.include <bsd.port.mk>
