# Created by: Alexander Logvinov <ports@logvinov.com>

PORTNAME=	remmina
DISTVERSION=	1.4.17
CATEGORIES=	net gnome

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	GTK+ Remote Desktop Client

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libpcre2-8.so:devel/pcre2 \
		libsodium.so:security/libsodium \
		libsoup-2.4.so:devel/libsoup \
		libwayland-client.so:graphics/wayland

FLAVORS=		default lite
lite_PKGNAMESUFFIX=	-lite
lite_DESCR=		${.CURDIR}/pkg-descr-lite

USES=		cmake compiler:c11 desktop-file-utils gettext gnome localbase:ldflags pathfix \
		pkgconfig shared-mime-info ssl shebangfix xorg

USE_GITLAB=	yes
GL_ACCOUNT=	Remmina
GL_PROJECT=	Remmina
GL_COMMIT=	0ef1621b3e16b3168213147a2bfca39da2c2668f

USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 pango
INSTALLS_ICONS=	yes

USE_XORG=	ice sm x11 xext xkbfile

SHEBANG_FILES=	data/desktop/remmina-file-wrapper.in
bash_CMD=	${SH}

CMAKE_ARGS=	-DWITH_APPINDICATOR:BOOL=false

CONFLICTS_INSTALL=	remmina-plugin*

OPTIONS_DEFINE=		AVAHI CUPS GCRYPT NLS SSH TERM
OPTIONS_DEFAULT=	AVAHI CUPS GCRYPT NLS SSH TERM \
			EXEC NX RDP SECRET SPICE ST VNC WWW XDMCP
OPTIONS_GROUP=		PLUGINS
OPTIONS_GROUP_PLUGINS=	EXEC KWALLET NX RDP SECRET SPICE ST VNC WWW XDMCP
OPTIONS_SUB=		yes

.if ${FLAVOR:U} == lite
OPTIONS_EXCLUDE=	AVAHI CUPS KWALLET NX SECRET SPICE SSH TERM WWW XDMCP
COMMENT+=		(lite flavor)
.endif

AVAHI_DESC=		Build with Avahi support
EXEC_DESC=		Plugin to execute a command
GCRYPT_DESC=		Build with libgcrypt support for password encryption
NX_DESC=		NX protocol plugin
RDP_DESC=		Remote Desktop Protocol plugin
SECRET_DESC=		GNOME Keyring plugin
SPICE_DESC=		Spice protocol plugin
SSH_DESC=		Build with SSH tunneling support
ST_DESC=		(Simple) Terminal Plugin
TERM_DESC=		Build with terminal support
VNC_DESC=		VNC protocol plugin
WWW_DESC=		Plugin to open an authenticated web browser
XDMCP_DESC=		XDMCP protocol plugin

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app \
			libavahi-ui-gtk3.so:net/avahi-gtk3
AVAHI_CMAKE_BOOL=	WITH_AVAHI

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_CMAKE_BOOL=	WITH_CUPS

GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
GCRYPT_CMAKE_BOOL=	WITH_GCRYPT

KWALLET_USES=		kde:5 qt:5
KWALLET_USE=		kde=wallet qt=buildtools_build,core,gui,qmake_build
KWALLET_CMAKE_BOOL=	WITH_KF5WALLET

NLS_CMAKE_BOOL=		WITH_TRANSLATIONS

NX_IMPLIES=		SSH

RDP_LIB_DEPENDS=	libfreerdp2.so:net/freerdp

SECRET_LIB_DEPENDS=	libsecret-1.so:security/libsecret
SECRET_RUN_DEPENDS=	gnome-keyring:security/gnome-keyring

SPICE_BUILD_DEPENDS=	spice-protocol>=0.12.15:devel/spice-protocol
SPICE_LIB_DEPENDS=	libspice-client-gtk-3.0.so:deskutils/spice-gtk
SPICE_CMAKE_BOOL=	WITH_SPICE

