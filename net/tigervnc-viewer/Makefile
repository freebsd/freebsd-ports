PKGNAMESUFFIX=	-viewer
CATEGORIES=	net

COMMENT=	TigerVNC Viewer
WWW=		https://tigervnc.org/

USES+=		gnome iconv jpeg magick:7,build xorg
USE_XORG+=	ice pixman sm x11 xcursor xext xfixes xft xi xinerama xrender xrandr

LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig \
		libfltk.so:x11-toolkits/fltk \
		libnettle.so:security/nettle \
	 	libgmp.so:math/gmp \
		libavcodec.so:multimedia/ffmpeg

OPTIONS_DEFINE=	DOCS GNUTLS NLS
OPTIONS_DEFAULT=	GNUTLS
OPTIONS_SUB=	yes
NLS_CMAKE_BOOL=	ENABLE_NLS
NLS_USES=	gettext
GNUTLS_CMAKE_BOOL=	ENABLE_GNUTLS
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls

DESKTOP_ENTRIES=	"TigerVNC viewer" "Connect to VNC server and display remote desktop" \
				"${PORTNAME}" "vncviewer" "Network;" false
DESCR=		${.CURDIR}/pkg-descr

post-patch:
	# do not build server components and tests
	@${REINPLACE_CMD} \
		-e 's|add_subdirectory(unix)||' \
		-e 's|add_subdirectory(tests)||' \
		${WRKSRC}/CMakeLists.txt

MASTERDIR=	${.CURDIR}/../tigervnc-server
.include "${MASTERDIR}/Makefile.common.mk"
