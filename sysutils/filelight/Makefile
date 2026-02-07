PORTNAME=	filelight
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Map of concentric segmented-rings representing file system
WWW=		https://utils.kde.org/projects/filelight/

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:6 \
		qt:6 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons i18n \
		jobwidgets kio kirigami-addons package parts service solid \
		sonnet textwidgets widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build \
		kirigami2:run kquickcharts:run qqc2-desktop-style:run
USE_QT=		base
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
