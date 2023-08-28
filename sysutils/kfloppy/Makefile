PORTNAME=	kfloppy
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Floppy disk formatter for KDE
WWW=		https://utils.kde.org/projects/kfloppy/

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		doctools emoticons i18n init itemmodels kdelibs4support \
		kio widgetsaddons xmlgui \
		ecm:build
USE_QT=		core dbus gui widgets xml \
		buildtools:build qmake:build

OPTIONS_DEFINE=	DOCS
KDE_APPLICATIONS_VERSION=	23.04.3
DEPRECATED=	No longer part of KDE Gear since 23.08
EXPIRATION_DATE=	2023-12-31

.include <bsd.port.mk>
