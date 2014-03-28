# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/www/gtkhtml3/Makefile,v 1.184 2012/08/17 19:06:47 kwm Exp $

PORTNAME=	gtkhtml3
PORTVERSION=	3.32.1
PORTREVISION=	2
CATEGORIES=	www gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/3$//}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	${PORTNAME:S/3$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Lightweight HTML rendering/printing/editing engine

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme
LIB_DEPENDS=	soup-2.4:${PORTSDIR}/devel/libsoup \
		enchant:${PORTSDIR}/textproc/enchant
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme

USES=		gettext pkgconfig gmake tar:bzip2
USE_XORG=	xinerama xi xrandr xcursor xcomposite xdamage
USE_GNOME=	gnomeprefix gnomehack intlhack gconf2 ltverhack
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="3.14"

NO_STAGE=	yes
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
	@${REINPLACE_CMD} -e 's|G_CONST_RETURN||g' \
		${WRKSRC}/a11y/*.[ch]

.include <bsd.port.mk>
