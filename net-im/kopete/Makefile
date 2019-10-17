# $FreeBSD$

PORTNAME=	kopete
PORTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net-im kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE multi-protocol instant messenger

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
LIB_DEPENDS=    libidn.so:dns/libidn \
		libjasper.so:graphics/jasper \
		libotr.so:security/libotr \
		libqca-qt5.so:devel/qca \
		libv4l2.so:multimedia/libv4l

USES=		cmake compiler:c++11-lang desktop-file-utils jpeg kde:5 qt:5 shebangfix \
		tar:xz
USE_GNOME=	libxml2 libxslt
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons dnssd ecm emoticons guiaddons i18n \
		iconthemes itemviews jobwidgets js kcmutils kdelibs4support \
		khtml kio notifications notifyconfig parts service solid sonnet \
		texteditor textwidgets unitconversion wallet widgetsaddons \
		windowsystem xmlgui
# KDE PIM components
USE_KDE+=	contacts identitymanagement libkleo pimtextedit
USE_QT=		concurrent core dbus gui network phonon4 printsupport sql widgets xml \
		buildtools_build qmake_build

SHEBANG_FILES=	protocols/winpopup/winpopup-install \
		protocols/winpopup/winpopup-send \
		kopete/kconf_update/*.pl

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