SSH_LIB_DEPENDS=	libssh.so:security/libssh
SSH_CMAKE_BOOL=		WITH_LIBSSH
SSH_LDFLAGS=		-fstack-protector

ST_IMPLIES=		EXEC

TERM_USE=		gnome=vte3
TERM_CMAKE_BOOL=	WITH_VTE

VNC_LIB_DEPENDS=	libgnutls.so:security/gnutls \
			libvncserver.so:net/libvncserver
VNC_USES=		jpeg
VNC_CMAKE_BOOL=		WITH_LIBVNCSERVER

WWW_LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
			libsoup-2.4.so:devel/libsoup \
			libwebkit2gtk-4.0.so:www/webkit2-gtk3
			
			

XDMCP_RUN_DEPENDS=	Xephyr:x11-servers/xephyr

post-patch:
	${REINPLACE_CMD} -e 's,FreeBSD,FreeBSD|DragonFly,' \
		${WRKSRC}/CMakeLists.txt

post-patch-EXEC-off:
	${REINPLACE_CMD} -e '/add_subdirectory(exec)/d' ${WRKSRC}/plugins/CMakeLists.txt

post-patch-GCRYPT-off:
	${REINPLACE_CMD} -e '/find_suggested_package(GCRYPT)/d' ${WRKSRC}/CMakeLists.txt

post-patch-KWALLET-off:
	${REINPLACE_CMD} -e '/add_definitions(-DWITH_KF5WALLET)/d' ${WRKSRC}/plugins/CMakeLists.txt
	${REINPLACE_CMD} -e '/add_subdirectory(kwallet)/d' ${WRKSRC}/plugins/CMakeLists.txt

post-patch-NX-off:
	${REINPLACE_CMD} -e '/find_required_package(XKBFILE)/d' ${WRKSRC}/plugins/CMakeLists.txt
	${REINPLACE_CMD} -e '/add_subdirectory(nx)/d' ${WRKSRC}/plugins/CMakeLists.txt

post-patch-RDP-off:
	${REINPLACE_CMD} -e '/find_suggested_package(FREERDP)/d' ${WRKSRC}/plugins/CMakeLists.txt
	${REINPLACE_CMD} -e '/add_subdirectory(rdp)/d' ${WRKSRC}/plugins/CMakeLists.txt

post-patch-SECRET-off:
	${REINPLACE_CMD} -e '/add_subdirectory(plugins\/secret)/d' ${WRKSRC}/CMakeLists.txt

post-patch-SPICE-off:
	${REINPLACE_CMD} -e '/find_suggested_package(SPICE)/d' ${WRKSRC}/plugins/CMakeLists.txt
	${REINPLACE_CMD} -e '/add_subdirectory(spice)/d' ${WRKSRC}/plugins/CMakeLists.txt

post-patch-SSH-off:
	${REINPLACE_CMD} -e '/find_suggested_package(LIBSSH)/d' ${WRKSRC}/plugins/CMakeLists.txt

post-patch-ST-off:
	${REINPLACE_CMD} -e '/add_subdirectory(st)/d' ${WRKSRC}/plugins/CMakeLists.txt

post-patch-VNC-off:
	${REINPLACE_CMD} -e' /find_suggested_package(LIBVNCSERVER)/d' ${WRKSRC}/plugins/CMakeLists.txt
	${REINPLACE_CMD} -e '/add_subdirectory(vnc)/d' ${WRKSRC}/plugins/CMakeLists.txt

post-patch-WWW-off:
	${REINPLACE_CMD} -e '/add_subdirectory(www)/d' ${WRKSRC}/plugins/CMakeLists.txt

post-patch-XDMCP-off:
	${REINPLACE_CMD} -e '/add_subdirectory(xdmcp)/d' ${WRKSRC}/plugins/CMakeLists.txt

.include <bsd.port.mk>
