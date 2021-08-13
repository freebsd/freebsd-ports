PORTNAME=	filelight
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Map of concentric segmented-rings representing file system

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml


USES=		cmake compiler:c++11-lang desktop-file-utils gettext \
		kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		i18n jobwidgets kio parts service solid sonnet textwidgets \
		widgetsaddons windowsystem xmlgui \
		doctools_build ecm_build
USE_QT=		concurrent core dbus gui network script svg widgets xml \
		buildtools_build qmake_build testlib_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
