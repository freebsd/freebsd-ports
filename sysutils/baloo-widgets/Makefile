# $FreeBSD$

PORTNAME=	baloo-widgets
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	BalooWidgets library

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	baloo completion config coreaddons ecm emoticons filemetadata \
		i18n init itemmodels jobwidgets kdelibs4support kio service \
		widgetsaddons
USE_QT=		concurrent core dbus gui network testlib widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

# Override shared library version
KDE_APPLICATIONS_SHLIB_VER=20.4.2

.include <bsd.port.mk>
