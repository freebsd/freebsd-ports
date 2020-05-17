# $FreeBSD$

PORTNAME=	qtcurve
DISTVERSION=	1.9.0-rc1
PORTREVISION?=	6
CATEGORIES=	x11-themes

MAINTAINER=	jhale@FreeBSD.org
COMMENT?=	Widget styles for Qt and GTK+ toolkits

.if !defined(QTCURVE_SLAVE)
USES=		metaport
# There is no NO_PATCH
PATCHDIR=	${MASTERDIR}/none

OPTIONS_RADIO=		QT5
OPTIONS_RADIO_QT5=	KF5 QT5
OPTIONS_DEFINE=		GTK2
OPTIONS_DEFAULT=	GTK2 QT5

GTK2_RUN_DEPENDS=	gtk2-qtcurve-theme>=${PORTVERSION}:x11-themes/qtcurve-gtk2
KF5_DESC=		KDE Frameworks 5 + Qt 5 toolkit support
KF5_RUN_DEPENDS=	kf5-style-qtcurve>=${PORTVERSION}:x11-themes/qtcurve-kf5
QT5_RUN_DEPENDS=	qt5-style-qtcurve>=${PORTVERSION}:x11-themes/qtcurve-qt5

.else # !defined(QTCURVE_SLAVE)
PATCH_SITES=	https://github.com/KDE/${PORTNAME}/commit/
PATCHFILES=	ee2228ea2f18ac5da9b434ee6089381df815aa94.patch:-p1

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	KDE
GH_TAGNAME=	a1ec5f8

USES=		compiler:c++11-lib cmake:insource pkgconfig xorg
USE_XORG=	x11 xcb

.for i in gtk2 kf5 qt5
WITH_${i}=	Off
.endfor
WITH_${QTCURVE_SLAVE}=	On

CMAKE_ARGS+=	-DENABLE_GTK2=${WITH_gtk2} \
		-DENABLE_QT4=Off \
		-DENABLE_QT5=${WITH_qt5} \
		-DQTC_QT4_ENABLE_KDE=Off \
		-DQTC_QT5_ENABLE_KDE=${WITH_kf5}
LDFLAGS+=	-L${LOCALBASE}/lib

BUILD_WRKSRC=	${WRKSRC}/${QTCURVE_SLAVE}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

PLIST=		${PKGDIR}/pkg-plist.${QTCURVE_SLAVE}

.if ${QTCURVE_SLAVE} == "utils"
PKGNAMESUFFIX=	-utils
USE_LDCONFIG=	yes
BUILD_WRKSRC=	${WRKSRC}
.else
LIB_DEPENDS+=	libqtcurve-utils.so:x11-themes/qtcurve-utils
.endif

.if ${QTCURVE_SLAVE} == "gtk2"
PKGNAMEPREFIX=	gtk2-
PKGNAMESUFFIX=	-theme
USES+=		gnome
USE_GNOME=	cairo gdkpixbuf2 gtk20 pango
USE_LDCONFIG=	yes

post-install:
	@(cd ${WRKSRC}/lib/cairo && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endif

.if ${QTCURVE_SLAVE} == "kf5"
CONFLICTS_INSTALL=	qt5-style-qtcurve
WITH_qt5=	On # required for KF5
PKGNAMEPREFIX=	kf5-style-
USES+=		kde:5 qt:5
USE_KDE=	archive completion config configwidgets coreaddons \
		ecm_build frameworkintegration guiaddons i18n iconthemes \
		init kdelibs4support kio widgetsaddons windowsystem xmlgui
USE_QT=		core dbus gui printsupport svg widgets x11extras \
		buildtools_build qmake_build
BUILD_WRKSRC=	${WRKSRC}/qt5
.endif

.if ${QTCURVE_SLAVE} == "qt5"
CONFLICTS_INSTALL=	kf5-style-qtcurve
PKGNAMEPREFIX=	qt5-style-
USES+=		qt:5
USE_QT=		core dbus gui svg widgets x11extras \
		buildtools_build qmake_build
PLIST_FILES=	${QT_PLUGINDIR_REL}/styles/qtcurve.so
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|bash|sh|' -e 's|\[\[|[|g' -e 's|\]\]|]|g' \
		${WRKSRC}/tools/gen-version.sh

.endif # !defined(QTCURVE_SLAVE)

.include <bsd.port.mk>
