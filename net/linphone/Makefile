PORTNAME=	linphone
DISTVERSION=	6.1.2
PORTEPOCH=	1
CATEGORIES=	net
# XXX: Linphone GitLab instance seems unstable
#      and sometimes refuses connections.
MASTER_SITES=	LOCAL/0mp

MAINTAINER=	hiroo.ono+freebsd@gmail.com
COMMENT=	Qt 6 desktop SIP client for voice, video, and messaging
WWW=		https://www.linphone.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	xdg-screensaver:devel/xdg-utils

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libbelcard.so:deskutils/belcard \
		libbelle-sip.so:net/belle-sip \
		libbelr.so:textproc/belr \
		libbzrtp.so:security/bzrtp \
		libjsoncpp.so:devel/jsoncpp \
		liblime.so:security/lime \
		liblinphone++.so:net/liblinphone \
		libmediastreamer2.so:net/mediastreamer \
		libortp.so:net/ortp

USES=		cmake compiler:c++17-lang desktop-file-utils gl gnome pkgconfig qt:6 sqlite:3 tar:bzip2 xorg
USE_GL=		gl
USE_GNOME=	libxml2
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
GL_PROJECT=	linphone-desktop
GL_TAGNAME=	${DISTVERSION}
USE_QT=		base declarative networkauth shadertools:build svg tools:build
USE_XORG=	x11

SUB_FILES=	linphone.desktop

CMAKE_ARGS+=	-DLINPHONE_QT_ONLY=ON \
		-DLINPHONE_OUTPUT_DIR=${LOCALBASE} \
		-DLINPHONEAPP_INSTALL_PREFIX=${PREFIX} \
		-DLINPHONEAPP_VERSION=${DISTVERSION} \
		-DMEDIASTREAMER2_PLUGINS_LOCATION=${LOCALBASE}/lib/mediastreamer/plugins \
		-DCMAKE_PREFIX_PATH=${LOCALBASE} \
		-DCMAKE_SKIP_INSTALL_RPATH=ON \
		-DCMAKE_BUILD_WITH_INSTALL_RPATH=OFF \
		-DENABLE_VIDEO=ON \
		-DENABLE_QT_GL=ON \
		-DENABLE_QT_KEYCHAIN=OFF \
		-DENABLE_BUILD_APP_PLUGINS=OFF \
		-DENABLE_CRASH_HANDLER=OFF \
		-DENABLE_APP_PACKAGING=OFF \
		-DENABLE_APP_PDF_VIEWER=OFF \
		-DENABLE_APP_WEBVIEW=OFF \
		-DENABLE_APP_PACKAGE_ROOTCA=OFF \
		-DENABLE_UPDATE_CHECK=OFF \
		-DENABLE_STRICT=OFF \
		-DENABLE_RELATIVE_PREFIX=OFF \
		-DENABLE_SCREENSHARING=OFF \
		-DENABLE_OPENH264=OFF \
		-DGIT_EXECUTABLE=NO

ICON_SIZES=	16x16 22x22 24x24 32x32 64x64 128x128 256x256

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/linphone.desktop \
		${STAGEDIR}${PREFIX}/share/applications/linphone.desktop
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/Linphone/data/image/logo.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/linphone.svg
.for size in ${ICON_SIZES}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}/apps
	${INSTALL_DATA} ${WRKSRC}/Linphone/data/icon/hicolor/${size}/apps/icon.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}/apps/linphone.png
.endfor
	# A Qt5 DT_NEEDED entry is an unconditional build failure for this port.
	@if /usr/bin/readelf -d ${STAGEDIR}${PREFIX}/bin/linphone | \
		${GREP} -Eq 'NEEDED.*libQt5'; then \
		${ECHO_MSG} 'ERROR: linphone is directly linked against Qt5'; \
		exit 1; \
	fi
	@${ECHO_MSG} '===> Qt linkage for staged linphone'
	@/usr/bin/ldd ${STAGEDIR}${PREFIX}/bin/linphone
	@if /usr/bin/ldd ${STAGEDIR}${PREFIX}/bin/linphone | \
		${GREP} -Eq 'libQt5|/qt5/'; then \
		${ECHO_MSG} 'ERROR: linphone has a direct or transitive Qt5 dependency'; \
		exit 1; \
	fi
	@if ! /usr/bin/ldd ${STAGEDIR}${PREFIX}/bin/linphone | \
		${GREP} -Eq 'libQt6(Core|Gui|Quick|Qml|OpenGL|Widgets)'; then \
		${ECHO_MSG} 'ERROR: linphone Qt6 linkage was not detected'; \
		exit 1; \
	fi
	@${ECHO_MSG} '===> Qt linkage for system MSQOGL'
	@/usr/bin/ldd ${LOCALBASE}/lib/mediastreamer/plugins/libmsqogl.so
	@if /usr/bin/ldd ${LOCALBASE}/lib/mediastreamer/plugins/libmsqogl.so | \
		${GREP} -Eq 'libQt5|/qt5/'; then \
		${ECHO_MSG} 'ERROR: system libmsqogl.so is linked against Qt5'; \
		exit 1; \
	fi
	@if ! /usr/bin/ldd ${LOCALBASE}/lib/mediastreamer/plugins/libmsqogl.so | \
		${GREP} -Eq 'libQt6(Core|Gui|Quick|Qml|OpenGL|Widgets)'; then \
		${ECHO_MSG} 'ERROR: system libmsqogl.so Qt6 linkage was not detected'; \
		exit 1; \
	fi
	# The package must not contain private copies of the system SDK or Qt.
	@if ${FIND} ${STAGEDIR}${PREFIX} -type f \( \
		-name 'libQt5*.so*' -o -name 'libQt6*.so*' -o \
		-name 'liblinphone*.so*' -o -name 'libmediastreamer*.so*' \) | \
		${GREP} -q .; then \
		${ECHO_MSG} 'ERROR: staged tree contains bundled Qt/Liblinphone/Mediastreamer libraries'; \
		exit 1; \
	fi

.include <bsd.port.mk>
