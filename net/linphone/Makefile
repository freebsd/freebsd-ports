PORTNAME=	linphone
PORTVERSION=	4.4.8
PORTEPOCH=	1
CATEGORIES=	net

MAINTAINER=	felix@palmen-it.de
COMMENT=	SIP client supporting voice/video calls and text messaging

LICENSE=	GPLv3

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libbelcard.so:deskutils/belcard \
		liblinphone++.so:net/liblinphone \
		libmediastreamer.so:net/mediastreamer \
		libortp.so:net/ortp

USES=		cmake compiler:c++11-lib pkgconfig qt:5
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
GL_PROJECT=	linphone-desktop
GL_COMMIT=	da40aed848da44e851d67a2039e7e966c5257d3b
USE_QT=		concurrent core dbus declarative gui linguisttools network \
		quickcontrols2 speech svg testlib widgets buildtools_build \
		qmake_build graphicaleffects_run quickcontrols_run

# Linphone's plugin API is implemented in a shared object with rather generic
# SONAME and filename, libapp-plugin.so. For classic installation in the
# local tree, we better move it to its own subdirectory, so we need RPATH
# here.
# This will affect actual Linphone plugins as well if they get ported.
CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH="${LOCALBASE}/lib/linphone"

WRKSRC_SUBDIR=	linphone-app

ICONDIR=	${LOCALBASE}/share/icons/hicolor/scalable/apps

post-patch:
	@${REINPLACE_CMD} -e 's/bc_compute_full_version([^)]*)//' \
		-e 's/set(FULL_VERSION /&${PORTVERSION}/' \
		-e 's/INSTALL_RPATH_USE_LINK_PATH/BUILD_WITH_INSTALL_RPATH/' \
		-e '/add_subdirectory.*linphone_package/d' \
		-e '/add_subdirectory.*build/d' \
		-e '/add_custom_command/d' -e '/deployqt_hack/d' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} 's/LINPHONE_QT_GIT_VERSION/"${PORTVERSION}"/' \
		${WRKSRC}/src/app/AppController.cpp

# override install because otherwise, it does a complete rebuild during stage
do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/linphone \
		${STAGEDIR}${LOCALBASE}/bin
	${MKDIR} ${STAGEDIR}${LOCALBASE}/lib/linphone
	${MKDIR} ${STAGEDIR}${ICONDIR}
	${INSTALL_LIB} ${BUILD_WRKSRC}/libapp-plugin.so \
		${STAGEDIR}${LOCALBASE}/lib/linphone
	${INSTALL_DATA} ${WRKSRC}/assets/images/linphone_logo.svg \
		${STAGEDIR}${ICONDIR}/linphone.svg
	${INSTALL_DATA} ${FILESDIR}/linphone.desktop \
		${STAGEDIR}${LOCALBASE}/share/applications/linphone.desktop

.include <bsd.port.mk>
