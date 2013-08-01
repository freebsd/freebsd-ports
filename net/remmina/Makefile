# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	remmina
PORTVERSION=	1.0.0
CATEGORIES=	net gnome

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	The GTK+ Remote Desktop Client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/${PORTNAME}/COPYING

USES=		cmake desktop-file-utils
USE_GMAKE=	yes
USE_GNOME=	atk gdkpixbuf2 glib20 gtk20 pango
INSTALLS_ICONS=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -Wl,-rpath -Wl,${LOCALBASE}/lib -lX11 \
		-lgio-2.0 -lgobject-2.0 -lgthread-2.0 -lgmodule-2.0
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
CFLAGS+=	-I${WRKSRC}/remmina/include -I${LOCALBASE}/include ${PTHREAD_CFLAGS} -fPIC
SUB_FILES=	pkg-message
USE_GITHUB=	yes
GH_ACCOUNT=	FreeRDP
GH_PROJECT=	${PORTNAME}
GH_COMMIT=	356c033
GH_TAGNAME=	${PORTVERSION}
WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-Remmina-${GH_COMMIT}

OPTIONS_DEFINE=	SSH GCRYPT TERM AVAHI UNIQUE NLS
OPTIONS_DEFAULT=	SSH GCRYPT TERM AVAHI UNIQUE NLS
SSH_DESC=	Build with SSH tunneling support
GCRYPT_DESC=	Build with libgcrypt support for password encryption
TERM_DESC=	Build with terminal support
AVAHI_DESC=	Build with Avahi support
UNIQUE_DESC=	Build with Unique-App support

.include <bsd.port.options.mk>

CMAKE_ARGS+=	--build=build
# now cannot build with gtk30 because requisite ports are old
CMAKE_ARGS+=	-DGTK_VERSION=2

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MSSH}
BUILD_DEPENDS+=	${LOCALBASE}/include/libssh/libssh.h:${PORTSDIR}/security/libssh
RUN_DEPENDS+=	${LOCALBASE}/lib/libssh.so.4:${PORTSDIR}/security/libssh
.if ${OSVERSION} >= 800040
LDFLAGS+=	-fstack-protector
.endif
.else
CMAKE_ARGS+=	-DWITH_LIBSSH=OFF
.endif

.if ${PORT_OPTIONS:MGCRYPT}
LIB_DEPENDS+=	gcrypt:${PORTSDIR}/security/libgcrypt
.else
CMAKE_ARGS+=	-DWITH_GCRYPT=OFF
.endif

.if ${PORT_OPTIONS:MTERM}
USE_GNOME+=	vte
.else
CMAKE_ARGS+=	-DWITH_VTE=OFF
.endif

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	avahi-ui:${PORTSDIR}/net/avahi-gtk
.else
CMAKE_ARGS+=	-DWITH_AVAHI=OFF
.endif

.if ${PORT_OPTIONS:MUNIQUE}
LIB_DEPENDS+=	unique:${PORTSDIR}/x11-toolkits/unique
.else
CMAKE_ARGS+=	-DWITH_UNIQUE=OFF
.endif

post-patch:
	@# fit avahi to current PORTVERSION
	${REINPLACE_CMD} -e's|avahi-ui>=0.6.30|avahi-ui>=0.6.29|' ${WRKSRC}/cmake/FindAVAHI.cmake
	${REINPLACE_CMD} -e's|avahi-client>=0.6.30|avahi-client>=0.6.29|' ${WRKSRC}/cmake/FindAVAHI.cmake
	@# do not build plugins and locales , they are provided by separated ports
	${REINPLACE_CMD} -e's|add_subdirectory(remmina-plugins)||' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e's|add_subdirectory(remmina-plugins-gnome)||' ${WRKSRC}/CMakeLists.txt
.if !${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e's|add_subdirectory(po)||' ${WRKSRC}/remmina/CMakeLists.txt
.endif

post-install:
	@# localized desktop entry file is not included remmina 1.0.0, install manually
	${MKDIR} ${PREFIX}/share/applications/
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop ${PREFIX}/share/applications/
	${CP} -a ${DATADIR}/icons/ ${PREFIX}/share/icons
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
