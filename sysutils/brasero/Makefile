# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/sysutils/brasero/Makefile,v 1.83 2010/11/15 21:53:38 kwm Exp $

PORTNAME=	brasero
PORTVERSION=	2.32.1
PORTREVISION=	8
CATEGORIES=	sysutils audio multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD/DVD mastering tool for the GNOME desktop

LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique \
		libtotem-plparser.so:${PORTSDIR}/multimedia/totem-pl-parser \
		libcanberra-gtk.so:${PORTSDIR}/audio/libcanberra
RUN_DEPENDS=	growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		cdrdao:${PORTSDIR}/sysutils/cdrdao \
		yelp:${PORTSDIR}/x11/yelp

CONFLICTS=	brasero-3.[0-9]*

GNU_CONFIGURE=	yes
USE_XORG=	ice sm
USES=		pathfix gettext shared-mime-info gmake pkgconfig tar:bzip2 \
		libtool desktop-file-utils
USE_GNOME=	intlhack gnomeprefix gnomedocutils
USE_LDCONFIG=	yes
USE_GSTREAMER=	gconf core
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-inotify --with-html-dir=${PREFIX}/share/doc \
		--enable-gtk3=no --enable-introspection=yes
CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_CAM_LIB_H=1
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.brasero.gschema.xml

OPTIONS_DEFINE=	NAUTILUS LIBBURNIA
OPTIONS_DEFAULT=NAUTILUS
NAUTILUS_DESC=	Nautilus extension
LIBBURNIA_DESC=	libburnia plug-ins

PLIST_SUB=	FULL_VERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNAUTILUS}
USE_GNOME+=	nautilus2
CONFIGURE_ARGS+=--enable-nautilus
PLIST_SUB+=	NAUTILUS=""
.else
PLIST_SUB+=	NAUTILUS="@comment "
CONFIGURE_ARGS+=--enable-nautilus=no
.endif

.if ${PORT_OPTIONS:MLIBBURNIA}
LIB_DEPENDS+=	libburn.so:${PORTSDIR}/devel/libburn \
		libisofs.so:${PORTSDIR}/devel/libisofs
CONFIGURE_ARGS+=--enable-libburnia
PLIST_SUB+=	LIBBURNIA=""
.else
PLIST_SUB+=	LIBBURNIA="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    	${WRKSRC}/libbrasero-burn/burn-process.c
	@${REINPLACE_CMD} -e 's|" == "|" = "|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/proc/self/fd/0|/dev/fd/0|g' ${WRKSRC}/po/*.po
	@${REINPLACE_CMD} -e '/BRASERO_SM_LIBS =/s/$$/ -lICE/' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
