PORTNAME=	kcalc
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	math kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Scientific calculator for KDE
WWW=		https://utils.kde.org/projects/kcalc/

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr
BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons crash doctools \
		guiaddons i18n init notifications widgetsaddons xmlgui \
		ecm:build
USE_QT=		core dbus gui widgets xml \
		buildtools:build qmake:build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
