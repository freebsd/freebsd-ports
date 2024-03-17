PORTNAME=	actiona
DISTVERSIONPREFIX=	v
DISTVERSION=	3.10.1
PORTREVISION=	7
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform automation tool
WWW=		https://wiki.actiona.tools/doku.php

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/property_tree/ini_parser.hpp:devel/boost-libs
LIB_DEPENDS=	libnotify.so:devel/libnotify \
		libopencv_core.so:graphics/opencv

USES=		compiler:c++11-lang desktop-file-utils gl pkgconfig qmake \
		gnome qt:5 shared-mime-info xorg
USE_GITHUB=	yes
GH_ACCOUNT=	Jmgr
USE_QT=		concurrent core dbus gui multimedia network script scripttools speech sql widgets x11extras xml xmlpatterns \
		buildtools:build uitools:build
USE_GNOME=	gdkpixbuf2 glib20
USE_GL=		gl
USE_XORG=	x11 xtst

QMAKE_ARGS=	PKGCONFIG_OPENCV=opencv4

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USE=	QT=linguisttools:build

pre-build-NLS-on: # this is a hackish way to turn NLS on/off, asked the upstream to have the NLS option
	@cd ${WRKSRC} && ${MAKE_CMD} locale_release

post-stage-NLS-off:
	@${RM} -r ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
