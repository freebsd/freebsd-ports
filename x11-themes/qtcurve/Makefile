PORTNAME=	qtcurve
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.0-298
PORTREVISION?=	0
CATEGORIES=	x11-themes
DISTNAME=	${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	jhale@FreeBSD.org
COMMENT?=	Widget styles for Qt and GTK toolkits
WWW=		https://invent.kde.org/system/qtcurve

.if !defined(QTCURVE_STYLE)
USES=		metaport
# There is no NO_PATCH
PATCHDIR=	${MASTERDIR}/none

OPTIONS_RADIO=		QT5 QT6
OPTIONS_RADIO_QT5=	KF5 QT5
OPTIONS_RADIO_QT6=	KF6 QT6
OPTIONS_DEFINE=		GTK2
OPTIONS_DEFAULT=	GTK2 QT6

GTK2_RUN_DEPENDS=	gtk2-qtcurve-theme>=${PORTVERSION}:x11-themes/qtcurve-gtk2
KF5_DESC=		KDE Frameworks 5 + Qt 5 toolkit support
KF5_RUN_DEPENDS=	kf5-style-qtcurve>=${PORTVERSION}:x11-themes/qtcurve-kf5
KF6_DESC=		KDE Frameworks 6 + Qt 6 toolkit support
KF6_RUN_DEPENDS=	kf6-style-qtcurve>=${PORTVERSION}:x11-themes/qtcurve-kf6
QT5_RUN_DEPENDS=	qt5-style-qtcurve>=${PORTVERSION}:x11-themes/qtcurve-qt5
QT6_RUN_DEPENDS=	qt6-style-qtcurve>=${PORTVERSION}:x11-themes/qtcurve-qt6

.else # !defined(QTCURVE_STYLE)
LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lib cmake:insource pkgconfig tar:xz xorg
USE_XORG=	x11 xcb

USE_GITLAB=	yes
GL_SITE=	https://invent.kde.org
GL_ACCOUNT=	system
GL_PROJECT=	qtcurve
GL_TAGNAME=	3b9869fb240a4670ce9f9bf4c84c851b3b778a4e
.for i in gtk2 kf5 kf6 qt5 qt6
WITH_${i}=	Off
.endfor
WITH_${QTCURVE_STYLE}=	On

CMAKE_ARGS+=	-DENABLE_GTK2=${WITH_gtk2} \
		-DENABLE_QT4=Off \
		-DENABLE_QT5=${WITH_qt5} \
		-DENABLE_QT6=${WITH_qt6} \
		-DQTC_QT4_ENABLE_KDE=Off \
		-DQTC_QT5_ENABLE_KDE=${WITH_kf5} \
		-DQTC_QT6_ENABLE_KDE=${WITH_kf6} \
		-DCMAKE_POLICY_VERSION_MINIMUM=3.5
LDFLAGS+=	-L${LOCALBASE}/lib

BUILD_WRKSRC=	${WRKSRC}/${QTCURVE_STYLE}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

PLIST=		${PKGDIR}/pkg-plist.${QTCURVE_STYLE}

.if ${QTCURVE_STYLE} == "utils"
PKGNAMESUFFIX=	-utils
USES+=		gettext-tools kde:6
USE_KDE+=	ecm:build i18n:build
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DQTC_ENABLE_UTILS=On # Custom
BUILD_WRKSRC=	${WRKSRC}
.else
LIB_DEPENDS+=	libqtcurve-utils.so:x11-themes/qtcurve-utils
CMAKE_ARGS+=	-DQTC_INSTALL_PO=Off
.endif

.if ${QTCURVE_STYLE} == "gtk2"
PKGNAMEPREFIX=	gtk2-
PKGNAMESUFFIX=	-theme
USES+=		gnome
USE_GNOME=	cairo gdkpixbuf gtk20 pango

post-install:
	@(cd ${WRKSRC}/lib/cairo && \
		${SETENVI} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endif

.if ${QTCURVE_STYLE} == "kf5"
DEPRECATED=	Depends on deprecated KDE Frameworks 5
EXPIRATION_DATE=	2026-12-22
CONFLICTS_INSTALL=	kf6-style-qtcurve qt5-style-qtcurve
WITH_qt5=	On # required for KF5
PKGNAMEPREFIX=	kf5-style-
USES+=		kde:5 qt:5
USE_KDE=	archive completion config configwidgets coreaddons \
		frameworkintegration guiaddons i18n iconthemes \
		init kio widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		core dbus gui printsupport svg widgets x11extras \
		buildtools:build qmake:build
BUILD_WRKSRC=	${WRKSRC}/qt5
.endif

.if ${QTCURVE_STYLE} == "qt5"
CONFLICTS_INSTALL=	kf5-style-qtcurve
PKGNAMEPREFIX=	qt5-style-
USES+=		qt:5
USE_QT=		core dbus gui svg widgets x11extras \
		buildtools:build qmake:build
PLIST_FILES=	${QT_PLUGINDIR_REL}/styles/qtcurve.so
.endif

.if ${QTCURVE_STYLE} == "kf6"
CONFLICTS_INSTALL=	kf5-style-qtcurve qt6-style-qtcurve
WITH_qt6=	On # required for KF6
PKGNAMEPREFIX=	kf6-style-
USES+=		gettext-tools kde:6 qt:6
USE_KDE=	archive colorscheme completion config configwidgets \
		coreaddons frameworkintegration guiaddons i18n \
		iconthemes kio widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		base svg
BUILD_WRKSRC=	${WRKSRC}/qt6
.endif

.if ${QTCURVE_STYLE} == "qt6"
CONFLICTS_INSTALL=	kf6-style-qtcurve
PKGNAMEPREFIX=	qt6-style-
USES+=		qt:6
USE_QT=		base svg
PLIST_FILES=	${QT_PLUGINDIR_REL}/styles/qtcurve.so
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|bash|sh|' -e 's|\[\[|[|g' -e 's|\]\]|]|g' \
		${WRKSRC}/tools/gen-version.sh

.endif # !defined(QTCURVE_STYLE)

.include <bsd.port.mk>
