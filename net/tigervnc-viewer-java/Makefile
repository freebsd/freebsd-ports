PKGNAMESUFFIX=	-viewer-java
CATEGORIES=	net java

COMMENT=	TigerVNC Viewer
WWW=		https://tigervnc.org/

USES+=		jpeg xorg
USE_XORG+=	pixman
USE_JAVA=	yes
JAVA_VERSION=	8+

NO_ARCH=	yes

CMAKE_ARGS+=	-DBUILD_JAVA:BOOL=true \
		-DBUILD_VIEWER:BOOL=false \
		-DENABLE_NLS:BOOL=false

DESKTOP_ENTRIES=	"TigerVNC viewer (Java version)" "Connect to VNC server and display remote desktop" \
				"${PORTNAME}" "vncviewer-java" "Network;" false

DESCR=		${.CURDIR}/pkg-descr
FILESDIR=	${.CURDIR}/files

JARFILES=	VncViewer.jar
PLIST_FILES=	${JARFILES:S,^,${JAVAJARDIR}/,} \
		bin/vncviewer-java
SUB_LIST=	JAVAJARDIR="${JAVAJARDIR}"
SUB_FILES=	vncviewer-java

post-patch:
	# do not build server components and tests
	@${REINPLACE_CMD} \
		-e 's|add_subdirectory(unix)||' \
		-e 's|add_subdirectory(tests)||' \
		${WRKSRC}/CMakeLists.txt

do-install:
	 ${INSTALL_DATA} ${WRKSRC}/java/VncViewer.jar ${STAGEDIR}${JAVAJARDIR}/
	 ${INSTALL_SCRIPT} ${WRKDIR}/vncviewer-java ${STAGEDIR}${PREFIX}/bin/

MASTERDIR=	${.CURDIR}/../tigervnc-server

.include "${MASTERDIR}/Makefile.common.mk"
