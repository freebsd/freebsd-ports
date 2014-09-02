# Created by: ade, archie
# $FreeBSD$
#   $MCom: ports/x11-fm/nautilus/Makefile,v 1.212 2012/09/03 16:28:29 mezz Exp $

PORTNAME=	nautilus
PORTVERSION=	2.32.2.1
PORTREVISION=	7
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	File manager for the GNOME desktop

LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique \
		libexempi.so:${PORTSDIR}/textproc/exempi

CONFLICTS=	nautilus-3.[0-9]*

INSTALLS_ICONS=	yes
USES=		desktop-file-utils gettext gmake libtool:keepla pathfix \
		pkgconfig shared-mime-info tar:bzip2
USE_GNOME=	gnomeprefix intlhack gnomedesktop \
		librsvg2 gvfs introspection:build
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBPNG="-L${LOCALBASE}/lib -lpng -lz" \
		EXTRA_CORE_MODULES="gmodule-2.0"
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS=	--enable-static --disable-packagekit --disable-update-mimedb
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

GCONF_SCHEMAS=	apps_nautilus_preferences.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|G_CONST_RETURN|const|g' \
		${WRKSRC}/eel/eel-*.[ch] \
		${WRKSRC}/libnautilus-private/*.[ch] \
		${WRKSRC}/src/nautilus-zoom-control.c
	@${REINPLACE_CMD} -e 's|-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure ${WRKSRC}/eel/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/nautilus/extensions-2.0

.include <bsd.port.mk>
