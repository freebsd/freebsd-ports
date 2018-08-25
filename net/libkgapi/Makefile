# $FreeBSD$

PORTNAME=	libkgapi
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE based library to access google services

LICENSE=	LGPL21

LIB_DEPENDS=	libical.so:devel/libical \
		libsasl2.so:security/cyrus-sasl2

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash ecm emoticons guiaddons i18n iconthemes init \
		itemmodels itemviews jobwidgets kdelibs4support kio \
		notifications parts service textwidgets unitconversion \
		widgetsaddons windowsystem xmlgui solid sonnet wallet
# pim components
USE_KDE+=	calendarcore contacts
USE_QT=		core dbus gui location qml network printsupport quick webchannel \
		webengine widgets xml \
		buildtools_build qmake_build

USE_LDCONFIG=	yes


.include <bsd.port.mk>
