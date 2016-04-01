# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	remmina
PORTVERSION=	1.0.0
PORTREVISION=	5
CATEGORIES=	net gnome

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ Remote Desktop Client

LICENSE=	GPLv2

USES=		cmake gmake pkgconfig
USE_GNOME=	atk gdkpixbuf2 glib20 gtk20 pango
INSTALLS_ICONS=	yes
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib  -Wl,-rpath -Wl,${LOCALBASE}/lib \
		-lX11 -lgio-2.0 -lgobject-2.0 -lgthread-2.0 -lgmodule-2.0 \
		-lgtk-x11-2.0
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${WRKSRC}/remmina/include -I${LOCALBASE}/include -fPIC
SUB_FILES=	pkg-message
USE_GITHUB=	yes
GH_ACCOUNT=	FreeRDP
GH_PROJECT=	Remmina

OPTIONS_DEFINE=	SSH GCRYPT TERM AVAHI NLS
OPTIONS_DEFAULT=	SSH GCRYPT TERM AVAHI NLS
SSH_DESC=	Build with SSH tunneling support
GCRYPT_DESC=	Build with libgcrypt support for password encryption
TERM_DESC=	Build with terminal support
AVAHI_DESC=	Build with Avahi support

.include <bsd.port.options.mk>

CMAKE_ARGS+=	--build=build
# now cannot build with gtk30 because requisite ports are old
CMAKE_ARGS+=	-DGTK_VERSION=2

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
LDFLAGS+=	-lintl
.else
USES+=		gettext	# doesn't build otherwise
LDFLAGS+=	-lintl	# doesn't build otherwise
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MSSH}
LIB_DEPENDS+=	libssh_threads.so:security/libssh
LDFLAGS+=	-fstack-protector
.else
CMAKE_ARGS+=	-DWITH_LIBSSH=OFF
.endif

.if ${PORT_OPTIONS:MGCRYPT}
LIB_DEPENDS+=	libgcrypt.so:security/libgcrypt
.else
CMAKE_ARGS+=	-DWITH_GCRYPT=OFF
.endif

.if ${PORT_OPTIONS:MTERM}
USE_GNOME+=	vte
.else
CMAKE_ARGS+=	-DWITH_VTE=OFF
.endif

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	libavahi-ui.so:net/avahi-gtk
.else
CMAKE_ARGS+=	-DWITH_AVAHI=OFF
.endif

post-patch:
	# fix pkgconfig
	${REINPLACE_CMD} -e 's,$${CMAKE_INSTALL_LIBDIR}/pkgconfig,libdata/pkgconfig,' ${WRKSRC}/remmina/CMakeLists.txt
	# do not build plugins and locales , they are provided by separated ports
	${REINPLACE_CMD} -e's|add_subdirectory(remmina-plugins)||' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e's|add_subdirectory(remmina-plugins-gnome)||' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e's|add_subdirectory(external_tools)||' ${WRKSRC}/remmina/CMakeLists.txt
.if !${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e's|add_subdirectory(po)||' ${WRKSRC}/remmina/CMakeLists.txt
.endif

.include <bsd.port.mk>
