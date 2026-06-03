PORTNAME=	ktouch
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	misc education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Touch typing tutor for KDE
WWW=		https://www.kde.org/applications/education/ktouch

RUN_DEPENDS=	kqtquickcharts>=${KDE_APPLICATIONS_VERSION}:graphics/kqtquickcharts

USES=		cmake gettext gnome kde:6 qt:6 tar:xz xorg
USE_GNOME=	libxml2
USE_KDE=	completion config configwidgets coreaddons \
		doctools i18n itemviews kcmutils textwidgets \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base declarative
USE_XORG=	x11 xcb xext xkbfile

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
