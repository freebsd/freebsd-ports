# $FreeBSD$

PORTNAME=	filelight
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Map of concentric segmented-rings representing file system

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml

CONFLICTS_INSTALL=      ${PORTNAME}-kde4*

USES=		cmake:outsource compiler:c++11-lang desktop-file-utils gettext \
		kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons doctools \
		ecm i18n jobwidgets kio parts service solid sonnet textwidgets \
		widgetsaddons xmlgui
USE_QT=		core dbus gui network script widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
