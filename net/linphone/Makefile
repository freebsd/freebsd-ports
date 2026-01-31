PORTNAME=	linphone
PORTVERSION=	5.3.2
PORTEPOCH=	1
CATEGORIES=	net
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	hiroo.ono+freebsd@gmail.com
COMMENT=	SIP client supporting voice/video calls and text messaging
WWW=		https://www.linphone.org/

LICENSE=	GPLv3

BUILD_DEPENDS=	patchelf:sysutils/patchelf
LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libbelcard.so:deskutils/belcard \
		liblinphone++.so:net/liblinphone \
		libmediastreamer2.so:net/mediastreamer \
		libortp.so:net/ortp \
		libqt5keychain.so:security/qtkeychain@qt5 \
		libQt5Multimedia.so:multimedia/qt5-multimedia \
		libxml2.so:textproc/libxml2 \
		liblime.so:security/lime \
		libjsoncpp.so:devel/jsoncpp \
		libbelle-sip.so:net/belle-sip \
		libbelr.so:textproc/belr

USES=		cmake compiler:c++11-lib pkgconfig qt:5 tar:bzip2 xorg sqlite:3
USE_GITLAB=	yes
USE_XORG=	x11
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public \
		public/external:ispell
GL_PROJECT=	linphone-desktop \
		ispell:ispell
GL_TAGNAME=	${PORTVERSION} \
		05574fe160222c3d0b6283c1433c9b087271fad1:ispell
USE_QT=		concurrent core dbus declarative gui linguisttools network \
		quickcontrols2 speech svg testlib widgets buildtools:build \
		qmake:build graphicaleffects:run quickcontrols:run

# Linphone's plugin API is implemented in a shared object with rather generic
# SONAME and filename, libapp-plugin.so. For classic installation in the
# local tree, we better move it to its own subdirectory, so we need RPATH
# here.
# This will affect actual Linphone plugins as well if they get ported.
CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH="${LOCALBASE}/lib/linphone" \
		-DCMAKE_INSTALL_RPATH_USE_LINK_PATH=NO \
		-DLINPHONEAPP_INSTALL_PREFIX=${PREFIX} \
		-DLINPHONEAPP_VERSION="${PORTVERSION}" \
		-DGIT_EXECUTABLE=NO
CMAKE_ON=	ENABLE_VIDEO \
		ENABLE_BUILD_VERBOSE \
		ENABLE_QT_KEYCHAIN
CMAKE_OFF=	ENABLE_BUILD_APP_PLUGINS

ICONDIR=	${LOCALBASE}/share/icons/hicolor

post-extract:
	${TAR} -x -C ${WRKSRC}/external/ispell \
		-f ${DISTDIR}/${DISTFILE_ispell} \
		--strip-components 1

# override install because otherwise, it does a complete rebuild during stage
do-install:
	# Patchelf
	patchelf --set-rpath "${LOCALBASE}/lib:${LOCALBASE}/lib/linphone" \
		${BUILD_WRKSRC}/linphone-app/linphone
	# Linphone
	${MKDIR} ${STAGEDIR}${LOCALBASE}/lib/linphone \
		${STAGEDIR}${LOCALBASE}/include/LinphoneApp \
		${STAGEDIR}${DATADIR} \
		${STAGEDIR}${ETCDIR} \
		${STAGEDIR}${ICONDIR}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/linphone-app/linphone \
		${STAGEDIR}${LOCALBASE}/bin
	${INSTALL_LIB} ${BUILD_WRKSRC}/linphone-app/libapp-plugin.so \
		${STAGEDIR}${LOCALBASE}/lib/linphone
	${INSTALL_DATA} ${BUILD_WRKSRC}/linphone-app/qt.conf \
		${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/linphone-app/include/LinphoneApp/* \
		${STAGEDIR}${LOCALBASE}/include/LinphoneApp
	${INSTALL_DATA} ${BUILD_WRKSRC}/linphone-app/linphone.desktop \
		${STAGEDIR}${LOCALBASE}/share/applications/linphone.desktop
	${MKDIR} ${STAGEDIR}${ICONDIR}/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/linphone-app/assets/images/linphone_logo.svg \
		${STAGEDIR}${ICONDIR}/scalable/apps/linphone.svg
	for idir in 16x16 22x22 24x24 32x32 64x64 128x128 256x256; do \
		${MKDIR} ${STAGEDIR}${ICONDIR}/$${idir}/apps; \
		${INSTALL_DATA} ${WRKSRC}/linphone-app/assets/icons/hicolor/$${idir}/apps/icon.png \
			${STAGEDIR}${ICONDIR}/$${idir}/apps/linphone.png; \
	done
	${MKDIR} ${STAGEDIR}${DATADIR}/assistant
	${INSTALL_DATA} ${WRKSRC}/linphone-app/assets/assistant/* \
		${STAGEDIR}${DATADIR}/assistant
	${INSTALL_DATA} ${WRKSRC}/linphone-app/assets/linphonerc-factory \
		${STAGEDIR}${DATADIR}
	# ISpell
	${INSTALL_LIB} ${BUILD_WRKSRC}/external/ispell/libISpell.so \
		${STAGEDIR}${LOCALBASE}/lib
	${MKDIR} ${STAGEDIR}${DATADIR}/ispell_dictionaries
	${INSTALL_DATA} ${WRKSRC}/external/ispell/ispell_dictionaries/* \
		${STAGEDIR}${DATADIR}/ispell_dictionaries

.include <bsd.port.mk>
