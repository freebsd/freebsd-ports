# Created by: Rusty Nejdl <rnejdl@ringofsaturn.com>
# $FreeBSD$

PORTNAME=	filelight
PORTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
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

# Override KDE_APPLICATIONS_VERSION -- 16.12.3 which is the current one in kde.mk
# does not yet ship the localization as part of their distfiles. As we did not import
# kde-l10n 16.12.3, the localization of this port would be broken otherwise.
KDE_APPLICATIONS_VERSION=	17.04.3

.include <bsd.port.mk>
