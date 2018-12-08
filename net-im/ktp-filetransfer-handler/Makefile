# $FreeBSD$

PORTNAME=	ktp-filetransfer-handler
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net-im kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE instant messaging file transfer handler

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtelepathy-qt5.so:net-im/telepathy-qt@qt5 \
		libKTpCommonInternals.so:net-im/ktp-common-internals

USES=		compiler:c++11-lang cmake:outsource gettext kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons ecm i18n itemviews jobwidgets kio service solid \
		wallet widgetsaddons xmlgui
USE_QT=		core dbus gui network xml widgets \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
