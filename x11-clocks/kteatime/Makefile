PORTNAME=	kteatime
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	x11-clocks kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Handy timer for steeping tea
WWW=		https://www.kde.org/

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons crash doctools \
		i18n iconthemes notifications notifyconfig sonnet textwidgets \
		widgetsaddons xmlgui \
		ecm:build
USE_QT=		base

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
