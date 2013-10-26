# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdeartwork
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-themes kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Artworks Themes

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen2.pc:${PORTSDIR}/math/eigen2

CONFLICTS_INSTALL=	kdeaccessibility-4.[0-6].* \
			kdebase-workspace-4.5.[0-5] \
			kde-wallpapers-4.[79].*

LATEST_LINK=	${PORTNAME}4

USE_XZ=		yes
USE_KDE4=	kdehier kdelibs kdeprefix libkexiv2 workspace automoc4
USES=		cmake:outsource
USE_QT4=	corelib gui opengl \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	x11 xt

OPTIONS_DEFINE=	GNOME
GNOME_DESC=	Use Gnome screensavers

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOME}
BUILD_DEPENDS+=	${LOCALBASE}/share/applications/xscreensaver-properties.desktop:${PORTSDIR}/x11/xscreensaver-gnome
RUN_DEPENDS+=	${LOCALBASE}/share/applications/xscreensaver-properties.desktop:${PORTSDIR}/x11/xscreensaver-gnome
.else
BUILD_DEPENDS+=	xscreensaver:${PORTSDIR}/x11/xscreensaver
RUN_DEPENDS+=	xscreensaver:${PORTSDIR}/x11/xscreensaver
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local/|${LOCALBASE}|g' \
			-e 's|/usr/share|${LOCALBASE}/share|g' \
		${PATCH_WRKSRC}/cmake/modules/FindXscreensaver.cmake
.for item in kscreensaver/kdesavers/banner.cpp
	${REINPLACE_CMD} -e 's|<qlabel.h>|<QLabel>|'\
			 -e 's|<qlineedit.h>|<QLineEdit>|'\
			 -e 's|<qcombobox.h>|<QComboBox>|'\
			 -e 's|<qcheckbox.h>|<QCheckBox>|'\
			 -e 's|<qslider.h>|<QSlider>|'\
			 -e 's|<qlayout.h>|<QLayout>|'\
			 -e 's|<qdatetime.h>|<QDateEdit>|'\
			 -e 's|<qfontdatabase.h>|<QFontDatabase>|'\
			 -e 's|<qpainter.h>|<QPainter>|'\
			 -e 's|<qfontcombobox.h>|<QFontComboBox>|' \
	    ${PATCH_WRKSRC}/${item}
.endfor
.for item in kscreensaver/kdesavers/banner.h kscreensaver/kdesavers/blob.h\
	     kscreensaver/kdesavers/Euphoria.cpp
	${REINPLACE_CMD} -e 's|<qtimer.h>|<QTimer>|'\
	    ${PATCH_WRKSRC}/${item}
.endfor
.for item in kscreensaver/kdesavers/blob.cpp
	${REINPLACE_CMD} -e 's|<qcolor.h>|<QColor>|'\
			 -e 's|<qlabel.h>|<QLabel>|'\
			 -e 's|<qlayout.h>|<QLayout>|'\
			 -e 's|<qpainter.h>|<QPainter>|'\
			 -e 's|<qpixmap.h>|<QPixmap>|'\
			 -e 's|<qimage.h>|<QImage>|' \
	    ${PATCH_WRKSRC}/${item}
.endfor

.include <bsd.port.mk>
