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

USES+=		cmake gnome localbase:ldflags pkgconfig
USE_GNOME+=	atk gdkpixbuf2 glib20 gtk30 pango
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

# disable appindicator as it is a feature of gnome 3 which isn't supported on FreeBSD
CMAKE_ARGS+=    -DWITH_APPINDICATOR=OFF
# set build directory
CMAKE_ARGS+=    --build=build

.include <bsd.port.pre.mk>

PLIST=		${.CURDIR}/pkg-plist

post-patch:
# Do not build remmina core program
	${REINPLACE_CMD} -e '/add_subdirectory(src)/d' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e '/add_subdirectory(data)/d' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e '/add_subdirectory(po)/d' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e '/find_suggested_package(AVAHI)/d' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e '/target_link_libraries(remmina/d' ${WRKSRC}/plugins/CMakeLists.txt

# Which plugins to build
.if ${PKGNAMESUFFIX:S,-,,} != "exec"
	${REINPLACE_CMD} -e '/add_subdirectory(exec)/d' ${WRKSRC}/plugins/CMakeLists.txt
.endif
.if ${PKGNAMESUFFIX:S,-,,} != "kwallet"
	${REINPLACE_CMD} -e '/add_definitions(-DWITH_KF5WALLET)/d' ${WRKSRC}/plugins/CMakeLists.txt
	${REINPLACE_CMD} -e '/add_subdirectory(kwallet)/d' ${WRKSRC}/plugins/CMakeLists.txt
.endif
.if ${PKGNAMESUFFIX:S,-,,} != "nx"
	${REINPLACE_CMD} -e '/find_suggested_package(LIBSSH)/d' ${WRKSRC}/plugins/CMakeLists.txt
	${REINPLACE_CMD} -e '/find_required_package(XKBFILE)/d' ${WRKSRC}/plugins/CMakeLists.txt
	${REINPLACE_CMD} -e '/add_subdirectory(nx)/d' ${WRKSRC}/plugins/CMakeLists.txt
.endif
.if ${PKGNAMESUFFIX:S,-,,} != "rdp"
	${REINPLACE_CMD} -e '/find_suggested_package(FREERDP)/d' ${WRKSRC}/plugins/CMakeLists.txt
	${REINPLACE_CMD} -e '/add_subdirectory(rdp)/d' ${WRKSRC}/plugins/CMakeLists.txt
.endif
.if ${PKGNAMESUFFIX:S,-,,} != "secret"
	${REINPLACE_CMD} -e '/add_subdirectory(plugins\/secret)/d' ${WRKSRC}/CMakeLists.txt
.endif
.if ${PKGNAMESUFFIX:S,-,,} != "spice"
	${REINPLACE_CMD} -e '/find_suggested_package(SPICE)/d' ${WRKSRC}/plugins/CMakeLists.txt
	${REINPLACE_CMD} -e '/add_subdirectory(spice)/d' ${WRKSRC}/plugins/CMakeLists.txt
.endif
.if ${PKGNAMESUFFIX:S,-,,} != "st"
	${REINPLACE_CMD} -e '/add_subdirectory(st)/d' ${WRKSRC}/plugins/CMakeLists.txt
.endif
.if ${PKGNAMESUFFIX:S,-,,} != "telepathy"
	${REINPLACE_CMD} -e '/find_suggested_package(TELEPATHY)/d' ${WRKSRC}/plugins/CMakeLists.txt
	${REINPLACE_CMD} -e '/add_subdirectory(telepathy)/d' ${WRKSRC}/plugins/CMakeLists.txt
.endif
.if ${PKGNAMESUFFIX:S,-,,} != "vnc"
	${REINPLACE_CMD} -e '/find_suggested_package(GCRYPT)/d' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e' /find_suggested_package(LIBVNCSERVER)/d' ${WRKSRC}/plugins/CMakeLists.txt
	${REINPLACE_CMD} -e '/add_subdirectory(vnc)/d' ${WRKSRC}/plugins/CMakeLists.txt
.endif
.if ${PKGNAMESUFFIX:S,-,,} != "www"
	${REINPLACE_CMD} -e '/add_subdirectory(www)/d' ${WRKSRC}/plugins/CMakeLists.txt
.endif
.if ${PKGNAMESUFFIX:S,-,,} != "xdmcp"
	${REINPLACE_CMD} -e '/add_subdirectory(xdmcp)/d' ${WRKSRC}/plugins/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
.endif
