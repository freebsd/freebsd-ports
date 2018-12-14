# $FreeBSD$

PORTNAME=	klettres
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	misc kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Alphabet learning tool for KDE

USES=		cmake:outsource compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	attica auth codecs completion config configwidgets coreaddons \
		crash doctools ecm emoticons i18n init itemmodels \
		kdelibs4support newstuff service widgetsaddons xmlgui
USE_QT=		core dbus gui network phonon4 svg widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
