# $FreeBSD$

PORTNAME=	kig
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	2
CATEGORIES=	math kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE interactive geometry application

LIB_DEPENDS=	${PY_BOOST}

USES=		cmake:outsource gettext compiler:c++11-lib kde:5 \
		python:2.7,run qt:5 shebangfix tar:xz
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		crash doctools ecm emoticons i18n iconthemes init itemmodels \
		jobwidgets kdelibs4support kio parts service sonnet texteditor \
		textwidgets widgetsaddons xmlgui
USE_QT=		core dbus gui network printsupport svg widgets xml xmlpatterns \
		buildtools_build qmake_build
SHEBANG_FILES=	pykig/pykig.py

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
