# $FreeBSD$
#
# Common code for Remmina plugin ports net/remmina-plugin-*

.if defined(PKGNAMESUFFIX)

PORTNAME=	remmina-plugin
PATCHDIR=	${.CURDIR}/../remmina/files

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS+=	remmina>=${PORTVERSION}:net/remmina
RUN_DEPENDS+=	remmina>=${PORTVERSION}:net/remmina

USES+=		cmake localbase:ldflags pkgconfig
USE_GNOME+=	atk gdkpixbuf2 glib20 gtk30 pango
INSTALLS_ICONS=	yes

# disable appindicator as it is a feature of gnome 3 which isn't supported on FreeBSD
CMAKE_ARGS+=    -DWITH_APPINDICATOR=OFF
# set build directory
CMAKE_ARGS+=    --build=build

SSH_DESC=	Build with SSH tunneling support

.include <bsd.port.pre.mk>

.if ${PKGNAMESUFFIX} == "-gnome"
PLIST=		${.CURDIR}/pkg-plist
.else
PLIST_SUB+=	PLUGIN="${PKGNAMESUFFIX:S,-,,}"
PLIST=		${PKGDIR}/pkg-plist.plugin
.endif

post-patch:
# Do not build remmina core program
	${REINPLACE_CMD} -e 's|add_subdirectory(remmina)||' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|find_suggested_package(AVAHI)||' ${WRKSRC}/CMakeLists.txt
# Which plugins to build
.if ${PKGNAMESUFFIX:S,-,,} != "nx"
	${REINPLACE_CMD} -e 's|find_suggested_package(LIBSSH)||' ${WRKSRC}/remmina-plugins/CMakeLists.txt
	${REINPLACE_CMD} -e 's|find_required_package(XKBFILE)||' ${WRKSRC}/remmina-plugins/CMakeLists.txt
	${REINPLACE_CMD} -e 's|add_subdirectory(nx)||' ${WRKSRC}/remmina-plugins/CMakeLists.txt
.endif
.if ${PKGNAMESUFFIX:S,-,,} != "gnome"
	${REINPLACE_CMD} -e 's|add_subdirectory(remmina-plugins-gnome)||' ${WRKSRC}/CMakeLists.txt
.endif
.if ${PKGNAMESUFFIX:S,-,,} != "rdp"
	${REINPLACE_CMD} -e 's|find_suggested_package(FREERDP)||' ${WRKSRC}/remmina-plugins/CMakeLists.txt
	${REINPLACE_CMD} -e 's|add_subdirectory(rdp)||' ${WRKSRC}/remmina-plugins/CMakeLists.txt
.endif
.if ${PKGNAMESUFFIX:S,-,,} != "spice"
	${REINPLACE_CMD} -e 's|find_suggested_package(SPICE)||' ${WRKSRC}/remmina-plugins/CMakeLists.txt
	${REINPLACE_CMD} -e 's|add_subdirectory(spice)||' ${WRKSRC}/remmina-plugins/CMakeLists.txt
.endif
.if ${PKGNAMESUFFIX:S,-,,} != "vnc"
	${REINPLACE_CMD} -e 's|find_suggested_package(GCRYPT)||' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e' s|find_suggested_package(LIBVNCSERVER)||' ${WRKSRC}/remmina-plugins/CMakeLists.txt
	${REINPLACE_CMD} -e 's|add_subdirectory(vnc)||' ${WRKSRC}/remmina-plugins/CMakeLists.txt
.endif
.if ${PKGNAMESUFFIX:S,-,,} != "xdmcp"
	${REINPLACE_CMD} -e 's|add_subdirectory(xdmcp)||' ${WRKSRC}/remmina-plugins/CMakeLists.txt
.endif
.if ${PKGNAMESUFFIX:S,-,,} != "telepathy"
	${REINPLACE_CMD} -e 's|find_suggested_package(TELEPATHY)||' ${WRKSRC}/remmina-plugins/CMakeLists.txt
	${REINPLACE_CMD} -e 's|add_subdirectory(telepathy)||' ${WRKSRC}/remmina-plugins/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
.endif
