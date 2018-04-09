# Created by: Rusty Nejdl <rnejdl@ringofsaturn.com>
# $FreeBSD$

PORTNAME=	filelight
PORTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Map of concentric segmented-rings representing file system

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml

CONFLICTS_INSTALL=      ${PORTNAME}-kde4*

USES=		cmake:outsource desktop-file-utils gettext kde:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons doctools \
		ecm i18n jobwidgets kio parts service solid sonnet textwidgets \
		widgetsaddons xmlgui
USE_QT5=	core dbus gui network script widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
