# $FreeBSD$

PKGNAMESUFFIX=	-viewer
CATEGORIES=	net

COMMENT=	TigerVNC Viewer

USES+=		gnome iconv jpeg xorg
USE_XORG+=	ice sm x11 xcursor xext xfixes xft xinerama xrender

BUILD_DEPENDS+=	convert:graphics/ImageMagick7 # to generate icons during build
LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png \
		libfltk.so:x11-toolkits/fltk

OPTIONS_DEFINE=	DOCS GNUTLS NLS
OPTIONS_DEFAULT=	GNUTLS
OPTIONS_SUB=	yes
NLS_CMAKE_BOOL=	ENABLE_NLS
NLS_USES=	gettext
GNUTLS_CMAKE_BOOL=	ENABLE_GNUTLS
GNUTLS_LIB_DEPENDS=	libtasn1.so:security/libtasn1 \
			libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error \
			libgnutls.so:security/gnutls

INSTALLS_ICONS=	yes
DESKTOP_ENTRIES=	"TigerVNC viewer" "Connect to VNC server and display remote desktop" \
				"${PORTNAME}" "vncviewer" "Network;" false

post-patch:
	# do not build server components and tests
	@${REINPLACE_CMD} \
		-e 's|add_subdirectory(unix)||' \
		-e 's|add_subdirectory(tests)||' \
		${WRKSRC}/CMakeLists.txt

MASTERDIR=	${.CURDIR}/../tigervnc-server
.include "${MASTERDIR}/Makefile.common.mk"
