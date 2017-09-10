# $FreeBSD$

PORTNAME=	qtcurve
PORTVERSION=	1.8.18
PORTREVISION=	3
CATEGORIES=	x11-themes

MAINTAINER=	jhale@FreeBSD.org
COMMENT?=	Widget styles for Qt and GTK+ toolkits

.if !defined(QTCURVE_SLAVE)
USES=		metaport
# There is no NO_PATCH
PATCHDIR=	${MASTERDIR}/none

OPTIONS_DEFINE=	GTK2 KDE4 QT4 QT5
OPTIONS_DEFAULT:=	${OPTIONS_DEFINE}

GTK2_RUN_DEPENDS=	gtk2-qtcurve-theme>=1.8.18:x11-themes/qtcurve-gtk2
KDE4_RUN_DEPENDS=	kde4-style-qtcurve>=1.8.18:x11-themes/qtcurve-kde4
QT4_RUN_DEPENDS=	qt4-style-qtcurve>=1.8.18:x11-themes/qtcurve-qt4
QT5_RUN_DEPENDS=	qt5-style-qtcurve>=1.8.18:x11-themes/qtcurve-qt5

.else # !defined(QTCURVE_SLAVE)
LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	QtCurve

USES=		compiler:c++11-lib cmake execinfo pkgconfig
USE_XORG=	x11 xcb

.for i in gtk2 kde4 qt4 qt5
WITH_${i}=	Off
.endfor
WITH_${QTCURVE_SLAVE}=	On

CMAKE_ARGS+=	-DENABLE_GTK2=${WITH_gtk2} \
		-DENABLE_QT4=${WITH_qt4} \
		-DENABLE_QT5=${WITH_qt5} \
		-DQTC_QT4_ENABLE_KDE=${WITH_kde4}
LDFLAGS+=	-L${LOCALBASE}/lib

BUILD_WRKSRC=	${WRKSRC}/${QTCURVE_SLAVE}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

PLIST=		${PKGDIR}/pkg-plist.${QTCURVE_SLAVE}

.if ${QTCURVE_SLAVE} == "utils"
PKGNAMESUFFIX=	-utils
USE_LDCONFIG=	yes
BUILD_WRKSRC=	${WRKSRC}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext-tools:build
NLS_CMAKE_OFF=	-DQTC_INSTALL_PO=Off
.else
LIB_DEPENDS+=	libqtcurve-utils.so:x11-themes/qtcurve-utils
.endif

.if ${QTCURVE_SLAVE} == "gtk2"
PKGNAMEPREFIX=	gtk2-
PKGNAMESUFFIX=	-theme
USE_GNOME=	gtk20 cairo pango
USE_LDCONFIG=	yes

post-install:
	@(cd ${WRKSRC}/lib/cairo && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endif

.if ${QTCURVE_SLAVE} == "kde4"
WITH_qt4=	On # required for KDE 4
PKGNAMEPREFIX=	kde4-style-
USE_KDE=	kdelibs workspace automoc4
USES+=		kde:4
USE_QT4=	moc_build qmake_build rcc_build uic_build
BUILD_WRKSRC=	${WRKSRC}/qt4
.endif

.if ${QTCURVE_SLAVE} == "qt4"
PKGNAMEPREFIX=	qt4-style-
USE_QT4=	dbus gui svg moc_build qmake_build rcc_build uic_build
PLIST_FILES=	${QT_PLUGINDIR_REL}/styles/qtcurve.so
.endif

.if ${QTCURVE_SLAVE} == "qt5"
PKGNAMEPREFIX=	qt5-style-
USE_QT5=	dbus gui svg widgets x11extras buildtools_build qmake_build
PLIST_FILES=	${QT_PLUGINDIR_REL}/styles/qtcurve.so
.endif

.endif # !defined(QTCURVE_SLAVE)

.include <bsd.port.mk>
