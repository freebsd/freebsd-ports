PORTNAME=	qt5-style-plugins
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0.0-23
DISTVERSIONSUFFIX=	-g335dbe
PORTREVISION=	14
CATEGORIES=	x11-themes
DIST_SUBDIR=	KDE/Qt/addons

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Additional Styles for Qt 5
WWW=		https://qt-project.org

LICENSE=	LGPL21

USES=		gl pkgconfig qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	qt
GH_PROJECT=	qtstyleplugins
USE_QT=		core gui widgets buildtools:build
USE_GL=		gl

post-patch:
	${REINPLACE_CMD} '/SUBDIRS.*gtk2/d' \
		${WRKSRC}/src/plugins/platformthemes/platformthemes.pro \
		${WRKSRC}/src/plugins/styles/styles.pro

.include <bsd.port.mk>
