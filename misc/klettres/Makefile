PORTNAME=	klettres
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	misc education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Alphabet learning tool for KDE
WWW=		https://edu.kde.org/klettres

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	attica auth codecs completion config configwidgets coreaddons \
		crash emoticons i18n init itemmodels \
		kdelibs4support newstuff phonon service widgetsaddons xmlgui \
		doctools:build ecm:build
USE_QT=		core dbus gui network svg widgets xml \
		buildtools:build qmake:build testlib:build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
