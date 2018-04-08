# $FreeBSD$

PORTNAME=	parley
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	misc kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Vocabulary trainer for KDE

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml

USES=		cmake:outsource gettext kde:5 tar:xz
USE_GNOME=	libxml2 libxslt
USE_KDE=	attica auth codecs completion configwidgets coreaddons config \
		crash doctools ecm i18n jobwidgets kcmutils kio newstuff \
		notifications kross khtml service sonnet textwidgets \
		widgetsaddons xmlgui \
		libkeduvocdocument
USE_QT5=	concurrent core dbus gui location network multimedia qml quick \
		script svg webchannel webengine widgets xml \
		buildtools_build qmake_build
USE_XORG=	x11 xrender

.include <bsd.port.mk>
