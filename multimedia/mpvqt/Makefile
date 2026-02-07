PORTNAME=	mpvqt
DISTVERSION=	1.1.1
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	MpvQt is a libmpv wrapper for QtQuick2 and QML
WWW=		https://invent.kde.org/libraries/mpvqt

LICENSE=		LGPL21 LGPL3
LICENSE_COMB=		dual
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSES/LGPL-2.1-only.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/LICENSES/LGPL-3.0-only.txt

LIB_DEPENDS=	libmpv.so:multimedia/mpv

USES=		cmake gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	ecm:build
USE_QT=		base declarative

PLIST_SUB=	SHLIB_VER=2 \
		SHLIB_VERSION=${DISTVERSION}

.include <bsd.port.mk>
