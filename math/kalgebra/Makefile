PORTNAME=	kalgebra
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	math education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE graph calculator
WWW=		https://www.kde.org/applications/education/kalgebra

LIB_DEPENDS=	libAnalitza.so:math/analitza
BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml

USES=		cmake compiler:c++11-lang desktop-file-utils gettext gl kde:6 \
		qt:6 readline tar:xz
USE_GL=		glu
USE_KDE=	auth codecs config configwidgets coreaddons doctools i18n kio \
		plasma-workspace service widgetsaddons xmlgui \
		ecm:build
USE_QT=		base
CMAKE_ARGS=	-DBUILD_mobile:BOOL=FALSE

OPTIONS_DEFINE=	DOCS WEBENGINE
OPTIONS_DEFAULT_amd64=	WEBENGINE
OPTIONS_DEFAULT_i386=	WEBENGINE
OPTIONS_SUB=	yes

WEBENGINE_DESC=	Add dependency on qt6-webengine
WEBENGINE_USE=	QT=webengine
WEBENGINE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt6WebEngineWidgets

.include <bsd.port.mk>
